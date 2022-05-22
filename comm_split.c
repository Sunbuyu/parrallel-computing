/* 
*@name : comm_split
* @time : 2022-5-15
* @author: SunXimo
* @version : 1.0
* @copyright : GPL
* @description : practice the syntax of MPI_Comm_split. np = 4 applied.
* 
* MPI processes split into two groups depending on whether their rank
* is even.
*
* +----------------+---+---+---+---+
* | MPI processes  | 0 | 1 | 2 | 3 |
* +----------------+---+---+---+---+
* | MPI_COMM_WORLD | X | X | X | X |
* | Subgroup A     | X |   | X |   |
* | Subgroup B     |   | X |   | X |
* +----------------+---+---+---+---+
*
* In subcommunicator A, MPI processes are assigned ranks in the same order as
* their rank in the global communicator.
* In subcommunicator B, MPI processes are assigned ranks in the opposite order
* as their rank in the global communicator.  which means to get a reverse rank.
*/

#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    int myid, numprocs;
    MPI_Init(&argc, &argv);

    MPI_Comm comm;  // to dup a mpi_comm_world for easy typing.
    MPI_Comm_dup(MPI_COMM_WORLD, &comm);

    MPI_Comm_size(comm, &numprocs);

    // Check that 4 processes are used
    if (numprocs != 4)
    {
        printf("Required number of processes: %d, your number of processes: %d\n",
        4, numprocs);
        MPI_Abort(comm, EXIT_FAILURE);
    }

    MPI_Comm_rank(comm, &myid);

    int color, key;
    char marker;  // a special defined tag to diff process. 
    // if the rank of current process is even, then set its color to 1
    // and the key assigned to its original rank.  marker is set to be 'A'
    // You will see new ranks under new communicator will be 0, 1, 2, 3 and subsequing.
    // 新的通讯子下重新从零开始，而排序的依据则是key值的相对大小。大的就排后面。
    // 本例中， 
    // 对于color = 1 的组，原有的进程号是： 0，2，对应的key = 0，2，新通讯子下进程号为：0，1
    // 对于color = 0 的组，原有的进程号是： 1，3 对应的可以 = 3，1，新通讯子下进程号为：1，0
    if (myid % 2 == 0) 
    {
        color = 1;
        key = myid;
        marker = 'A';
    }
    else  // if the rank is odd, then its color will be set to 0
    {
        color = 0;
        key = numprocs - myid;
        marker = 'B';
    }
    // split the global communicator
    MPI_Comm new_comm;
    MPI_Comm_split(comm, color, key, &new_comm);

    // Get my rank in the new communicator
    int my_new_comm_rank;
    MPI_Comm_rank(new_comm, &my_new_comm_rank);

    // Print my new communicator and process rank in the new communicator
    printf("[MPI process %d] I am now MPI process %d in subcommunicator %c.\n", 
    myid, my_new_comm_rank, marker );
    MPI_Finalize();

    printf("This program is finished!");
    return 0;
}