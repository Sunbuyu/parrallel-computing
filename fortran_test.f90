program test
    use iso_fortran_env
    implicit none
    integer, parameter :: col = 3, row = 2
    real :: myarray(col,row)
    integer :: i, j

    do i = 1, col
        do j = 1, row
            myarray(col, row) = i * j
        end do
    end do

    do i = 1, col
        do j = 1, row
            myarray(col, row) = i * j
            print*, "a", "(", i, ",", j, ")", "is", myarray(col, row)
        end do
    end do
 

    
end program test