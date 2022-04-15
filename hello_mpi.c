// #include <stdio.h>
// #include <mpi.h>
// 
// int main(int argc, char **argv) {
    // MPI_Init(int *argc, char **argv);
// 
// }
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int rank, size;
    // MPI_Init(NULL, NULL);
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        printf("Hello world!\n");
    }
    printf("I am process %i out of %i.\n", rank, size);
    MPI_Finalize();
}