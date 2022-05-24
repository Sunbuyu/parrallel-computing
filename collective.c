/* ******************************************************
* Description : practice collective functions.
* MPI_Barrier  MPI_Bcast MPI_Gather MPI_Scatter MPI_Alltoall
* 练习使用mpi的聚合通信函数，上述的五个。
*/

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int np = 0, myid = 0;
    MPI_Comm comm;
    MPI_Comm_dup(MPI_COMM_WORLD, &comm);
    MPI_Comm_rank(comm, &myid);
    MPI_Comm_size(comm, &np);

    // 整一个循环多算点时间，每个进程间的时间差就会更大了。这样barrier的效果更明显。
    int temp = 1;
    for (int i = 0; i < 100000*myid; i++)
    {
        temp += pow(i,2.0);
    }
    printf("I am %d, and my number is :%d, I am waiting.\n", myid, temp);

    // Test MPI_Barrier
    MPI_Barrier(comm);
    printf("Stop waiting.\n");

    // Test MPI_Bcast. Broadcast the value of process 0 to all processes.
    // 把根进程0的temp值广播到所有的进程
    MPI_Bcast(&temp, 1, MPI_INT, 0, comm);
    printf("After broadcasting, I am %d, and my temp is : %d\n", myid, temp);

    // 设置根进程为0从每个进程里头收集一个数也就是temp的值
    // Test MPI_gather. Gather value of temp from all processes to process 0
    // which means the recvcount equals 1.
    int gather_num[np];  // a array to recv values.
    MPI_Gather(&temp, 1, MPI_INT, &gather_num, 1, MPI_INT, 0, comm);
    // 测试是否成功，通过看进程0的对应的值。
    // Test if gather function successfully conducted.
    if (myid == 0)
    {
        for (int i = 0; i < np; i++)
        {
            printf("gather_num[%d] is %d\n", i, gather_num[i]);
        }
    }

    // Test MPI_Scatter. The reverse operation of MPI_Gather.
    // 测试 MPI_Scatter。这玩意是 MPI_Gather 的逆操作。逻辑是完全一样的。
    // 把gather_num的数全部改成2，后面再散播出去。
    if (myid == 0)
    {
        for (int i = 0; i < np; i++)
        {
            gather_num[i] = 2;
        }
    }
    MPI_Scatter(&gather_num, 1, MPI_INT, &temp, 1, MPI_INT, 0, comm);

    printf("I am %d, and my temp is %d\n", myid, temp);

    




    // 测试 MPI_Finalize 的返回值。成功就结束。
    // Test MPI_Finalize ;
    if (MPI_Finalize() == MPI_SUCCESS)
    {
        printf("All is well!\n");
    }

    return 0;
}