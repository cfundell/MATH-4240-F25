#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()
#include "matrix.h"

int main() {
    srand(time(NULL));

    // make matrices
    matrix A = new_matrix(5,5);
    matrix L = new_matrix(5,5);
    matrix LT = new_matrix(5,5);
    double rand_val;

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            rand_val = (double)rand() / (double)RAND_MAX;
            mget(L,i,j) = rand_val * (i>j) + 1.0e0*(i==j) + 0.0e0*(i<j);
            mget(LT,j,i) = rand_val * (i>j) + 1.0e0*(i==j) + 0.0e0*(i<j);
        }
    }

    // A = L*LT
    A = matrix_mult(&L,&LT);

    // create random vector 
    vector x = new_vector(5);

    vget(x,1) = (double)rand() / (double)RAND_MAX;
    vget(x,2) = (double)rand() / (double)RAND_MAX;
    vget(x,3) = (double)rand() / (double)RAND_MAX;
    vget(x,4) = (double)rand() / (double)RAND_MAX;
    vget(x,5) = (double)rand() / (double)RAND_MAX;


    // print matrices
    print_matrix(&L);
    print_matrix(&LT);
    print_matrix(&A);
    print_vector(&x);

    // power iteration
    double lambda_power = power_iteration(&x, 0.00001, 1000, &A);
    // shifted inverse
    double lambda_shifted = shifted_inverse(5.0, &x, 0.00001, 1000, &A);

    // print results
    printf("Power Iteration Eigenvalue: %.6e\n", lambda_power);
    printf("Shifted Inverse Eigenvalue: %.6e\n", lambda_shifted);


    return 0;
}