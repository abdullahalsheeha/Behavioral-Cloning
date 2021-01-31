# Udacity-Self-Driving-Car-Engineer

This repository houses my solutions for projects completed as part of Udacity's Self-driving Car Engineer Nanodegree.

Projects
Basic Lane Line Detection
Employ region of interest selection, grayscaling, Gaussian smoothing, Canny Edge Detection and Hough Transform line detection to identify lane lines on the road in an image.

Finding_lane_lines/test_videos_output/solidWhiteRight.mp4

Advanced Lane Line Detection
Find lane markings in images and video using color transformations, gradients, and perspective transformation. Determine the curvature of the lane and the vehicle position with respect to center.

example
Lane detections with curvature and offset

Rendered notebook
Project writeup
Source

Traffic sign classifier
Train and validate a deep learning model using TensorFlow to classify traffic sign images using the German Traffic Sign Dataset.

Rendered notebook
Project writeup
Source

Behavioral Cloning
Use Udacity's driving simulator to create a dataset to clone driving behavior by training and validating a model using Keras. The model outputs a steering angle to an autonomous vehicle.

example
Autonomus driving in the simulator

Project writeup
Source

Extended Kalman Filter
Utilize a Kalman filter, and simulated lidar and radar measurements to track the a bicycle's position and velocity.

Lidar measurements are red circles, radar measurements are blue circles with an arrow pointing in the direction of the observed angle, and estimation markers are green triangles.

dataset_1

Source

Localization: Particle Filter
A 2 dimensional particle filter in C++. The particle filter is given a map and some initial localization information (analogous to what a GPS would provide). At each time step the filter is also given observation and control data.

particle_filter

Source

Path Planning: Vehicle Trajectories
Safely navigate a self-driving car around a virtual highway with other traffic that is driving +-10 MPH of the 50 MPH speed limit. The car should try to go as close as possible to the 50 MPH speed limit, which means passing slower traffic when possible, note that other cars will try to change lanes too. The car should avoid hitting other cars at all cost as well as driving inside of the marked road lanes at all times, unless going from one lane to another. The car should be able to make one complete loop around the 6946m highway. Since the car is trying to go 50 MPH, it should take a little over 5 minutes to complete 1 loop. Also the car should not experience total acceleration over 10 m/s^2 and jerk that is greater than 10 m/s^3.

path_planning

Video
Source

PID controller
Use a Proportional-Integral-Derivative Controller (PID), to control the steering angle of a simuluated self-driving car maneuvering around a circular track.

ezgif com-optimize

Video
Source

