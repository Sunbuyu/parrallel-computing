program recv
    use mpi
    
    integer ( kind = 4 ) error
    integer ( kind = 4 ) rank
    integer :: number_amount, MAX_NUMBERS
    real :: r
    integer, allocatable :: numbers(:), number_buf(:)
    integer :: status(MPI_STATUS_SIZE)
    
    call MPI_Init(error);
    call MPI_Comm_rank(MPI_COMM_WORLD, rank, error);
    
    if (rank .eq. 0) then
        MAX_NUMBERS = 100
        allocate(numbers(0:MAX_NUMBERS-1))
        ! Pick a random amount of integers to send to process 1
        call random_number(r)
        number_amount = floor(MAX_NUMBERS*r)
        
        ! Send the amount of integers to process 1
        call MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD, error)
        print *, 'I am', rank, ' and I sent', number_amount, ' numbers to 1'
        deallocate(numbers)
    else if (rank .eq. 1) then
        ! Probe for an incoming message from process 0
        call MPI_Probe(0, 0, MPI_COMM_WORLD, status, error);
        
        ! Get the size of the message
        call MPI_Get_count(status, MPI_INT, number_amount, error);
        ! Allocate a buffer just big enough
        allocate(number_buf(0:number_amount-1))
        
        ! Receive the message
        call MPI_Recv(number_buf, number_amount, MPI_INT, 0, 0, MPI_COMM_WORLD, status, error)
        print *, 'I am', rank, ' and I dynamically received', number_amount, ' numbers from 0'
        deallocate(number_buf)
    end if
    
    call MPI_Finalize(error)
    end

    !mpif90 recv.f90 && mpirun -np 2 --allow-run-as-root a.out