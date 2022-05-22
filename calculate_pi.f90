program computing_pi
    ! The header file for using MPI parallel environment,
    ! which must be included for all mpi programs.
    include 'mpif.h'
    ! Variables declaration
    integer iam, np, comm, ierr
    integer n, i, num, is, ie
    real*8 pi, h, eps, xi, s
    ! Enroll in MPI environment and get the MPI parameters
    call mpi_init(ierr)
    call mpi_comm_dup(mpi_comm_world, comm, ierr)
    call mpi_comm_rank(comm, iam, ierr)
    call mpi_comm_size(comm, np, ierr)
    ! Read the number of digits you want for value of Pi.
    if(iam .eq. 0) then
    ! write(*, *) 'Number of digits(1-16)= ' 
    write(*, *) iam
    read(*, *) num
    endif
    call mpi_bcast(num,1,mpi_integer,0,comm,ierr)
    eps = 1
    do 10 i=1, num
    eps = eps * 0.1
    10 continue
    n = sqrt(4.0/(3.0*eps))
    h = 1.0/n
    num = n/np
    if(iam .eq. 0) then
    s = 3.0
    xi = 0
    is = 0
    ie = num
    elseif(iam .eq. np-1) then
    s = 0.0
    is = iam*num
    ie = n - 1
    xi = is * h
    else
    s = 0.0
    is = iam*num
    ie = is + num
    xi = is * h
    endif
    if(np .eq. 1) ie = ie - 1
    do 20 i=is+1, ie
    xi = xi + h
    s = s + 4.0/(1.0+xi*xi)
    20 continue
    call mpi_reduce(s, pi, 1, mpi_double_precision,mpi_sum, 0, comm, ierr)
    if(iam .eq. 0) then
    write(*, 99) pi
    endif
    call mpi_finalize(ierr)
    99 format('The pi= ',f16.13)
    end