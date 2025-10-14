#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <assert.h>
#include "matrix.h"
#include "trimatrix.h"

int main() {
    srand(time(NULL));
    int N = 0;
    printf(" Input N (size for NxN matrix): ");
    scanf("%i", &N);
    assert(N>1);
    
    // Create A = LL^T where L is lower triangular with 1 on diagonal and 
    // random numbers between 0 and 1 below
    matrix A = new_matrix(N,N);
    matrix L = new_matrix(N,N);
    matrix LT = new_matrix(N,N);
    double rand_val;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            rand_val = (double)rand() / (double)RAND_MAX;
            mget(L,i,j) = rand_val * (i>j) + 1.0e0*(i==j) + 0.0e0*(i<j);
            mget(LT,j,i) = rand_val * (i>j) + 1.0e0*(i==j) + 0.0e0*(i<j);
        }
    }

    printf("\nCreated L:\n");
    print_matrix(&L);

    A = matrix_mult(&L,&LT);

    // Hessenberg reduction to tridiagonal form
    trimatrix T = new_trimatrix(N);
    void Hessenberg(const matrix* A, const trimatrix* T);
    Hessenberg(&A,&T);
    printf("\n Original Matrix (A = L*L^T):\n");
    print_matrix(&A);
    printf("Reduction to Tridiagonal form:\n");
    print_trimatrix(&T);

    // QR Algorithim to find eigenvalues of T, the same eigenvalues of A
    void QRA(const trimatrix* T);
    QRA(&T);
    printf("After QR Algorithm:\n");
    print_trimatrix(&T);

    return 0;
}