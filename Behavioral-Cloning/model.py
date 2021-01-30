#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2
import random
import pandas as pd
from imgaug import augmenters as iaa
from sklearn.utils import shuffle
from sklearn.model_selection import train_test_split
from keras import Sequential
from keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout, Cropping2D, Lambda
from keras.optimizers import Adam
from keras.preprocessing.image import ImageDataGenerator
import ntpath 
import os   


# In[2]:


columns = ['center', 'left', 'right', 'steering', 'throttle', 'reverse', 'speed']
data = pd.read_csv('/Users/abdullahalsheeha/Downloads/Data/driving_log.csv', names=columns)
data.head()


# In[3]:


def path_leaf(path):
    head, tail = ntpath.split(path)
    return tail

data['center'] = data['center'].apply(path_leaf)
data['left'] = data['left'].apply(path_leaf)
data['right'] = data['right'].apply(path_leaf)
data.drop(data.index[0], inplace=True)
data.head() 


# In[4]:


data.dtypes


# In[5]:


data['steering'] = pd.to_numeric(data['steering'], errors='coerce')
data['throttle'] = pd.to_numeric(data['throttle'], errors='coerce')
data['reverse'] = pd.to_numeric(data['reverse'], errors='coerce')
data['speed'] = pd.to_numeric(data['speed'], errors='coerce')


# In[6]:


data.head()


# In[7]:


def load_img_steering(datadir, df):
    img_path = []
    steering = []
    
    for i in range(len(data)):
        center, left, right = data.iloc[i][0], data.iloc[i][1], data.iloc[i][2]
        img_path.append(os.path.join(datadir, center.strip()))
        steering.append(float(data.iloc[i][3]))
    
            
    img_paths = np.asarray(img_path)
    steerings = np.asarray(steering)
    return img_paths, steerings

img_paths, steerings = load_img_steering('/Users/abdullahalsheeha/Downloads/Data/IMG', data) 
   
 


# In[8]:


x_train, x_valid, y_train, y_valid = train_test_split(img_paths, steerings, test_size=0.2, shuffle=True, random_state=6)
print('training samples: {}\n validaition samples: {}'.format(len(x_train), len(x_valid)))


# In[9]:




def augment(image, steering_angle):
    image = mpimg.imread(image)
    
    if np.random.rand() < 0.5:
        image = cv2.flip(image, 1)
        steering_angle = -steering_angle
    #if np.random.rand() < 0.5:
        #bright = np.ones(image.shape, dtype='uint8')
        #image = cv2.add(image, bright)
    #if np.random.rand() < 0.5:    
        #zoom = iaa.Affine(scale=(1, 1.3))
        #image = zoom.augment_image(image)    
    return image, steering_angle           


# In[10]:


def batch_generator(image_paths, steering_ang, batch_size, train):
    
    while True:
        batch_img = []
        batch_steering = []
    
        for i in range(batch_size):
            random_index = random.randint(0, len(image_paths) - 1)
      
            
            if train:    
                img, steering = augment(image_paths[random_index], steering_ang[random_index])
            else:
                img = mpimg.imread(image_paths[random_index])
                steering = steering_ang[random_index]
            
            img = cv2.cvtColor(img, cv2.COLOR_RGB2YUV)
            img = cv2.GaussianBlur(img, (3, 3), 0)
            img = cv2.resize(img, (320, 160))
            batch_img.append(img)
            batch_steering.append(steering)
           
           
        yield (np.asarray(batch_img), np.asarray(batch_steering)) 


# In[11]:


model = Sequential()
model.add(Lambda(lambda x: (x / 255.0) - 0.5, input_shape=(160, 320, 3)))
model.add(Cropping2D(cropping=((70,25), (0,0))))
model.add(Conv2D(24, (5, 5), strides=(2,2), activation='relu'))
model.add(Conv2D(36, (5, 5), strides=(2,2), activation='relu'))
#model.add(Dropout(0.3))
model.add(Conv2D(48, (5, 5), strides=(2,2), activation='relu'))
#model.add(Dropout(0.3))
model.add(Conv2D(64, (3, 3), activation='relu'))
#model.add(Dropout(0.3))
model.add(Conv2D(64, (3, 3), activation='relu'))
model.add(Dropout(0.5))

model.add(Flatten())

#model.add(Dropout(0.5))
model.add(Dense(100, activation = 'relu'))
model.add(Dropout(0.5))
model.add(Dense(50, activation = 'relu'))
model.add(Dropout(0.5))
model.add(Dense(10, activation = 'relu'))
#model.add(Dropout(0.5))
model.add(Dense(1))

model.compile(loss='mse', optimizer=Adam(lr=1e-4))
    


# In[12]:



print(model.summary())


# In[13]:


history = model.fit(batch_generator(x_train, y_train, 100, 1), steps_per_epoch=300, epochs=10, validation_data=batch_generator(x_valid, y_valid, 100, 0), validation_steps=200)


# In[14]:


plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.legend(['Train', 'Valid'])
plt.xlabel('epoch')
plt.ylabel('loss')


# In[15]:


model.save('model.h5')


# In[ ]:




