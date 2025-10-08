#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main() {
    // make matrices
    matrix A = new_matrix(5,5);
    matrix B = new_matrix(5,5);

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            mget(A,i,j) = -1.0*(i==j) + 2.0*(i-1==j) + 2.0*(j-1==i);
            mget(B,i,j) = 2.0*(i==j) + 1.0*(i-1==j) + 1.0*(j-1==i);
        }
    }

    // print matrices
    print_matrix(&A);
    print_matrix(&B);
    
    // add, subtract, multiply
    matrix C = matrix_add(&A,&B);
    print_matrix(&C);
    matrix E = matrix_mult(&A,&B);
    print_matrix(&E);

    // vectors 
    vector x = new_vector(5);
    vector y = new_vector(5);

    vget(x,1) = 1.0;
    vget(x,2) = 2.0;
    vget(x,3) = 3.0;
    vget(x,4) = 4.0;
    vget(x,5) = 5.0;

    vget(y,1) = 5.0;
    vget(y,2) = 4.0;
    vget(y,3) = 3.0;
    vget(y,4) = 2.0;
    vget(y,5) = 1.0;

    // print vectors
    print_vector(&x);
    print_vector(&y);

    // add, subtract, dot
    vector z = vector_add(&x,&y);
    print_vector(&z);
    double d = vector_dot_mult(&x,&y);
    print_scalar(&d);

    // matrix vector multiply
    vector b = matrix_vector_mult(&A,&x);
    print_vector(&b);

    // solve Ax = b
    vector x2 = solve(&A,&b);
    print_vector(&x2);
}