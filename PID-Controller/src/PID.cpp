#include "PID.h"
#include <math.h>
#include <vector>
/**

 * TODO: Complete the PID class. You may add any additional desired functions.
 */
using std::vector;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   *  Initialize PID coefficients and errors.
   */
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;
  
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  prev_cte= 0.0;
  err = 0.0;
  //err1 = 0.0;
  
}

void PID::UpdateError(double cte) {
  /**
   *  Update PID errors based on cte.
   */
  
  p_error = cte;
  d_error = cte - prev_cte;
  i_error += cte;
  
  prev_cte = cte;
  err += p_error*p_error;
  //err1 = err/2;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  /*vector<double> p = {0, 0, 0};
  vector<double> dp = {1, 1, 1};
  double sum_dp;
  double tol = 0.2;
  double best_err = err1;
  for (int i =0; i<dp.size(); i++){
    sum_dp+=dp[i];
  }
    
  while (sum_dp > tol){
     for (int i =0; i<p.size(); i++){
         p[i] += dp[i];
         
         double err2 = err1;
         if (err < best_err){
            best_err = err2;
            dp[i] *= 1.1;
           }
         else{
           p[i] -= 2 * dp[i];
                
           double err3 = err1;
           if (err < best_err){
              best_err = err3;
              dp[i] *= 1.1;
             }
           else{
              p[i] += dp[i];
              dp[i] *= 0.9;
         }
         }
     }
  }
  Kp = p[0];
  Kd = p[1];
  Ki = p[2];*/
    
    
    
  return -Kp*p_error - Kd*d_error - Ki*i_error;  // TODO: Add your total error calc here!
}
