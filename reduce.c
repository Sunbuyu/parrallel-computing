
#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main (int argc, char **argv) {
    // #define reduce
    // /* start the mpi environment */
    // int iam, size;

    // MPI_Init(&argc, &argcv);
    
    // MPI_Comm_rank(MPI_COMM_WORLD, &iam);
    // MPI_Comm_size(MPI_COMM_WORLD, &size);
    // #ifdef reduce
    // float a[2], b[2];
    // int root = 1;

    // a[0] = 10.0 + iam;
    // MPI_Reduce(a, b, 1, MPI_DOUBLE, MPI_MAX, root, MPI_COMM_WORLD);
    // if (iam = root) {
    //     printf("The max value = %f \n", b[0]);
    // }
    // #endif
    // 测试变量在init前面定义和后面定义有什么不同。
    int iam, size;
    int numsum, maxnum;
    // int number = 1;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &iam);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int number = 1;  // 实测把number的定义和赋值放到init后面和前面没有不同
    int num2 = iam;
    MPI_Reduce(&number, &numsum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD );

    if (iam == 0) {
        printf("The sum of all numbers is %d  \n", numsum);
    }

    MPI_Reduce(&num2, &maxnum, 1, MPI_INT, MPI_MAX, 1, MPI_COMM_WORLD);
    if (iam == 1)
    {
        printf("The max number of all members is %d\n", maxnum);
    }


    MPI_Finalize();
}