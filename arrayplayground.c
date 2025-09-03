#include <stdio.h>
#include <stdlib.h>

int** allocate_array(int n, int m){
    //allocate memory for n rows? 
    int** arr = (int**)malloc(n*sizeof(int*));

    for (int i = 0; i<n; i++){
        arr[i] = (int*)malloc(m*sizeof(int));
    }
    return arr;
    printf("Your array has been allocated :)");
}

void free_array(int** arr, int n){
    for (int i = 0; i<n; i++){
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}

int main(){
    int rows;
    int cols;

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);

    printf("Enter the number of columns in the matrix");
    scanf("%d", &cols);

    int** mat = allocate_array(rows, cols);
    if (mat != NULL) {
        // Initialize and print the array
        printf("Allocated %dx%d array:\n", rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = i * cols + j + 1;
                printf("%2d ", mat[i][j]);
            }
            printf("\n");
        }

        free_array(mat, rows);      //no memory leaks here
    } else {
        printf("Failed to allocate array.\n");
    }
    return 0;

}