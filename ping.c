#include <stdio.h>
#include <mpi.h>

int main()
{
    int rank;
    float buffer[1];
    MPI_Status status;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
      printf("I am %i before send ping \n", rank);
      MPI_Send(buffer, 1, MPI_FLOAT, 1, 17, MPI_COMM_WORLD);
    }
    else if (rank == 1)
    {
      MPI_Recv(buffer, 1, MPI_FLOAT, 0, 17, MPI_COMM_WORLD, &status);
      printf("I am %i after  recv ping \n", rank);
    }


    MPI_Finalize();
}