## Advanced Lane Finding

The goals / steps of this project are the following:

* Compute the camera calibration matrix and distortion coefficients given a set of chessboard images.
* Apply a distortion correction to raw images.
* Use color transforms, gradients, etc., to create a thresholded binary image.
* Apply a perspective transform to rectify binary image ("birds-eye view").
* Detect lane pixels and fit to find the lane boundary.
* Determine the curvature of the lane and vehicle position with respect to center.
* Warp the detected lane boundaries back onto the original image.
* Output visual display of the lane boundaries and numerical estimation of lane curvature and vehicle position.

### Camera Calibration

#### 1. Calculating camera matrix and distortion coefficients to eliminate camera distortion.
Calibration parameters which are the camera matrix and distortion coefficients are determined. I read the calibration pictures with glob library. With a for loop, I processed all the images. These were process steps:

Convert current image to grayscale
Find corners with findChessboardCorners() function
If corners were found, I appended the corners and image points to my list

### Pipeline (single images)

#### 1. Generate undistorted image
To eliminate distortion, I used the camera matrix and distortion coefficients, which are calculated with camera calibration.
![Unknown](https://user-images.githubusercontent.com/61292363/107550263-dcbb2d00-6be1-11eb-9e1f-3d7d64b1d91a.png)

#### 2. Get bird's eye view
The code for my perspective transform includes a function called `warper()`. The `warper()` function takes as inputs an image (`img`), as well as source (`src`) and destination (`dst`) points.  I chose the hardcode the source and destination points in the following manner:

This resulted in the following source and destination points:

| Source        | Destination   | 
|:-------------:|:-------------:| 
| 210, 720      | 200, 720        | 
| 595, 450      | 200, 0      |
| 690, 450     | 1000, 0      |
| 1110, 720      | 1000, 720        |

I verified that my perspective transform was working as expected by drawing the `src` and `dst` points onto a test image and its warped counterpart to verify that the lines appear parallel in the warped image.

![Unknown-2](https://user-images.githubusercontent.com/61292363/107551615-8c44cf00-6be3-11eb-8870-2414957fa185.png)

#### 3. Image filtering

I filtered the image with the combination of Sobel edge detection and HSV color filtering. I used absolute gradient magnitude and gradient direction for Sobel
first visualize color spaces HSV (color space transformation is done using cv2). V-channel in HSV seem to work best in their respective space. 
With some error and trial by observation, find the threshold (210, 255) to perform pretty well for V-channel in HSV.

![Unknown-3](https://user-images.githubusercontent.com/61292363/107552897-248f8380-6be5-11eb-91ee-841b0df1ab43.png)


#### 4. Identifying lane-line pixels and fit their positions with a polynomial

I used second order polynomial to fit the lane: x = ay^2 + by + c.

Then we divide the image in windows, and for each left and right window we find the mean of it, re-centering the window. The points inside the windows are stored. We then feed the numpy polyfit function to find the best second order polynomial to represent the lanes.

#### 5. calculated the radius of curvature of the lane and the position of the vehicle with respect to center.

TheÊget_radius_and_offset()Êfunction handles calculating the radius and offset.
To calculate the radius, we first fine the curvature of each line individually.

After finding the curvature of each line, we simply get the average of the two.
left_curverad =  ((1 + (2*left_fit[0]*720*ym_per_pixel + left_fit[1])**2)**(3/2))/np.abs(2*left_fit[0])
right_curverad =  ((1 + (2*right_fit[0]*720*ym_per_pixel + right_fit[1])**2)**(3/2))/np.abs(2*right_fit[0])
radius = np.mean([left_curverad, right_curverad])
To calculate the offset, we calculate the x position of each lane line within the image and subtract the the center of the lane (which we assume is the location of the camera), after converting pixels to meters.
left_lane = left_fit[0]*(720*ym_per_pixel)^2 + left_fit[1]*720*ym_per_pixel + left_fit[2]
right_lane = right_fit[0]*(720*ym_per_pixel)^2 + right_fit[1]*720*ym_per_pixel + right_fit[2]
offset = [640*xm_per_pixel - np.mean([left_lane, right_lane]), right_lane-left_lane]
The final code used in the image and video pipelines can be seen in theÊget_radius_and_offset()Êfunction in the notebook.

![Unknown-5](https://user-images.githubusercontent.com/61292363/107554052-74227f00-6be6-11eb-9459-e5cc58b7aaa5.png)


### Final result

![github](https://user-images.githubusercontent.com/61292363/106393862-657be100-640a-11eb-9598-badfdbb450fd.mp4)
