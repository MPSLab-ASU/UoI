#ifndef ALPHA_GRID_H
#define ALPHA_GRID_H

#include <eigen3/Eigen/Dense>
#include <tuple>

using namespace std;
using namespace Eigen;


#ifdef __cplusplus
  extern "C" {
#endif
tuple<VectorXf,float> alpha_grid( MatrixXf X, VectorXf y, float l1_ratio, int n_alphas, float eps, int n_samples); 
#ifdef __cplusplus
 }
#endif

#endif
