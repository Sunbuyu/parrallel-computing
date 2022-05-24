# MPI_Comm_split()函数
首先我们看一下函数的mannual。
如果已经通过终端装好了openmpi，那么直接输入`man MPI_Comm_split`就会出现相应的手册页。
```shell
Fortran 2008 Syntax
       USE mpi_f08
       MPI_Comm_split(comm, color, key, newcomm, ierror)
            TYPE(MPI_Comm), INTENT(IN) :: comm
            INTEGER, INTENT(IN) :: color, key
            TYPE(MPI_Comm), INTENT(OUT) :: newcomm
            INTEGER, OPTIONAL, INTENT(OUT) :: ierror
INPUT PARAMETERS
       comm      Communicator (handle).

       color     Control of subset assignment (nonnegative integer).

       key       Control of rank assignment (integer).


OUTPUT PARAMETERS
       newcomm   New communicator (handle).

       IERROR    Fortran only: Error status (integer).  
DESCRIPTION
       This function partitions the group associated with comm into disjoint subgroups, one for each value of color. Each subgroup contains all processes of the same color. Within each subgroup, the processes are ranked in the order defined by the value
       of the argument key, with ties broken according to their rank in the old group. A new communicator is created for each subgroup and returned in newcomm. A process may supply the color value MPI_UNDEFINED, in which case newcomm returns
       MPI_COMM_NULL. This is a collective call, but each process is permitted to provide different values for color and key.

       When you call MPI_Comm_split on an inter-communicator, the processes on the left with the same color as those on the right combine to create a new inter-communicator.  The key argument describes the relative rank of processes on each side of the
       inter-communicator.  The function returns MPI_COMM_NULL for  those colors that are specified on only one side of the inter-communicator, or for those that specify MPI_UNDEFINED as the color.

       A call to MPI_Comm_create(comm, group, newcomm) is equivalent to a call to MPI_Comm_split(comm, color, key, newcomm), where all members of group provide color = 0 and key = rank in group, and all processes that are not members of group provide
       color = MPI_UNDEFINED. The function MPI_Comm_split allows more general partitioning of a group into one or more subgroups with optional reordering.

       The value of color must be nonnegative or MPI_UNDEFINED.          
```
函数根据color的值来分组，把具有相同color值的进程分到同一个通信域里头，而新的通信域里头的进程
rank的编号则是重新从零开始，那么它们的相对大小就是靠每个进程具有的key值来决定大小顺序的。
一般来说，如果想照着从小到大的顺序来安排新的进程编号的话，只用将key值设置等于myid就可以了。

