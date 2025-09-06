module zfill_module
    implicit none
    contains

    recursive subroutine zfill(arr, row0, col0, size, start_val)
    integer, intent(inout) :: arr(:,:)
    integer, intent(in)    :: row0, col0, size, start_val
    integer :: half

    if (size == 1) then
        arr(row0, col0) = start_val
    else
        half = size / 2
        call zfill(arr, row0,         col0,         half, start_val)
        call zfill(arr, row0,         col0+half,    half, start_val + half*half)
        call zfill(arr, row0+half,    col0,         half, start_val + 2*half*half)
        call zfill(arr, row0+half,    col0+half,    half, start_val + 3*half*half)
    end if
end subroutine zfill

end module zfill_module