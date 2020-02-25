#define EIGEN_DEFAULT_TO_ROW_MAJOR
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <mpi.h>
#include <tuple>
#define EIGEN_USE_MKL_ALL
#include <eigen3/Eigen/Dense>
#include <mkl.h>

#include "logspace.h"

using namespace std;
using namespace Eigen;

VectorXf logspace (float start, float end, int size) {

  VectorXf vec;
  vec.setLinSpaced(size, start, end);

  for(int i=0; i<size; i++)
    vec(i) = pow(10,vec(i));

  return vec;
}

