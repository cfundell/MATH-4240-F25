#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include "matrix.h"
#include "random_mat.h"

double calculateVariance(int N, double data[])
{
    // variable to store sum of the given data
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += data[i];
    }

    // calculating mean
    double mean = sum / N;

    // temporary variable to store the summation of square
    // of difference between individual data items and mean
    double values = 0;

    for (int i = 0; i < N; i++) {
        values += pow(data[i] - mean, 2);
    }

    // variance is the square of standard deviation
    double variance = values / N;
    return variance;
}

void compute_Irwin_Hall_dist(int num_values, char filename[]) {
    FILE *fptr;
    fptr = fopen(filename, "w");

    double rand_norm = 0;
    double running_total = 0;
    // test Irwin-Hall distribution
    double data[num_values];
    for (int i = 0; i < num_values; i++) {        
        rand_norm = compute_IH_num();

        data[i] = rand_norm;
        fprintf(fptr, "%.*f\n", DBL_DIG-1,rand_norm);

        running_total += rand_norm;
        rand_norm = 0;
    }

    double final_average = running_total/num_values;
    printf("Final average: %f\n", final_average);
    double final_variance = calculateVariance(num_values, data);
    printf("Final variance: %f\n", final_variance);

    fclose(fptr);
}

double compute_IH_num() {
        double IH_num = 0;

        for (int i = 0; i < 12; i++) {
            IH_num += ( ((double)rand())/ ((double)RAND_MAX));
        }

        IH_num += -6.0; 

        return IH_num;
}

float compute_IH_num_f() {
        float IH_num = 0;

        for (int i = 0; i < 12; i++) {
            IH_num += ( ((float)rand())/ ((float)RAND_MAX));
        }

        IH_num += -6.0; 

        return IH_num;
}

matrix generate_GOE(int size) {
    matrix A = new_matrix(size, size);
    matrix AT = new_matrix(size, size);
    matrix HALF = new_matrix(size, size);
    matrix G = new_matrix(size, size);
    
    // Generate random matrix A and its transpose AT
    double rand_val;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            rand_val = compute_IH_num();
            mget(A, i, j) = rand_val;
            mget(AT, j, i) = rand_val;
        }
    }

    // Generate half matrix (0.5 * I)
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i == j) { mget(HALF, i, j) = 0.5;}
        }
    }

    G = matrix_add(&A, &AT);
    G = matrix_mult(&HALF, &G);   

    return G;
}

double compute_off_diag_mean(const int size, const matrix* A) {
    double off_diag_total = 0;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if(i != j) { off_diag_total += mgetp(A, i, j); }
        }
    }

    double off_mean = off_diag_total / (size * (size - 1));
    return off_mean;
}

double compute_diag_mean(const int size, const matrix* A) {
    double diag_total = 0;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if(i == j) { diag_total += mgetp(A, i, j); }
        }
    }

    double diag_mean;
    diag_mean = diag_total / (double)(size);
    return diag_mean;  
}

double compute_matrix_mean(const int size, const matrix* A) {
    double total = 0;

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            total += mgetp(A, i, j);
        }
    }
    
    return total / (size * size);
}

double compute_off_diag_variance(const int size, const matrix* A) {
    int num_entries = (size * (size - 1)) / 2;
    double off_entries[num_entries];
    int array_tracker = 0;

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if(i < j) { 
                off_entries[array_tracker] = mgetp(A, i, j); 
                array_tracker++;
            }
        }
    }

    return calculateVariance(num_entries, off_entries);
}

double compute_diag_variance(const int size, const matrix* A) {
    double diag_entries[size];
    int array_tracker = 0;

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if(i == j) { 
                diag_entries[array_tracker] = mgetp(A, i, j); 
                array_tracker++;
            }
        }
    }

    return calculateVariance(size, diag_entries);    
}