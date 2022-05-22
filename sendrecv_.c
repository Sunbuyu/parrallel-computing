/*
* @Name: send_recv
* @Time : 2022-05
* @Author : SunMozhi
* @Version : 3.0
* @Copyright : GPL
* @Description : This program uses 4 processes to perform a value pass. The 
* value of my_gem is passed from process 0 to 1, from 1 to 2, from 2 to 3, and
* from 3 to 0. Instead of using send and recv function, sendrecv function is 
* utilized this time. 
* Utilization of sendrecv function could avoid dead lock, which pretends to 
* appear when send and recv used.
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
    MPI_Status st;

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
        MPI_Sendrecv(&my_gem, 1, MPI_INT, 0, 0, &my_gem, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &st);

        printf("My rank is %d, value of my_gem is %d.\n", myid, my_gem);
    }

    MPI_Finalize();
    if (myid == 0){
        printf("All is well.\n");
    }
    return EXIT_SUCCESS;
    
}