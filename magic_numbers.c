#include <stdio.h>

 int z_index(int x, int y){
    static const unsigned int M[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF};
    //magic numbers are bit masks corresponding to different parts of the array
    //anding a number with zero clears that bit

    //shift x by some amount, or with itself, and the result with a magic number
    x = (x | (x << 8)) & M[3];
    x = (x | (x << 4)) & M[2];
    x = (x | (x << 2)) & M[1];
    x = (x | (x << 1)) & M[0];

     //shift y by some amount, or with itself, and the result with a magic number
    y = (y | (y << 8)) & M[3];
    y = (y | (y << 4)) & M[2];
    y = (y | (y << 2)) & M[1];
    y = (y | (y << 1)) & M[0];

     int z = (x | y<<1);
    return z;

}

int main(){
    int n = 8;

    int arr[n][n];
    for ( int y = 0; y < n; y++)
        for ( int x = 0; x < n; x++)
            // assign the z
            arr[y][x] = z_index(x, y);

    // print array
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            printf("%3d ", arr[y][x]);
        }
        printf("\n");
    }
    return 0;
}