program uptospeed
    implicit none
    integer :: fruits1, fruits2, value
    character(len = 50) :: name

    ! main program execution
    print *, "Enter a number of fruits: " 
    read *, fruits1
    print *, "Enter another number of fruits: " 
    read *, fruits2
    print *, "Enter the kind of fruit: " 
    read *, name

    value = process_input(fruits1, fruits2, name)
    print *, "End of program!"

contains

    function process_input(num1, num2, type) result(out_val)
        integer, intent(in) :: num1
        integer, intent(in) :: num2
        character(len=50), intent(in) :: type

        integer :: out_val
        out_val = num1 + num2
        print *, "You have", out_val, type
    end function process_input

end program uptospeed
