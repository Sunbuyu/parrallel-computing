program jacobi
    use mpi
    implicit none
    !> global array size
    integer, parameter :: total_size = 16
    integer, parameter :: mysize = total_size/4 , steps = 10
    
    !> local array size
    integer :: n, myid, numprocs, i, j, rc
    real :: a(total_size, mysize+2), b(total_size, mysize+2)
    integer :: begin_col, end_col, ierr
    integer :: status(MPI_STATUS_SIZE)

    call MPI_Init(ierr)
    call MPI_Comm_rank(MPI_COMM_WORLD, myid, ierr)
    call MPI_comm_size(MPI_COMM_WORLD, numprocs, ierr)
    write(*,*) "Process", myid, "of", numprocs, "is alive"

    


    call MPI_Finalize(rc)



end program jacobi