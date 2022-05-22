// -------------------------------------------------------------------------  //
// Name:        pi
// Author:      SunXimo
// Version:     v1.0
// Copyright:   GPL
// Description: This program uses mpi to calculate the value of pi with 4
//              processes with finite integrate.
// -------------------------------------------------------------------------  //

#include "mpi.h"
#include <stdio.h>

// double f(double x)
// {
    // double result;
    // result = 4 / (1 + x * x);
    // return result;
// }

double f(double x_i, int num_of_rectangle)
{
    return (4 / (1.0 + x_i * x_i) / ((double)num_of_rectangle));
}

int main(int argc, char **argv)
{
    int n = 100;  // n is numbers of rectangles between 0 and 1.
    double dx = 1.0/ ((double)n);
    int myid, numprocs;
    double pi_sum = 0;
    double x_i = 0;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    double pi_part = 0;

    for (int i = myid +1; i <= n; i += numprocs)
    {
        x_i =  dx * ((double)(i) - 0.5);
        pi_part +=  f(x_i, n);
    }

    // use mpi reduce to pass pi_part values of all processes to pi_sum variable 
    // of root process 0. 
    //   
    MPI_Reduce(&pi_part, &pi_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);    

    if (myid == 0)
    {
        printf("The result of pi is %f\n", pi_sum);
    }

    // to show every process possesses all the variables.
    // e.g. Every process owns a copy of all the varibales, whether it is defined
    // before the MPI_Init() or not.
    // 每一个进程都会在自己的进程重新copy一份变量，类似于c++的命名空间,而且和变量是否定义在
    // MPI_Init() 函数的前后没有关系。就相当于每一个进程都会相同的跑一遍所有的语句。这个
    // main被同时执行了np个，这样每一个变量都会在每一进程里出现就很容易理解了。。
    // 举例：x_i如果是np=4，那么就会同时执行4个进程，每个进程里都会有x_i的变量。
    if (myid == 1)
    {
        printf("pi_sum of rank %dth is %f\n", myid, pi_sum);
    }

    MPI_Finalize();

}