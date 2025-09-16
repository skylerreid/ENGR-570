#include <stdio.h>

void zfill(int x0, int y0, int size, int offset, int n, int array[n][n]) {
    if (size == 2) {
        // Base case: fill a 2x2 block in Z order
        array[y0][x0] = offset;  //fill elements in subarray 0-3
        array[y0][x0+1] = offset + 1; 
        array[y0+1][x0] = offset + 2; 
        array[y0+1][x0+1] = offset + 3;
        return;
    }

    int half = size / 2; // move over by half of the current array size
    int quad_area = half * half; // tell if 2x2 size has been reached

    // recursively go through quadrants
    zfill(x0, y0, half, offset + quad_area * 0, n, array); // top-left
    zfill(x0+half, y0, half, offset + quad_area * 1, n, array); // top-right
    zfill(x0, y0+half, half, offset + quad_area * 2, n, array); // bottom-left
    zfill(x0+half, y0+half, half, offset + quad_area * 3, n, array); // bottom-right
}

int main() {
    int n;
    printf("Enter the size of the array (power of 2): \n");
    scanf("%d", &n);

    if (n != 2 && n!= 4 && n!= 8 && n!= 16){
        printf("n must be a power of 2 :( \n");
        return 0;
    }
    int arr[n][n];
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            //allocate empty array and fill zeros
            arr[y][x] = 0;

    zfill(0, 0, n, 0, n, arr);

    // print array
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            printf("%3d ", arr[y][x]);
        }
        printf("\n");
    }
    return 0;
}