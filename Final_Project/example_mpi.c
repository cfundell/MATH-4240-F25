#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* =========================
   YOUR EXACT MATRIX DEFINITION
   ========================= */

typedef struct matrix matrix;
struct matrix
{
    int rows;
    int cols;
    double* val;
};

matrix new_matrix(const int rows, const int cols)
{
    matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    assert(rows > 0);
    assert(cols > 0);
    mat.val = (double*)malloc(sizeof(double) * rows * cols);

    for (int i = 0; i < (rows * cols); i++) {
        mat.val[i] = 0.0;
    }

    return mat;
}

/* =========================
   MPI DATATYPE FOR HEADER ONLY
   (rows, cols)
   ========================= */
void create_MPI_matrix_header(MPI_Datatype *MPI_MATRIX)
{
    int blocklengths[2];
    MPI_Aint displacements[2];
    MPI_Datatype types[2];

    blocklengths[0] = 1;   // rows
    blocklengths[1] = 1;   // cols

    types[0] = MPI_INT;
    types[1] = MPI_INT;

    matrix temp;
    MPI_Aint base;

    MPI_Get_address(&temp, &base);
    MPI_Get_address(&temp.rows, &displacements[0]);
    MPI_Get_address(&temp.cols, &displacements[1]);

    displacements[0] -= base;
    displacements[1] -= base;

    MPI_Type_create_struct(2, blocklengths, displacements, types, MPI_MATRIX);
    MPI_Type_commit(MPI_MATRIX);
}

/* =========================
   FILL MATRIX FOR TESTING
   ========================= */
void fill_matrix(matrix *A)
{
    for (int i = 0; i < A->rows * A->cols; i++)
        A->val[i] = (double)(i + 1);
}

/* =========================
   PRINT MATRIX
   ========================= */
void print_matrix(const matrix *A)
{
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            printf("%6.2f ", A->val[i * A->cols + j]);
        }
        printf("\n");
    }
}

/* =========================
   MAIN PROGRAM
   ========================= */
int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        if (rank == 0)
            printf("Run with exactly 2 processes.\n");
        MPI_Finalize();
        return 0;
    }

    MPI_Datatype MPI_MATRIX;
    create_MPI_matrix_header(&MPI_MATRIX);

    matrix A;

    if (rank == 0) {
        /* ---------- SENDER ---------- */

        A = new_matrix(3, 4);   // uses YOUR allocator
        fill_matrix(&A);

        printf("\nRank 0 sending matrix:\n");
        print_matrix(&A);

        /* Send header (rows, cols) */
        MPI_Send(&A, 1, MPI_MATRIX, 1, 0, MPI_COMM_WORLD);

        /* Send the actual matrix data */
        MPI_Send(A.val, A.rows * A.cols, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD);

        free(A.val);
    }
    else if (rank == 1) {
        /* ---------- RECEIVER ---------- */

        /* Receive header */
        MPI_Recv(&A, 1, MPI_MATRIX, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        /* Allocate using YOUR constructor */
        A = new_matrix(A.rows, A.cols);

        /* Receive data */
        MPI_Recv(A.val, A.rows * A.cols, MPI_DOUBLE,
                 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("\nRank 1 received matrix:\n");
        print_matrix(&A);

        free(A.val);
    }

    MPI_Type_free(&MPI_MATRIX);
    MPI_Finalize();
    return 0;
}
