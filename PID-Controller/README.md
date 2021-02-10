# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Overview
Describe the effect each of the P, I, D components had in your implementation.
Proportional: This component of the controller refers to the proportional control relative to CTE. The CTE is the current y-position of our self-driving car along the x-axis, when our reference is a horizontal line. The formula to calculate steering is (steering = -Kp * cte). If we only use P control, our car would have a tendency to overshoot our reference point.

Derivative: In this component we have to calculate the difference between current CTE and previous CTE. This will allow our self-driving car to update the steering and ability to avoid overshooting and converge with the reference. The formula to calculate steering is (steering = -Kp * cte - Kd * (cte - previous_cte)).

Integral: The integral in a PID controller is the sum of the instantaneous error over time and gives the accumulated offset that should have been corrected previously. The formula to calculate steering is (steering = -Kp * cte - Kd * (cte - previous_cte) - Ki * sum_cte).

## Tuning
I manually tuned the initial values for the PID controller.



## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Results

![github](https://user-images.githubusercontent.com/61292363/106394657-b8579780-640e-11eb-939f-ac48967d4c3f.mp4)
