# CarND-Path-Planning-Project
Self-Driving Car Engineer Nanodegree Program
   
### Intoduction
The goal of this project is to build a path planner to safely navigate around a virtual highway with other cars.

The highway track has other vehicles, all going different speeds, but approximately obeying the 50 MPH speed limit.

The car transmits its location, along with its sensor fusion data, which estimates the location of all the vehicles on the same side of the road.

The path planner outputs a list of (x,y) global map coordinates that form a trajectory. Every 0.02 s the car moves to the next point on the list. The car's new rotation becomes the line between the previous waypoint and the car's new location.

The planner implemented is able to drive safely at a speed slightly below the 50MPH limit for 4.32 miles without incident.


### Basic Build Instructions
* Clone this repo.
* Make a build directory: mkdir build && cd build
* Compile: cmake .. && make
* Run it: ./path_planning.



### Reflection
The code is divided in 2 main files:

main.cpp which contains all the code.
spline.h which contains the spline library to implement a spline interpolation function.

In main.cpp, I start by pulling telemetry data from the simulator, containing my car localization, previous path given to the planner, and sensor fusion data with the information of all the other vehicles moving around my car in the road. (78-94)

I take the coordinates of the last two points of the previous path and save them in ptsx and ptsy vectors, that will later be used as input to the spline function to generate the new trajectory. If this is the first time, I use the current position of the car as starting point. (194-216).

The path planner is divided in 3 steps:



### Prediction & Behavior Planning:
In this step, I updated all the three lane's state. The simulation sent the sensor fusion data, which contained, every necessarily information. I selected the current lane based on frenet d value. After update, I had the car's relative distance, velocity in each lane, which is ahead of my car, or behind me 20 m. This 20 meter tolerance was given to increase the maneuver safety. if its not safe to change lane and the car in front me in range 30 m, my car have to slow down. (109-185)


### Trajectory Generation
I take the frenet d value and use it to generate the cartesian (x, y) coordinates for 3 target points in the future, that are added to the ptsx and ptsy vectors together with the last 2 points from the previous path that were added before.(219-229)

I take the ptsx and ptsy vectors and shift and rotate the points to local car coordinates. Then I fit a spline (232-242).

Using the spline curve calculated, I take the first 30m chunk (my target_x distance) and split it to generate the waypoints of my new trajectory. Each point represents the position of my car every 0.02s. I use each point velocity to calculate the x position of my car at the end of the 0.02s interval, and use the spline to calculate my y coordinate. Finally, I shift and rotate these points back to global coordinates and save them in a next_x_vals and next_y_vals vectors. This new trajectory generate is fed to the simulator. (249-275)


## Results 

![github](https://user-images.githubusercontent.com/61292363/106394842-cce85f80-640f-11eb-9d1f-252d8bbbb057.mov)
