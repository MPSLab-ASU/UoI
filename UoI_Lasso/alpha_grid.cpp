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
#include "alpha_grid.h"


using namespace std;
using namespace Eigen;

tuple<VectorXf,float> alpha_grid( MatrixXf X, VectorXf y, float l1_ratio, int n_alphas, float eps, int n_samples)
{

  int rank;
  int size;

  MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
  MPI_Comm_size(MPI_COMM_WORLD, &size);
    
  VectorXf Xy(X.cols());

  Xy = X.transpose() * y;

  //Reduce Xy at root to find alpha_max 

  VectorXf Xty;

  if(rank==0)
    Xty.setZero(X.cols());
  
  MPI_Reduce(Xy.data(), Xty.data(), X.cols(), MPI_FLOAT, MPI_SUM, 0,MPI_COMM_WORLD);

 //float alpha_max;  
  VectorXf lambdas(n_alphas);
  
  float alpha_max;
  if(rank==0) {
    //float alpha_max = (Xty.array().square().sum().sqrt().max())  / (n_samples * l1_ratio);
    alpha_max = (Xty.array().square().rowwise().sum().sqrt()).maxCoeff() /  (n_samples * l1_ratio);
    lambdas = logspace(log10(alpha_max*eps), log10(alpha_max), n_alphas);
  }

  MPI_Bcast(lambdas.data(), lambdas.size(), MPI_FLOAT, 0, MPI_COMM_WORLD); 

  return make_tuple(lambdas, alpha_max); 


}
