# Behavioral-Cloning

The goals/steps of this project are the following:

* Use the simulator to collect data of good driving behavior
* Build, a convolution neural network in Keras that predicts steering angles from images
* Train and validate the model with a training and validation set
* Test that the model successfully drives around track one without leaving the road

### Image preprocessing

Proper image preprocessing is a vital step for a good result. To reduce noise, I used 3x3 Gaussian filter, resize the image (320, 160, 3).

### Model Architecture and Training Strategy

#### 1. Solution Design Approach

The overall strategy for deriving a model architecture was to build off existing research completed by experts in the field and fine-tune the model to my data.


My first step was to use a convolution neural network model similar to the NVIDIA CNN model. I thought this model might be appropriate because it is a similar use case.

In order to gauge how well the model was working, I split my image and steering angle data into a training and validation set. I found that my first model had a low mean squared error on the training set but a high mean squared error on the validation set. This implied that the model was overfitting. 

To combat the overfitting, I modified the model to include three dropout layers with a keep_prob of 0.5.


The final step was to run the simulator to see how well the car was driving around track one. There were a few spots where the vehicle fell off the track. to improve the driving behavior in these cases, I captured recovery data from both the left and right sides of the track.

At the end of the process, the vehicle is able to drive autonomously around the track without leaving the road.

#### 2. Final Model Architecture

The final model architecture (model.py lines 148-170) consisted of a convolution neural network with the following layers and layer sizes 
```python
Model: "sequential"
_________________________________________________________________
Layer (type)                 Output Shape              Param #   
=================================================================
lambda (Lambda)              (None, 160, 320, 3)       0         
_________________________________________________________________
cropping2d (Cropping2D)      (None, 65, 320, 3)        0         
_________________________________________________________________
conv2d (Conv2D)              (None, 31, 158, 24)       1824      
_________________________________________________________________
conv2d_1 (Conv2D)            (None, 14, 77, 36)        21636     
_________________________________________________________________
conv2d_2 (Conv2D)            (None, 5, 37, 48)         43248     
_________________________________________________________________
conv2d_3 (Conv2D)            (None, 3, 35, 64)         27712     
_________________________________________________________________
conv2d_4 (Conv2D)            (None, 1, 33, 64)         36928     
_________________________________________________________________
dropout (Dropout)            (None, 1, 33, 64)         0         
_________________________________________________________________
flatten (Flatten)            (None, 2112)              0         
_________________________________________________________________
dense (Dense)                (None, 100)               211300    
_________________________________________________________________
dropout_1 (Dropout)          (None, 100)               0         
_________________________________________________________________
dense_1 (Dense)              (None, 50)                5050      
_________________________________________________________________
dropout_2 (Dropout)          (None, 50)                0         
_________________________________________________________________
dense_2 (Dense)              (None, 10)                510       
_________________________________________________________________
dense_3 (Dense)              (None, 1)                 11        
=================================================================
Total params: 348,219
Trainable params: 348,219
Non-trainable params: 0
_________________________________________________________________
None
```
## Training Results

![Unknown7](https://user-images.githubusercontent.com/61292363/107575589-1c454180-6c01-11eb-9f9d-cd010ef8b7ab.png)

## Results


![github](https://user-images.githubusercontent.com/61292363/106394095-dcfe4000-640b-11eb-81f5-09d884388501.mp4)
Autonomus driving in the simulator
