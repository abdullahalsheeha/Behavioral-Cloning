# **Finding Lane Lines on the Road** 

![Unknown-6](https://user-images.githubusercontent.com/61292363/107556896-ffe9da80-6be9-11eb-87a8-e040cc802e3a.png)

Overview
---

When we drive, we use our eyes to decide where to go.  The lines on the road that show us where the lanes are act as our constant reference for where to steer the vehicle.  Naturally, one of the first things we would like to do in developing a self-driving car is to automatically detect lane lines using an algorithm.

## 1. Pipeline description
My pipeline consisted of 8 steps.

* Step 1: Convert the colored image to grayscale.
* Step 2: Smooth with Gaussian Blur
* Step 3: Detect edges with Canny edge detection operator
* Step 4: Select Region Of Interest (ROI)
* Step 5: Find lines with Hough transform
* Step 6: Determine the left and right lane from detected the lines
* Step 7: Draw lines

## 2. Potential shortcomings with this pipeline
Shortcomings are:

* Based on average filtering, the algorithm can't follow the rapid changes of line.
* If the light conditions are not proper, edges could not be detected.

# Results

![github](https://user-images.githubusercontent.com/61292363/106393687-aa534800-6409-11eb-9518-b3a8ce1ba5df.mp4)
