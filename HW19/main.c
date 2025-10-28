#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include "matrix.h"

void norm_fine(vector v, const int N, const int thread_count);
void norm_coarse(vector v, const int N, const int thread_count);

int main(int argc, char* argv[]) {
    // setup file writing for later
    FILE *fptr;
    fptr = fopen("output.txt", "w");

    // usage checks & declarations
    if (argc != 3) {
        fprintf(stderr, "usage: %s <thread_count> <N>\n", argv[0]);
        return 1;
    }
    int thread_count = atoi(argv[1]);
    int N = atoi(argv[2]);

    // check is OPENMP is properly enabled
#ifdef _OPENMP
    printf("OpenMP enabled (version %d)\n", _OPENMP);
#else
    printf("OpenMP NOT enabled — compile with -fopenmp!\n");
#endif

    vector v1 = new_vector(N); 
    vector v2 = new_vector(N);

    // define v1 and v2 (same vector created twice in order to compare fine and coarse)
    for (int i = 1; i <= N; i++) {
        vget(v1, i) = 1.0;
        vget(v2, i) = 1.0;
    }

    fprintf(fptr, "Number of threads: %i\n", thread_count);
    fprintf(fptr, "Initial vector (uniform values)\n");
    fprintf(fptr, "Size (N) = %i\nv[i] = %lf\n\n", N, vget(v1, 1));

    // compute second norms for v1 (fine) and v2 (coarse)
    double fine_start = omp_get_wtime();
    norm_fine(v1, N, thread_count);
    double fine_end = omp_get_wtime();
    double fine_time = fine_end - fine_start;

    double coarse_start = omp_get_wtime();
    norm_coarse(v2, N, thread_count);
    double coarse_end = omp_get_wtime();
    double coarse_time = coarse_end - coarse_start;

    // print results
    fprintf(fptr, "Results for fine-grained:\n");
    fprintf(fptr, "v[i] = %lf\n", vget(v1, 1));
    fprintf(fptr, "Total wall time: %lf\n\n", fine_time);

    fprintf(fptr, "Results for coarse-grained:\n");
    fprintf(fptr, "v[i] = %lf\n", vget(v1, 1));
    fprintf(fptr, "Total wall time: %lf\n", coarse_time);    

    fclose(fptr);    

    printf("Results printed to 'output.txt'\n");
    return 0;
}

void norm_fine(vector v, const int N, const int thread_count) {
    double norm = 0.0;

#   pragma omp parallel num_threads(thread_count)
    {    
#       pragma omp parallel for reduction(+:norm)
        for (int i = 1; i <= N; i++) {
            norm += pow(fabs(vget(v, i)), 2);
        }    

#       pragma omp single
        norm = pow(norm, 0.5);        

#       pragma omp for
        for (int i = 1; i <= N; i++) {
            vget(v, i) = vget(v, i) / norm;
        }        
    }
}

void norm_coarse(vector v, const int N, const int thread_count) {
    double norm = 0.0;

#   pragma omp parallel num_threads(thread_count) 
    {
        const int my_rank = omp_get_thread_num();

        const int N_per_thread = N / thread_count;
        const int istart = my_rank * N_per_thread + 1;
        const int iend = (my_rank + 1) * (N_per_thread);

        double norm_thread = 0.0;
        for (int i = istart; i <= iend; i++) {
            norm_thread += pow(fabs(vget(v,i)), 2);
        }

#       pragma omp critical 
        norm += norm_thread;

#       pragma omp barrier

#       pragma omp single
        norm = pow(norm, 0.5);

        for (int i = istart; i <= iend; i++) {
            vget(v, i) = vget(v, i) / norm;
        }
    }
}

void usage(const char *prog_name) { 
    fprintf(stderr, "usage: %s <thread_count> <num_intervals>\n", prog_name); 
    fprintf(stderr, " thread_count should be positive\n"); 
    fprintf(stderr, " num_intervals should be positive\n"); 
    fprintf(stderr, " mod(num_intervals, thread_count) should be 0\n"); 
    exit(1); 
}
