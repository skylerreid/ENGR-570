#include <stdio.h>
#include <math.h>

// Convert (x,y) -> Hilbert index
unsigned int hilbert_index(unsigned int x, unsigned int y, int bits) {
    unsigned int index = 0;
    unsigned int rx, ry, s;

    for (s = bits - 1; (int)s >= 0; s--) {
        rx = (x >> s) & 1;
        ry = (y >> s) & 1;
        index += ((3 * rx) ^ ry) << (2 * s);

        // Rotate/flip quadrant if needed
        if (ry == 0) {
            if (rx == 1) {
                x = (1U << bits) - 1 - x;
                y = (1U << bits) - 1 - y;
            }
            // Swap x and y
            unsigned int t = x;
            x = y;
            y = t;
        }
    }
    return index;
}


int main(void) {
    int N;
    printf("Enter the size of the array (power of 2): \n");
    scanf("%d", &N);

    int bits = (int)(log2(N));

    int arr[N][N];
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            arr[y][x] = hilbert_index(x, y, bits);
            printf("%3d ", arr[y][x]);
        }
        printf("\n");
    }

    return 0;
}
