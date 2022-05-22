
program jacobi
    ! use mpi
    include 'mpi.f'
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

    !> initialize array
    do j = 1, mysize + 2
        do i = 1, total_size
            a(i,j) = 0
        end do
    end do

    if (myid == 0) then
        do i = 1, total_size
            a(i, 2) = 8.0
        end do
    end if

    if (myid == 3) then
        do i = 1, total_size
            a(i, mysize+1) = 8.0
        end do
    end if
    
    do i = 1, mysize + 2
        a(1,i) = 8.0
        a(total_size, i) = 8.0
    end do

    !> ------ Jacobian iteration -----------------
    do n = 1, steps
        !> receive data from right neighbor
        if (myid < 3) then
            call MPI_Recv(a(1, mysize + 2), total_size, MPI_real, myid+1, 10, MPI_COMM_WORLD, status, ierr)
        end if

        !> send data to left ø
        if (myid > 0) then
            call MPI_Send(a(1, 2), total_size, MPI_real, myid-1, 10, MPI_COMM_WORLD, ierr)
        end if

        !> send data to right neighbor
        if (myid < 3) then
            call MPI_Send(a(1, 2), total_size, MPI_real, myid-1, 10, MPI_COMM_WORLD, ierr)
        end if

        !> receive data from left neighbor
        if (myid > 0) then
            call MPI_Recv(a(1, 1), total_size, MPI_real, myid-1, 10, MPI_COMM_WORLD, status, ierr)
        end if





        


    call MPI_Finalize(rc)



end program jacobi



