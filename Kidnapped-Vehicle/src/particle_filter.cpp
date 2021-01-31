/**
 * particle_filter.cpp
 *
 * Created on: Dec 12, 2016
 * Author: Tiffany Huang
 */

#include "particle_filter.h"

#include <math.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <string>
#include <vector>

#include "helper_functions.h"

using std::string;
using std::vector;
using std::normal_distribution;
void ParticleFilter::init(double x, double y, double theta, double std[]) {
  /**
   * TODO: Set the number of particles. Initialize all particles to
   *   first position (based on estimates of x, y, theta and their uncertainties
   *   from GPS) and all weights to 1.
   * TODO: Add random Gaussian noise to each particle.
   * NOTE: Consult particle_filter.h for more information about this method
   *   (and others in this file).
   */
  num_particles = 300;  // TODO: Set the number of particles
  std::default_random_engine gen;
  
  
  normal_distribution<double> dist_x(x, std[0]);
  normal_distribution<double> dist_y(y, std[1]);
  normal_distribution<double> dist_theta(theta, std[2]);
  particles.resize(num_particles);
  
  for (size_t i = 0; i < particles.size(); ++i) {
    
    
    
    particles[i].id = i;
    particles[i].x = dist_x(gen);
    particles[i].y = dist_y(gen);
    particles[i].theta = dist_theta(gen);
    particles[i].weight = 1;
    
    
  }
  is_initialized = true;

}

void ParticleFilter::prediction(double delta_t, double std_pos[],
                                double velocity, double yaw_rate) {
  /**
   * TODO: Add measurements to each particle and add random Gaussian noise.
   * NOTE: When adding noise you may find std::normal_distribution
   *   and std::default_random_engine useful.
   *  http://en.cppreference.com/w/cpp/numeric/random/normal_distribution
   *  http://www.cplusplus.com/reference/random/default_random_engine/
   */
   std::default_random_engine gen;
   
   //normal_distribution<double> dist_x(0, std_pos[0]);
   //normal_distribution<double> dist_y(0, std_pos[1]);
   //normal_distribution<double> dist_theta(0, std_pos[2]);
   
  
   for (size_t i=0; i < particles.size(); ++i){
     
     if (fabs(yaw_rate) > 0.000001) {
       particles[i].x += (velocity/yaw_rate)*(sin(particles[i].theta+yaw_rate*delta_t)-sin(particles[i].theta));
       particles[i].y += (velocity/yaw_rate)*(cos(particles[i].theta) - cos(particles[i].theta+yaw_rate*delta_t));
       particles[i].theta += yaw_rate*delta_t;
     }
     else {
       particles[i].x += velocity * delta_t * cos(particles[i].theta);
       particles[i].y += velocity * delta_t * sin(particles[i].theta);
       particles[i].theta += yaw_rate*delta_t;
     }
     
     normal_distribution<double> dist_x(particles[i].x, std_pos[0]);
     normal_distribution<double> dist_y(particles[i].y, std_pos[1]);
     normal_distribution<double> dist_theta(particles[i].theta, std_pos[2]);
     
     particles[i].x = dist_x(gen);
     particles[i].y = dist_y(gen);
     particles[i].theta = dist_theta(gen);
   }

}

void ParticleFilter::dataAssociation(vector<LandmarkObs> predicted,
                                     vector<LandmarkObs>& observations) {
  /**
   * TODO: Find the predicted measurement that is closest to each
   *   observed measurement and assign the observed measurement to this
   *   particular landmark.
   * NOTE: this method will NOT be called by the grading code. But you will
   *   probably find it useful to implement this method and use it as a helper
   *   during the updateWeights phase.
   */
   if (0 < predicted.size()) {
   for (size_t i=0; i < observations.size(); ++i){
     size_t p=0;
     
     double dist_min = dist(predicted[0].x, predicted[0].y, observations[i].x, observations[i].y);
     for (size_t j=1; j < predicted.size(); ++j){
       
       
       double dist_a = dist(predicted[j].x, predicted[j].y, observations[i].x, observations[i].y);
       if (dist_min > dist_a){
         dist_min = dist_a;
         p = j;
       }
         
     }
     observations[i].id = predicted[p].id;
     observations[i].x = predicted[p].x;
     observations[i].y = predicted[p].y;
     }
   }
}

double multiv_prob(double sig_x, double sig_y, double x_obs, double y_obs,
                   double mu_x, double mu_y) {
  // calculate normalization term
  double gauss_norm;
  gauss_norm = 1 / (2 * M_PI * sig_x * sig_y);

  // calculate exponent
  double exponent;
  exponent = (pow(x_obs - mu_x, 2) / (2 * pow(sig_x, 2)))
               + (pow(y_obs - mu_y, 2) / (2 * pow(sig_y, 2)));
    
  // calculate weight using normalization terms and exponent
  double weight;
  weight = gauss_norm * exp(-exponent);
    
  return weight;
}

