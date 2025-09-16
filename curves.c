#include <stdint.h>

#ifdef _WIN32
  #define EXPORT __declspec(dllexport)
#else
  #define EXPORT
#endif

// this will work for numbers up to 2^16
EXPORT unsigned int z_index(unsigned int x, unsigned int y){
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

    unsigned int z = (x | y<<1);
    return z;

}

// Convert (x,y) -> Hilbert index
EXPORT unsigned int hilbert_index(unsigned int x, unsigned int y, int bits) {
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