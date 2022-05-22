// -------------------------------------------------------------------------- //
//  Name        :  finite_integrate
//  Author      :  sunjun
//  Version     :  v1.0
//  Copyright   :  GPL
//  Description :  This program calculates a finite integrate using mpi module 
//                 to get value of pi.
// -------------------------------------------------------------------------- //

#include "mpi.h"
#include <stdio.h>

int main(int argc, char **argv) 
{
    int myid;  // the id rank in the communicator of current proccess
    int numprocs;  // number of processes
    
    MPI_Init(&argc, &argv);  // MPI initialization

    // get the number of processes via calling MPI_Comm_size 
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    // get the current process rank/id
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    printf("Process %dth of %d\n", myid, numprocs);



    MPI_Finalize();

    
}
