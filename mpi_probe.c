/*
* @Name: send_recv
* @Time : 2022-05
* @Author : SunMozhi
* @Version : 1.0
* @Copyright : GPL
* @Description : This program uses 4 processes to perform a value pass. The 
* value of my_gem is passed from process 0 to 1, from 1 to 2, from 2 to 3, and
* from 3 to 0. We are going to test  MPI_Probe.
* MPI_Probe feeds back programmer with the  st with mpi_Probe.
*/

#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char **argv)
{
    int myid, numprocs;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    if (numprocs != 4)
    {
        printf("Processes required: %d\n Process invoked: %d", 4, numprocs);
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    int my_gem = myid;
    MPI_Status st, st1;

    if (myid == 0) {
        // MPI_Send(&my_gem, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        // MPI_Recv(&my_gem, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, &st);
        MPI_Sendrecv(&my_gem, 1, MPI_INT, 1, 0, &my_gem, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, &st);

        printf("My rank is %d, value of my_gem is %d.\n", myid, my_gem);
    }
    if (myid == 1) {
        MPI_Sendrecv(&my_gem, 1, MPI_INT, 2, 0, &my_gem, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
        // MPI_Recv(&my_gem, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
        printf("My rank is %d, value of my_gem is %d.\n", myid, my_gem);
    }
    if (myid == 2) {
        MPI_Sendrecv(&my_gem, 1, MPI_INT, 3, 0, &my_gem, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &st);

        printf("My rank is %d, value of my_gem is %d.\n", myid, my_gem);
    }
    if (myid == 3) {
        // MPI_Send(&my_gem, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        // MPI_Recv(&my_gem, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &st);
        // Use MPI_Probe to see how  
        MPI_Probe(2, 0, MPI_COMM_WORLD, &st1);
        if (st1.MPI_SOURCE == 2)

        { 

            MPI_Sendrecv(&my_gem, 1, MPI_INT, 0, 0, &my_gem, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &st);
    
            printf("My rank is %d, value of my_gem is %d.\n", myid, my_gem);

        }
    }

    MPI_Finalize();
    if (myid == 0){
        printf("All is well.\n");
    }
    return EXIT_SUCCESS;
    
}