# **Traffic Sign Recognition** 

## Writeup

### You can use this file as a template for your writeup if you want to submit it as a markdown file, but feel free to use some other method and submit a pdf if you prefer.

---

**Build a Traffic Sign Recognition Project**

The goals / steps of this project are the following:
* Load the data set (see below for links to the project data set)
* Explore, summarize and visualize the data set
* Design, train and test a model architecture
* Use the model to make predictions on new images
* Analyze the softmax probabilities of the new images
* Summarize the results with a written report


[//]: # (Image References)

[image1]: ./examples/visualization.jpg "Visualization"
[image2]: ./examples/grayscale.jpg "Grayscaling"
[image3]: ./examples/random_noise.jpg "Random Noise"
[image4]: ./examples/placeholder.png "Traffic Sign 1"
[image5]: ./examples/placeholder.png "Traffic Sign 2"
[image6]: ./examples/placeholder.png "Traffic Sign 3"
[image7]: ./examples/placeholder.png "Traffic Sign 4"
[image8]: ./examples/placeholder.png "Traffic Sign 5"

## Rubric Points
### Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/481/view) individually and describe how I addressed each point in my implementation.  

---
### Writeup / README

#### 1. Provide a Writeup / README that includes all the rubric points and how you addressed each one. You can submit your writeup as markdown or pdf. You can use this template as a guide for writing the report. The submission includes the project code.

You're reading it! and here is a link to my [project code](https://github.com/udacity/CarND-Traffic-Sign-Classifier-Project/blob/master/Traffic_Sign_Classifier.ipynb)

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

Here is an exploratory visualization of the data set. It is a bar chart showing how the data ...


### Design and Test a Model Architecture

#### 1. Describe how you preprocessed the image data. What techniques were chosen and why did you choose these techniques? Consider including images showing the output of each preprocessing technique. Pre-processing refers to techniques such as converting to grayscale, normalization, etc. (OPTIONAL: As described in the "Stand Out Suggestions" part of the rubric, if you generated additional data for training, describe why you decided to generate additional data, how you generated the data, and provide example images of the additional data. Then describe the characteristics of the augmented training set like number of images in the set, number of images for each class, etc.)

As a first step, I decided to normalized the image data because i want the pixles to be in range between 0 and 1, because the scale of the data has an effect on the magnitude of the gradient for the weights.





#### 2. Describe what your final model architecture looks like including model type, layers, layer sizes, connectivity, etc.) Consider including a diagram and/or table describing the final model.

My final model consisted of the following layers:

| Layer         		|     Description	        					| 
|:---------------------:|:---------------------------------------------:| 
| Input         		| 32x32x3 RGB image   							| 
| Convolution 3x3     	| 1x1 stride, valid padding, outputs 30x30x20 	|
| RELU					|												|
| Max pooling	      	| 2x2 stride,  outputs 15x15x20 				|
| Convolution 3x3     	| 1x1 stride, valid padding, outputs 13x13x50 	|
| RELU					|												|
| Max pooling	      	| 2x2 stride,  outputs 6x6x50 					|
| Flatten				| 												|
| Fully connected		| 500 neurons  									|
| RELU					|												|
| Dropout				| Probability of keeping 50%					|
| Fully connected		| 256 neurons  									|
| RELU					|												|
| Fully connected		| 43 neurons  									|

 


#### 3. Describe how you trained your model. The discussion can include the type of optimizer, the batch size, number of epochs and any hyperparameters such as learning rate.

To train the model, I used an Adam optimizer, 128 batch size, 30 epochs and 0.001.

#### 4. Describe the approach taken for finding a solution and getting the validation set accuracy to be at least 0.93. Include in the discussion the results on the training, validation and test sets and where in the code these were calculated. Your approach may have been an iterative process, in which case, outline the steps you took to get to the final solution and why you chose those steps. Perhaps your solution involved an already well known implementation or architecture. In this case, discuss why you think the architecture is suitable for the current problem.

My final model results were:
* training set accuracy of 99.8%
* validation set accuracy of 94.1%
* test set accuracy of 95.7%

If an iterative approach was chosen:
* What was the first architecture that was tried and why was it chosen?
| Layer         		|     Description	        					| 
|:---------------------:|:---------------------------------------------:| 
| Input         		| 32x32x3 RGB image   							| 
| Convolution 3x3     	| 1x1 stride, valid padding, outputs 30x30x64 	|
| RELU					|												|
| Dropout				| Probability of keeping 50%					|
| Max pooling	      	| 2x2 stride,  outputs 15x15x64 				|
| Convolution 3x3     	| 1x1 stride, valid padding, outputs 13x13x128 	|
| RELU					|												|
| Max pooling	      	| 2x2 stride,  outputs 6x6x128 					|
| Flatten				|												|
| Convolution 3x3	    | 1x1 stride, valid padding, outputs 4x4x256    |
| RELU					|												|
| Max pooling	      	| 2x2 stride,  outputs 2x2x128 					|
| Dropout				| Probability of keeping 50%					|
| Flatten				| 												|
| Fully connected		| 512 neurons  									|
| RELU					|												|
| Fully connected		| 256 neurons  									|
| RELU					|												|
| Fully connected		| 128 neurons  									|
| RELU					|												|
| Fully connected		| 43 neurons  									|
I tried to use many convolution layers and large number of filters and so many fully connected layers.
* What were some problems with the initial architecture?
 It was large number of convolution filters and so many fully connected layers.
* How was the architecture adjusted and why was it adjusted? Typical adjustments could include choosing a different model architecture, adding or taking away layers (pooling, dropout, convolution, etc), using an activation function or changing the activation function. One common justification for adjusting an architecture would be due to overfitting or underfitting. A high accuracy on the training set but low accuracy on the validation set indicates over fitting; a low accuracy on both sets indicates under fitting.
It was low validation accuracy; I try to remove some of convolution layer and reduce the number of filter and I did the same for fully connected layers. 
* Which parameters were tuned? How were they adjusted and why?
* What are some of the important design choices and why were they chosen? For example, why might a convolution layer work well with this problem? How might a dropout layer help with creating a successful model?

If a well known architecture was chosen:
* What architecture was chosen?
| Layer         		|     Description	        					| 
|:---------------------:|:---------------------------------------------:| 
| Input         		| 32x32x3 RGB image   							| 
| Convolution 3x3     	| 1x1 stride, valid padding, outputs 30x30x20 	|
| RELU					|												|
| Max pooling	      	| 2x2 stride,  outputs 15x15x20 				|
| Convolution 3x3     	| 1x1 stride, valid padding, outputs 13x13x50 	|
| RELU					|												|
| Max pooling	      	| 2x2 stride,  outputs 6x6x50 					|
| Flatten				| 												|
| Fully connected		| 500 neurons  									|
| RELU					|												|
| Dropout				| Probability of keeping 50%					|
| Fully connected		| 256 neurons  									|
| RELU					|												|
| Fully connected		| 43 neurons  									|

* Why did you believe it would be relevant to the traffic sign application?
I try and it�s work very good.
* How does the final model's accuracy on the training, validation and test set provide evidence that the model is working well?
 I try the model in new images and predict 4 from 5 of images

### Test a Model on New Images

#### 1. Choose five German traffic signs found on the web and provide them in the report. For each image, discuss what quality or qualities might be difficult to classify.

Here are five German traffic signs that I found on the web:




#### 2. Discuss the model's predictions on these new traffic signs and compare the results to predicting on the test set. At a minimum, discuss what the predictions were, the accuracy on these new predictions, and compare the accuracy to the accuracy on the test set (OPTIONAL: Discuss the results in more detail as described in the "Stand Out Suggestions" part of the rubric).

Here are the results of the prediction:

| Image			        |     Prediction	        					| 
|:---------------------:|:---------------------------------------------:| 
|No passing for vehicles| No passing for vehicles over 3.5 metric tons  |
 over 3.5 metric tons
| Dangerous curve to    | Dangerous curve to the right.					|
  the right
| Yield					| Yield											|
| 60 km/h	      		| 60 km/h					 				|
| Pedestrians			| General caution
							|


The model was able to correctly guess 5 of the 5 traffic signs, which gives an accuracy of 100%. This compares favorably to the accuracy on the test set of 94.1%

#### 3. Describe how certain the model is when predicting on each of the five new images by looking at the softmax probabilities for each prediction. Provide the top 5 softmax probabilities for each image along with the sign type of each probability. (OPTIONAL: as described in the "Stand Out Suggestions" part of the rubric, visualizations can also be provided such as bar charts)

The code for making predictions on my final model is located in the 11th cell of the Ipython notebook.

For the first image, the model is relatively sure that this is a stop sign (probability of 0.6), and the image does contain a stop sign. The top five soft max probabilities were

| Probability         	|     Prediction	        					| 
|:---------------------:|:---------------------------------------------:| 
| 1.00         			| No passing for vehicles over 3.5 metric tons  | 
| 1.00     				| Dangerous curve to the right.					|
| 1.00					| Yield											|
| 1.00	      			| 60 km/h					 				|
| 0.00				    | Pedestrians      							|


For the second image ... 

### (Optional) Visualizing the Neural Network (See Step 4 of the Ipython notebook for more details)
#### 1. Discuss the visual output of your trained network's feature maps. What characteristics did the neural network use to make classifications?



