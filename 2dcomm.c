#include <stdio.h>
#include "mpi.h"



int main(int argc, char **argv)
{
    int myrank, np;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    // Duplicate mpi_comm_world to comm for breivity.
    MPI_Comm comm;
    MPI_Comm_dup(MPI_COMM_WORLD, &comm);

    // Row communicator and column communicator
    MPI_Comm rowcomm, colcomm;

    int color, key;

    int errorcode;

    int const row = 2, col = 3; // 2 rows and 2 columns.

    // Make sure enough np numbers provided.
    if (np < row*col)
    {
        printf("np required: %d, np asked: %d\n", row*col, np);
        MPI_Abort(comm, errorcode);
    }

    // 通过取相同商值作为同一行
    // Get row comm suborganized by color of quotient by process's rank to col.
    else  
    {
        if (myrank < row*col)
        {
            color = (int) (myrank / col);
        }
        else
        {
            color = MPI_UNDEFINED;
        }
    }
    key = myrank;
    MPI_Comm_split(comm, color, key, &rowcomm);

    // 通过mod运算得到的余数相同作为同一列。
    // Column tag by color assighning to mod by col.
    if (myrank < row*col)
    {
        color = myrank % col;
    }
    else
    {
        color = MPI_UNDEFINED;
    }
    key = myrank;
    MPI_Comm_split(comm, color, key, &colcomm);

    int myrow, mycol;
    if (myrank < row*col)
    {
        // 相同的商，同一行，新的编号按照原有的myrank编号的话，通过key编号得到的是列的数字。
        // 也就是 行的通信子里按原有大小编号得到的是列的数字。 反之则反。
        // In each rowcomm, if original rank values used as key to rowcomm, new
        // ranks in a rowcomm will be the logical column of new "ghost" 2d communicator. 
        MPI_Comm_rank(rowcomm, &mycol);
        MPI_Comm_rank(colcomm, &myrow);  
        // for (int i = 0; i < np; i++)
        // {
            printf("myrank is : %d, and my 2d rank is %d, %d\n", myrank, myrow, mycol);
        // }
    }

    // 分区装载矩阵的数值到上述不同的进程上去，本次算例是2*3的矩阵。
    // Split A and x to different blocks and assign them to different proccesses. 
    if (myrow == 0 && mycol == 0)
    {
        printf("I am 0,0");
    }
    if (myrank == 0)
    {
        printf("I am 0,0");
    }

    MPI_Finalize();

    return 0;
}