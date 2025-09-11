module zfill_module
    use iso_c_binding !using C ints, flattened arrays
    implicit none
contains

    recursive subroutine zfill(arr, row0, col0, size, start_val) bind(C, name="zfill")
        integer(c_int), intent(inout) :: arr(*)   ! pass a flat array
        integer(c_int), value :: row0, col0, size, start_val
        integer(c_int) :: half

        if (size == 1) then
            arr((row0-1)*size + col0) = start_val
        else
            half = size / 2
            call zfill(arr, row0,         col0,         half, start_val)
            call zfill(arr, row0,         col0+half,    half, start_val + half*half)
            call zfill(arr, row0+half,    col0,         half, start_val + 2*half*half)
            call zfill(arr, row0+half,    col0+half,    half, start_val + 3*half*half)
        end if
    end subroutine zfill

end module zfill_module
