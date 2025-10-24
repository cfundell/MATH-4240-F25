#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "matrix.h"

vector compute_w_fine(const int N, const int K, const int thread_count);
vector compute_w_coarse(const int N, const int K, const int thread_count);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <thread_count> <N>\n", argv[0]);
        return 1;
    }
    int thread_count = atoi(argv[1]);
    int N = atoi(argv[2]);
    int K = 400;

#ifdef _OPENMP
    printf("OpenMP enabled (version %d)\n", _OPENMP);
#else
    printf("OpenMP NOT enabled — compile with -fopenmp!\n");
#endif

    double fine_start = omp_get_wtime();
    vector w = compute_w_fine(N, K, thread_count);
    double fine_end = omp_get_wtime();

    double coarse_start = omp_get_wtime();
    vector w_coarse = compute_w_coarse(N, K, thread_count);
    double coarse_end = omp_get_wtime();

    printf("Results for fine-grained parallelism:\n");
    printf("w(1) = %f, w(N) = %f\n", vget(w, 1), vget(w, N));
    printf("%d threads, time = %.5f s\n", thread_count, fine_end - fine_start);
    printf("\n");
    printf("Results for coarse-grained parallelism:\n");
    printf("w(1) = %f, w(N) = %f\n", vget(w_coarse, 1), vget(w_coarse, N));
    printf("%d threads, time = %.5f s\n", thread_count, coarse_end - coarse_start);

    delete_vector(&w);
    delete_vector(&w_coarse);
    return 0;
}

vector compute_w_fine(const int N, const int K, const int thread_count) {
    vector w = new_vector(N);

    #pragma omp parallel for num_threads(thread_count) schedule(static)
    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= K; k++) {
            vget(w, n) += (1.0 / (n + k - 1)) * (1.0 / k);
        }
    }

    return w;
}

vector compute_w_coarse(const int N, const int K, const int thread_count) {
    vector v = new_vector(N);

#   pragma omp parallel num_threads(thread_count) 
    {
        int my_rank = omp_get_thread_num();
        int local_N = N / thread_count;
        int start = my_rank * local_N + 1;
        int end = (my_rank == thread_count - 1) ? N : (start + local_N - 1);

        #pragma omp for schedule(static)
        for (int n = 1; n <= N; n++) {
            for (int k = 1; k <= K; k++) {
                vget(v, n) += (1.0 / (n + k - 1)) * (1.0 / k);
            }
        }
    }
    
    return v;
}

void usage(const char *prog_name) { 
    fprintf(stderr, "usage: %s <thread_count> <num_intervals>\n", prog_name); 
    fprintf(stderr, " thread_count should be positive\n"); 
    fprintf(stderr, " num_intervals should be positive\n"); 
    fprintf(stderr, " mod(num_intervals, thread_count) should be 0\n"); 
    exit(1); 
}

