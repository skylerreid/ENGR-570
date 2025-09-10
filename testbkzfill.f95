
program testbkzfillprogram testbkzfill
    use bkzfill_module
    implicit none
    
    integer :: n, i, j
    integer, allocatable, dimension(:,:) :: array2d
    integer, allocatable, dimension(:) :: z_ordered_indices
    
    print *, "Enter the size of the array: "
    read *, n
    
    if (n < 1 .or. iand(n, n-1) /= 0) then !check if n is power of 2
        print *, "Error: n must be a power of 2 (2, 4, 8, 16, ...)"
        stop
    end if
    
    allocate(array2d(n,n), source=0)   ! allocate 2D array
    
    ! Pre-allocate the z-ordered indices array to the final size (n*n)
    allocate(z_ordered_indices(n*n))
    
    ! Fill the z-ordered indices array
    do i = 1, n 
        do j = 1, n
            z_ordered_indices((i-1)*n + j) = z_order2d(i-1, j-1)  ! Assuming z_order2d uses 0-based indexing
        enddo
    enddo
    
    ! Now you can use z_ordered_indices as needed
    
    ! Clean up
    deallocate(array2d)
    deallocate(z_ordered_indices)
    
end program testbkzfill

FUNCTION z_order2d (i , j ) RESULT ( z )
! Uncomment the following two lines if this function does not apepar in a scoping unit
! ( e . g . , a module or program )
! USE ISO_C_BINDING
! IMPLICIT NONE
INTEGER ( C_INT ) , INTENT ( IN ) :: i , j
INTEGER ( C_INT ) :: z

 INTEGER ( C_INT ) :: k , ik , jk , zk , ord
 INTEGER ( C_INT8_T ) :: ib (32) , jb (32) , zb (64)

 ib =0; jb =0; zb =0
 ik =i -1; jk =j -1
 DO k =1 ,32
 ib ( k ) = INT ( MOD ( ik ,2) , KIND = C_INT8_T ) ; ik = ik /2
 jb ( k ) = INT ( MOD ( jk ,2) , KIND = C_INT8_T ) ; jk = jk /2
 ENDDO

 zk =1
 DO k =1 ,32
 zb ( zk ) = ib ( k ) ;
 zb ( zk +1) = jb ( k ) ;
 zk = zk +2
 ENDDO

 z =1; ord =1
 DO k =1 ,64
 z = z + zb ( k ) * ord
 ord = ord + ord
 ENDDO
 ENDFUNCTION
