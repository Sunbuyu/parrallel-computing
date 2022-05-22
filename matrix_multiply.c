// -------------------------------------------------------------------------  //
// Name: matrix_multiply
// Author: SunMozhi
// Version: v1.0
// Copyright: GPL
// Description: This program muliplies a matrix A with a v ector x, mpi
//              implementation used. 
//              for v1.0, np = 3 is used.
// -------------------------------------------------------------------------  //

#include "mpi.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int myid, numprocs;  // rank of processes and total number of processes

    int row = 3;
    int col = 4;
    // double a[row][col];  // matrix a
    double a[3][4] = {{1,1,1,1}, {2,2,2,2}, {3,3,3,3}};

    double x[3] = {1,2,3};  // x

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    double a_part[col];  // every col of a in each process
    // for (int i = 0; i <= numprocs; )
    for (int i = 0; i < col; i++)
    {
        a_part[i] = a[i][myid];
    }

    double b[3] = {5,5,5};
    // b[col][1] = {5,5,5,5};
    double sum_part[3] = {0};
    double sum[3] = {0};
    // sum_part[col][0] = {0};
    for (int i = 0; i < row; i++)
    {
        sum_part[i] = a_part[i] * x[i] + b[i];  
    }

    MPI_Reduce(&sum_part + myid, &sum + myid, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid == 0)
    {
        printf("The sum result of matrix y = a*x + b is :");
        for (int i = 0; i < row; i++)
        {
            printf("%f ", sum[i]);
        }
    }

    MPI_Finalize();


}