void ParticleFilter::updateWeights(double sensor_range, double std_landmark[],
                                   const vector<LandmarkObs> &observations,
                                   const Map &map_landmarks) {
  /**
   * TODO: Update the weights of each particle using a mult-variate Gaussian
   *   distribution. You can read more about this distribution here:
   *   https://en.wikipedia.org/wiki/Multivariate_normal_distribution
   * NOTE: The observations are given in the VEHICLE'S coordinate system.
   *   Your particles are located according to the MAP'S coordinate system.
   *   You will need to transform between the two systems. Keep in mind that
   *   this transformation requires both rotation AND translation (but no scaling).
   *   The following is a good resource for the theory:
   *   https://www.willamette.edu/~gorr/classes/GeneralGraphics/Transforms/transforms2d.htm
   *   and the following is a good resource for the actual equation to implement
   *   (look at equation 3.33) http://planning.cs.uiuc.edu/node99.html
   */
    
    
    
    double sum_weight;
    
    for (size_t i = 0; i < particles.size(); ++i){
      vector<LandmarkObs> trans_observations(observations);
      vector<LandmarkObs> trans_observations_landmark;
      for (size_t j=0; j < trans_observations.size(); ++j){
         double x_obs = trans_observations[j].x;
         double y_obs = trans_observations[j].y;
         trans_observations[j].id = trans_observations[j].id;
         trans_observations[j].x = particles[i].x + cos(particles[i].theta) * x_obs - sin(particles[i].theta) * y_obs;
         trans_observations[j].y = particles[i].y + sin(particles[i].theta) * x_obs + cos(particles[i].theta) * y_obs;
         }
      trans_observations_landmark = trans_observations;
      vector<LandmarkObs> predicted;
      for (size_t j = 0; j < map_landmarks.landmark_list.size(); ++j) {

        if (sensor_range >= dist(particles[i].x, particles[i].y, map_landmarks.landmark_list[j].x_f, map_landmarks.landmark_list[j].y_f)) {

          LandmarkObs in_range_landmark = {
            map_landmarks.landmark_list[j].id_i,
            map_landmarks.landmark_list[j].x_f,
            map_landmarks.landmark_list[j].y_f
          };
            predicted.push_back(in_range_landmark);
          }
        }
      dataAssociation(predicted, trans_observations_landmark);
      double weight = 0;
      double sig_x, sig_y, x_obs, y_obs, mu_x, mu_y;
      for (size_t j=0; j < trans_observations_landmark.size(); ++j){
      sig_x = std_landmark[0];
      sig_y = std_landmark[1];
      mu_x = trans_observations[j].x;
      mu_y = trans_observations[j].y;
      x_obs = trans_observations_landmark[j].x;
      y_obs = trans_observations_landmark[j].y;
      weight = multiv_prob(sig_x, sig_y, x_obs, y_obs, mu_x, mu_y);
      if (weight == 0)
      {
        particles[i].weight  *= 0.000001;
      }
      else{
        particles[i].weight  *= weight;
      }
      }
      
      sum_weight += particles[i].weight;
      
    }
  
  
  for (size_t i=0; i < particles.size(); ++i){
    particles[i].weight /= sum_weight;
  }
}

void ParticleFilter::resample() {
  /**
   * TODO: Resample particles with replacement with probability proportional
   *   to their weight.
   * NOTE: You may find std::discrete_distribution helpful here.
   *   http://en.cppreference.com/w/cpp/numeric/random/discrete_distribution
   */
   std::random_device rd;
   std::mt19937 gen(rd());
   
   std::vector<Particle> new_particles(num_particles);
   std::vector<double> weights(particles.size());
   for (size_t i=0; i < particles.size(); i++)
   {
     weights[i] = particles[i].weight;
     }
   
   std::discrete_distribution<> d(weights.begin(), weights.end());
   for (size_t i=0; i < particles.size(); i++) {
     new_particles[i] = particles[d(gen)];
   }
   particles = new_particles;

}

void ParticleFilter::SetAssociations(Particle& particle,
                                     const vector<int>& associations,
                                     const vector<double>& sense_x,
                                     const vector<double>& sense_y) {
  // particle: the particle to which assign each listed association,
  //   and association's (x,y) world coordinates mapping
  // associations: The landmark id that goes along with each listed association
  // sense_x: the associations x mapping already converted to world coordinates
  // sense_y: the associations y mapping already converted to world coordinates
  particle.associations= associations;
  particle.sense_x = sense_x;
  particle.sense_y = sense_y;
}

string ParticleFilter::getAssociations(Particle best) {
  vector<int> v = best.associations;
  std::stringstream ss;
  copy(v.begin(), v.end(), std::ostream_iterator<int>(ss, " "));
  string s = ss.str();
  s = s.substr(0, s.length()-1);  // get rid of the trailing space
  return s;
}

string ParticleFilter::getSenseCoord(Particle best, string coord) {
  vector<double> v;

  if (coord == "X") {
    v = best.sense_x;
  } else {
    v = best.sense_y;
  }

  std::stringstream ss;
  copy(v.begin(), v.end(), std::ostream_iterator<float>(ss, " "));
  string s = ss.str();
  s = s.substr(0, s.length()-1);  // get rid of the trailing space
  return s;
}
