# **Finding Lane Lines on the Road** 

## Writeup Template

### You can use this file as a template for your writeup if you want to submit it as a markdown file. But feel free to use some other method and submit a pdf if you prefer.

---

**Finding Lane Lines on the Road**

The goals / steps of this project are the following:
* Make a pipeline that finds lane lines on the road
* Reflect on your work in a written report


[//]: # (Image References)

[image1]: ./examples/grayscale.jpg "Grayscale"

---

### Reflection

### 1. Describe your pipeline. As part of the description, explain how you modified the draw_lines() function.

My pipeline consisted of 5 steps. First, I converted the images to grayscale, then I used the GaussianBlur method to smooth the image to reduce noise. I passed the blurred image to Canny with thresholds of 50 and 150 for low and high, respectively. I chose these numbers via trial and error and these seemed to produce good enough results. After finding the edges, I narrowed down the scope of focus using a mask to limit to the region we expect the lane to fall into. Using the HoughLinesP and addWeighted methods, I was able to draw our detected lines onto our image.

In order to draw a single line on the left and right lanes, I modified the draw_lines() function by using average_slope_intercept() function which is taking the slope and intercept of hough_line() function then taking the average of slope and intercept after that i use make_points() function which is making points by using the average slope and intercept then i use draw_lines() function.   

If you'd like to include images to show how the pipeline works, here is how to include an image: 

![alt text][image1]


### 2. Identify potential shortcomings with your current pipeline


One potential shortcoming is the pre-determined min and max parameters for the hough transformation function. I imagine differences in lane markings, such as the distance between dashed lanes, would impact the pipeline's ability to accurately detect lanes. Additionally, the pipeline has some shortcomings when it comes to curves. If the lane turns at an angle great enough to move the lane "end" from the center of the graph, the detected lane lines will not align with reality. It's also possible the lane will move outside the "region_of_interest" we have defined. 




### 3. Suggest possible improvements to your pipeline

A possible improvement would be to understand the curvature of the lane
