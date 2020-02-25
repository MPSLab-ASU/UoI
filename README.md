# UoI
## Distributed-UoI_Lasso 
       Updated with BOOST CommandLine and rectified lasso_admm
      tested with real dataset and validated with sklearn Lasso results
                    Runs tested on Cori NERSC supercomputer.
      

## Requirements

languages: C, C++

computing resources: The model is created for `Cori KNL`.

API and Libraries: MPI, HDF5-parallel, eigen3, gsl


## Installation

1. Clone the module into your directory
2. There are two subdirectories namely UoI_Lasso and UoI_VAR.
3. Please follow the README.md in each of these directories. 



## Credits

Author: Mahesh Balasubramanian (guidance from Kris Bouchard, Prabhat, Brandon Cook)

## Paper 

Mahesh Balasubramanian; Trevor Ruiz; Brandon Cook; Mr Prabhat; Sharmodeep Bhattacharyya; Aviral Shrivastava; Kristofer Bouchard: "Scaling of Union of Intersections for Inference of Granger Causal Networks from Observational Data." In: Proceeding of the 34th IEEE International Parallel & Distributed Processing Symposium (IPDPS)

## Citation 

      @inproceedings{BalasubramanianIPDPS2020,
      title = {Scaling of Union of Intersections for Inference of Granger Causal Networks from Observational Data},
      author = {Mahesh Balasubramanian and Trevor Ruiz and Brandon Cook and Mr Prabhat and Sharmodeep Bhattacharyya and Aviral Shrivastava and Kristofer Bouchard},
      year = {2020},
      date = {2020-05-01},
      booktitle = {Proceeding of the 34th IEEE International Parallel & Distributed Processing Symposium (IPDPS)},
      keywords = {Data Analysis},
      pubstate = {forthcoming},
      tppubtype = {inproceedings}
      }

## Notes
The version of MPICH is reverted back to 7.4.4 because of an open ticket regarding the new mpich.

