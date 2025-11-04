#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

const int MAX_STRING = 100;

int main() {
    char greeting[MAX_STRING];
    int comm_sz;
    int my_rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if (my_rank != 0) {
        sprintf(greeting, " Hello from process %2i of %2i!", my_rank, comm_sz);
        MPI_Send(greeting, strlen(greeting)+1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
    else {
        printf(" Hello from process %2i of %2i!\n", my_rank, comm_sz);
        for (int j = 1; j < comm_sz; j++) {
            MPI_Recv(greeting, MAX_STRING, MPI_CHAR, j, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%s\n", greeting);
        }   
    }
    
    return 0;
}