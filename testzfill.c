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

    int half = size / 2; //use this to move between quadrants
    int quad_area = half * half; //size parameter to tell if 2x2 size has been reached

    // recursively go through quadrants
    zfill(x0, y0, half, offset + quad_area * 0, n, array); // top-left
    zfill(x0+half, y0, half, offset + quad_area * 1, n, array); // top-right
    zfill(x0, y0+half, half, offset + quad_area * 2, n, array); // bottom-left
    zfill(x0+half, y0+half, half, offset + quad_area * 3, n, array); // bottom-right
}

int main() {
    int n = 8; // array size
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
