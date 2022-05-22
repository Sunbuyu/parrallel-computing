#include <stdio.h>
#include <mpi.h>

// int main(int argc, char **argv) {
    // MPI_Init(int *argc, char **argv);
// 
// }
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv ) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    int buffer = 0;
    if (rank == 0) {
        // printf("Hello world!\n");
        // MPI_Send(&i, 1, MPI_INT , 3, 1, MPI_COMM_WORLD);
        printf("I am %i before send ping\n", rank);
        MPI_Send(&buffer, 1, MPI_INT , 1, 0, MPI_COMM_WORLD);
    }
    else if (rank == 1) {
        MPI_Recv(&buffer, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("I am %i after recv ping \n", rank);
    }

    printf("I am %i \n", rank);
    // MPI_Recv(&i, 1, MPI_INT , 0, 1, MPI_COMM_WORLD, &status);



    MPI_Finalize();
}



