#include <stdio.h>
#include <stdlib.h>

extern void zfill(int *array, int row0, int col0, int size, int start_val);

int main() {
    int n;
    printf("Enter the size of the array (power of 2): \n");
    scanf("%d", &n);

    if (n != 2 && n != 4 && n != 8 && n != 16) {
        printf("n must be a power of 2 :( \n");
        return 0;
    }

    // 
    int *array = malloc(n * n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n*n; i++)
        array[i] = 0;

    int offset = 0;
    zfill(0, 0, n, &offset, n, array);

    // Print array
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            printf("%3d ", array[y*n + x]);
        }
        printf("\n");
    }

    free(array);
    return 0;
}