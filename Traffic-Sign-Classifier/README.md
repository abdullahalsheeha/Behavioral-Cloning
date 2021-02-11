# **Traffic Sign Recognition** 


The goals / steps of this project are the following:
* Load the data set 
* Explore, summarize and visualize the data set
* Design, train and test a model architecture
* Use the model to make predictions on new images
* Analyze the softmax probabilities of the new images


### Data Set Summary & Exploration

#### 1. Provide a basic summary of the data set. In the code, the analysis should be done using python, numpy and/or pandas methods rather than hardcoding results manually.

I used the pandas library to calculate summary statistics of the traffic
signs data set:

* The size of training set is 34799 images
* The size of the validation set is 4410 images
* The size of test set is 12630 images
* The shape of a traffic sign image is (32, 32, 3)
* The number of unique classes/labels in the data set is 43

#### 2. Include an exploratory visualization of the dataset.

10 random image from each classes:

![Unknown](https://user-images.githubusercontent.com/61292363/107635881-f067a180-6c7c-11eb-9441-62e441fbbd27.png)

### Design and Test a Model Architecture

#### 1. Preprocessing the data

As a first step, I decided to normalized the image data because i want the pixles to be in range between 0 and 1, because the scale of the data has an effect on the magnitude of the gradient for the weights.

#### 2. Final model architecture

My final model consisted of the following layers:
```python
Model: "sequential"
_________________________________________________________________
Layer (type)                 Output Shape              Param #   
=================================================================
conv2d (Conv2D)              (None, 30, 30, 20)        560       
_________________________________________________________________
max_pooling2d (MaxPooling2D) (None, 15, 15, 20)        0         
_________________________________________________________________
conv2d_1 (Conv2D)            (None, 13, 13, 50)        9050      
_________________________________________________________________
max_pooling2d_1 (MaxPooling2 (None, 6, 6, 50)          0         
_________________________________________________________________
dropout (Dropout)            (None, 6, 6, 50)          0         
_________________________________________________________________
flatten (Flatten)            (None, 1800)              0         
_________________________________________________________________
dense (Dense)                (None, 500)               900500    
_________________________________________________________________
dense_1 (Dense)              (None, 256)               128256    
_________________________________________________________________
dropout_1 (Dropout)          (None, 256)               0         
_________________________________________________________________
dense_2 (Dense)              (None, 43)                11051     
=================================================================
Total params: 1,049,417
Trainable params: 1,049,417
Non-trainable params: 0
```

#### 3. Trained model description.
Hyperparameters for training:
```python 
rate = 0.001
EPOCHS = 30
BATCH_SIZE = 128
```

To train the model, I used Adam Optimizer.

#### 4. Model Accuracy

| Set name         		|     Accuracy	        					|
|:---------------------:|:---------------------------------------------:| 
| Training         		|     0.988	        					| 
| Validation         		|     0.958	        					| 
| Test         		|     0.943	        					| 


## Results

Predict new images

![download](https://user-images.githubusercontent.com/61292363/106393930-e1762900-640a-11eb-827a-cbfaba28a73d.png)
