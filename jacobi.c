#include <stdio.h>
#include <math.h>
#include "mpi.h"

/* This example handles a 12 x 12 mesh, on 4 processors only. */
#define maxn 12

int main( argc, argv )
int argc;
char **argv;
{
    int        rank, value, size, errcnt, toterr;
    int        i_first, i_last;
    MPI_Status status;
    double     diffnorm, gdiffnorm;
    double     xlocal[(12/4)+2][12];  // matrix of 5*12
    double     xnew[(12/4)+2][12];

    MPI_Init( &argc, &argv );

    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    if (size != 4) {
        printf("rank %d", size);
        MPI_Abort( MPI_COMM_WORLD, 1 );
    }
    /* xlocal[][0] is lower ghostpoints, xlocal[][maxn+2] is upper */

    /* Note that top and bottom processes have one less row of interior
       points */
    i_first = 1;
    i_last  = maxn/size;
    if (rank == 0)        i_first++;
    if (rank == size - 1) i_last--;

    /* Fill the data as specified */
    for (int i = 1; i <= maxn/size; i++) {
        for (int j = 0; j < maxn; j++) {
            xlocal[i][j] = rank;
        }
    }
	// The ghost line of process 3 and 1 respectively
    for (int j=0; j < maxn; j++) {
        xlocal[i_first-1][j] = -1;
        xlocal[i_last+1][j] = -1;
    }

    int itcnt = 0;
    do {
        /* Send up unless I'm at the top, then receive from below */
        /* Note the use of xlocal[i] for &xlocal[i][0] */
        if (rank < size - 1)   // size = 4, fixed in this program.
            MPI_Send( xlocal[3], 12, MPI_DOUBLE, rank + 1, 0, 
                MPI_COMM_WORLD );
        if (rank > 0)
            MPI_Recv( xlocal[0], 12, MPI_DOUBLE, rank - 1, 0, 
                MPI_COMM_WORLD, &status );
        /* Send down unless I'm at the bottom */
        if (rank > 0) 
            MPI_Send( xlocal[1], 12, MPI_DOUBLE, rank - 1, 1, 
                MPI_COMM_WORLD );
        if (rank < size - 1) 
            MPI_Recv( xlocal[4], 12, MPI_DOUBLE, rank + 1, 1, 
                MPI_COMM_WORLD, &status );
        
        /* Compute new values (but not on boundary) */
        itcnt ++;
        diffnorm = 0.0;  // diffnorm 残差平方和 or 残差二范数

        for (int i=i_first; i<=i_last; i++) {
            for (int j=1; j<maxn-1; j++) {
                xnew[i][j] = (xlocal[i][j+1] + xlocal[i][j-1] +
                        xlocal[i+1][j] + xlocal[i-1][j]) / 4.0;
                diffnorm += (xnew[i][j] - xlocal[i][j]) * 
                            (xnew[i][j] - xlocal[i][j]);
	    }
    }while (itcnt < 3);

	/* Only transfer the interior points */
	for (int i=i_first; i<=i_last; i++) {
	    for (int j=1; j<maxn-1; j++) {
            xlocal[i][j] = xnew[i][j];
        } 
    }

	MPI_Allreduce( &diffnorm, &gdiffnorm, 1, MPI_DOUBLE, MPI_SUM,
		       MPI_COMM_WORLD );
	gdiffnorm = sqrt( gdiffnorm );
	if (rank == 0) printf( "At iteration %d, diff is %e\n", itcnt, 
			       gdiffnorm );
    } while (gdiffnorm > 1.0e-2 && itcnt < 100);

    MPI_Finalize( );
    return 0;
}