#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {

    // initialize MPI
    MPI_Init(&argc, &argv);

    // get process number and rank of current process
    int size = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int myid = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    MPI_Status status;  // status for recv

    int buffer = 0;  // sending buffer

    // int count = 6;  // ping-pong times counted

    if ( myid == 0) {
        for (int count = 0; count < 6; count++) {
            // buffer = count;
            printf("I am %i before send ping, value is %i \n", myid, buffer);
            MPI_Send(&buffer, 1, MPI_INT , 1, 0, MPI_COMM_WORLD);
            buffer = 0;
            MPI_Recv(&buffer, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
            printf("I am %i after recieve pong, value is %i \n", myid, buffer);
        } 
    }

    else if ( myid == 1) {
        for (int count = 0; count < 6; count++) {
            MPI_Recv(&buffer, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

            buffer =  2;

            MPI_Send(&buffer, 1, MPI_INT , 0, 0, MPI_COMM_WORLD);

        } 
    }


    // finalize MPI
    MPI_Finalize();
    return 0;
}