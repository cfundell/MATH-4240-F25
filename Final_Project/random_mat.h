#ifndef __RANDOM_MAT_H__
#define __RANDOM_MAT_H__

// Declarations of functions that compute means and variances of matrix elements
double calculateVariance(int N, double data[]);
double compute_off_diag_mean(const int size, const matrix* A);
double compute_diag_mean(const int size, const matrix* A);
double compute_matrix_mean(const int size, const matrix* A);
double compute_off_diag_variance(const int size, const matrix* A);
double compute_diag_variance(const int size, const matrix* A);

// Function declarations for computing Irwin-Hall values 
// and generating GOE matrix in serial
void compute_Irwin_Hall_dist(int num_values, char filename[]);
double compute_IH_num();
float compute_IH_num_f();
matrix generate_GOE(int size);

#endif