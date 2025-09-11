program zfill_demo
    use zfill_module !get the zfill function from the other file

    implicit none
    integer :: n, x, y 
    integer, allocatable, dimension(:,:) :: array

    print *, "Enter the size of the array (power of 2): "
    read *, n

    if (n < 1 .or. iand(n, n-1) /= 0) then !check if n is power of 2
        print *, "Error: n must be a power of 2 (2, 4, 8, 16, ...)"
        stop
    end if

    allocate(array(n,n), source=0)   ! allocate array
    call zfill(array, 1, 1, n, 0)   !call the function

    ! print result
    do x = 1, n
        do y = 1, n
            write(*,'(I4)', advance="no") array(x,y)
        end do
        print *
    end do
end program zfill_demo