#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h> 
#include <assert.h>
#include <math.h>
#include <float.h>
#include "matrix.h"
#include "random_mat.h"
#include <mpi.h>

void get_input(int argc, char* argv[], const int my_rank, const int comm_sz, int* N);
void create_MPI_matrix_header_type(MPI_Datatype *MPI_MATRIX);

int main(int argc, char* argv[]) {
    // Setup MPI
    int comm_sz, my_rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // Ensure that each process has a different random seed
    unsigned int current_time = (unsigned int)time(NULL);
    srand(current_time + my_rank);

    // Create MPI_MATRIX datatype on each rank
    MPI_Datatype MPI_MATRIX;
    create_MPI_matrix_header(&MPI_MATRIX);

    // Get start time 
    double time_start;
    if (my_rank == 0) {
        time_start = MPI_Wtime();
    }

    // Grab the global N parameter 
    // and set the local N.
    // First rank will get extra work if N not equally divisible
    int N; 
    get_input(argc, argv, my_rank, comm_sz, &N);
    int N_local;
    if (my_rank == 0) {
        N_local = N/comm_sz + N % comm_sz;
    }
    else {
        N_local = N/comm_sz;
    }

    // Create partial matrix on current processor
    matrix A_local = new_matrix(N_local, N);
    double rand_val;
    for (int i = 1; i <= N_local; i++) {
        for (int j = 1; j <= N; j++) {
            rand_val = compute_IH_num() * 0.5;
            mget(A_local, i, j) = rand_val;
        }
    }

    matrix A_total;
    matrix AT_total;
    // Send and recieve data
    if (my_rank != 0) {
        // Send header (rows, cols) 
        MPI_Send(&A_local, 1, MPI_MATRIX, 0, 0, MPI_COMM_WORLD);

        // Send the actual matrix data 
        MPI_Send(A_local.val, A_local.rows * A_local.cols, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);

        free(A_local.val);
    }
    else {
        // Rank 0 recieves matrix data and creates A and AT //
        
        A_total = new_matrix(N, N);
        // Add matrix data from Rank 0
        // The "matrix_add_rows" function allows addition of a rectangular matrix into a square matrix,
        // given that the number of columns in each matrix is the same
        A_total = matrix_add_rows(&A_total, &A_local, 1, (N_local));

        for (int rank_num = 1; rank_num < comm_sz; rank_num++) {
            matrix A;
            // Receive header 
            MPI_Recv(&A, 1, MPI_MATRIX, rank_num, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            // Allocate space to recieve A
            A = new_matrix(A.rows, A.cols);

            // Recieve matrix data from rank 'rank_num'
            MPI_Recv(A.val, A.rows * A.cols, MPI_DOUBLE,
                    rank_num, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            // Add into total matrix
            int starting_row = (N_local + 1) + ((rank_num - 1) * (N/comm_sz));
            int num_rows = N/comm_sz;
            A_total = matrix_add_rows(&A_total, &A, starting_row, num_rows);

            free(A.val);
        }

        // Create transpose of A on rank 0, should be relatively quick process
        AT_total = new_matrix(N, N);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                mget(AT_total, j, i) = mget(A_total, i, j);
            }
        }
    }
    
    MPI_Barrier(MPI_COMM_WORLD);
    
    if (my_rank == 0) {
        // print_matrix(&A_total);
        // printf("\n");
        // print_matrix(&AT_total);
        // printf("\n");
        // print_matrix(&G);
    }

    double time_end;
    double total_W_time;
    if (my_rank == 0) {
        time_end = MPI_Wtime();
        total_W_time = time_end - time_start;
        printf("\nMatrix size: %i\n", N);
        printf("Number of processes: %i\n", comm_sz);
        printf("\nTotal wall time: %f\n\n", total_W_time);
    }

    MPI_Type_free(&MPI_MATRIX);
    MPI_Finalize();
    return 0;
}

void get_input(int argc, char* argv[], const int my_rank, const int comm_sz, int* N) {
    if (my_rank==0) {

        *N = strtol(argv[1], NULL, 10);

        for (int i=1; i < comm_sz; i++) {
            MPI_Send(N, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    }
    else {
        MPI_Recv(N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
}

void create_MPI_matrix_header_type(MPI_Datatype *MPI_MATRIX)
{
    int blocklengths[2] = {1, 1};
    MPI_Aint displacements[2];
    MPI_Datatype types[2] = {MPI_INT, MPI_INT};

    displacements[0] = offsetof(matrix, rows);
    displacements[1] = offsetof(matrix, cols);

    MPI_Type_create_struct(2, blocklengths, displacements, types, MPI_MATRIX);
    MPI_Type_commit(MPI_MATRIX);
}
