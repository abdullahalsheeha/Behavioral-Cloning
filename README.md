# Udacity-Self-Driving-Car-Engineer

This repository houses my solutions for projects completed as part of Udacity's Self-driving Car Engineer Nanodegree.

Projects
### Basic Lane Line Detection
Employ region of interest selection, grayscaling, Gaussian smoothing, Canny Edge Detection and Hough Transform line detection to identify lane lines on the road in an image.

![github](https://user-images.githubusercontent.com/61292363/106393687-aa534800-6409-11eb-9518-b3a8ce1ba5df.mp4)

### Advanced Lane Line Detection
Find lane markings in images and video using color transformations, gradients, and perspective transformation. Determine the curvature of the lane and the vehicle position with respect to center.

![github](https://user-images.githubusercontent.com/61292363/106393862-657be100-640a-11eb-9598-badfdbb450fd.mp4)

### Traffic sign classifier
Train and validate a deep learning model using TensorFlow to classify traffic sign images using the German Traffic Sign Dataset.

![download](https://user-images.githubusercontent.com/61292363/106393930-e1762900-640a-11eb-827a-cbfaba28a73d.png)

### Behavioral Cloning
Use Udacity's driving simulator to create a dataset to clone driving behavior by training and validating a model using Keras. The model outputs a steering angle to an autonomous vehicle.

![github](https://user-images.githubusercontent.com/61292363/106394095-dcfe4000-640b-11eb-81f5-09d884388501.mp4)
Autonomus driving in the simulator



### Extended Kalman Filter
Utilize a Kalman filter, and simulated lidar and radar measurements to track the a bicycle's position and velocity.

Lidar measurements are red circles, radar measurements are blue circles with an arrow pointing in the direction of the observed angle, and estimation markers are green triangles.

<img width="964" alt="Screen Shot 2021-01-31 at 9 38 29 PM" src="https://user-images.githubusercontent.com/61292363/106394284-e340ec00-640c-11eb-961c-e6d85bf284cf.png">

### Localization: Particle Filter
A 2 dimensional particle filter in C++. The particle filter is given a map and some initial localization information (analogous to what a GPS would provide). At each time step the filter is also given observation and control data.

![github](https://user-images.githubusercontent.com/61292363/106394455-c22ccb00-640d-11eb-9287-4ca3cb13a7ed.mov)

### Path Planning: Vehicle Trajectories
Safely navigate a self-driving car around a virtual the highway track has other vehicles, all going different speeds, but approximately obeying the 50 MPH speed limit.
The car transmits its location, along with its sensor fusion data, which estimates the location of all the vehicles on the same side of the road.
The path planner outputs a list of (x,y) global map coordinates that form a trajectory. Every 0.02 s the car moves to the next point on the list. The car's new rotation becomes the line between the previous waypoint and the car's new location.
The planner implemented is able to drive safely at a speed slightly below the 50MPH limit for 4.32 miles without incident.

![github](https://user-images.githubusercontent.com/61292363/106394842-cce85f80-640f-11eb-9d1f-252d8bbbb057.mov)

### PID controller
Use a Proportional-Integral-Derivative Controller (PID), to control the steering angle of a simuluated self-driving car maneuvering around a circular track.

![github](https://user-images.githubusercontent.com/61292363/106394657-b8579780-640e-11eb-939f-ac48967d4c3f.mp4)

