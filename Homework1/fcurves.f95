program spacefill
    use, intrinsic :: iso_c_binding
    implicit none

    ! define the c functions from the DLL
    interface
        function z_index(x, y) bind(C, name="z_index") result(res)
            import :: c_int32_t
            integer(c_int32_t), value :: x, y
            integer(c_int32_t) :: res
        end function z_index

        function hilbert_index(x, y, bits) bind(C, name="hilbert_index") result(res)
            import :: c_int32_t, c_int
            integer(c_int32_t), value :: x, y
            integer(c_int),      value :: bits
            integer(c_int32_t) :: res
        end function hilbert_index
    end interface

    !variable declarations
    !integer(c_int32_t) :: zi, hi
    integer(c_int32_t) :: x, y
    !integer(c_int)     :: bits
    integer::n!, j, i
    integer, allocatable, dimension(:,:) :: array

    print *, "Enter the size of the array (power of 2): "
    read *, n

    if (n < 1 .or. iand(n, n-1) /= 0) then !check if n is power of 2
        print *, "Error: n must be a power of 2 (2, 4, 8, 16, ...)"
        stop
    end if

    allocate(array(n,n), source=0_c_int32_t)

    do x = 1, n
        do y = 1, n
            array(y,x) = z_index(x-1, y-1)   ! convert to 0-based
            print '(I6,1X,I6,1X,I10)', x, y, array(x,y)
        end do
    end do

end program spacefill
