#include <stdio.h>

int bitcountv1(unsigned);

int main() {
    int x = 014;
    int bitc;

//    bitc = bitcountv1(x);
    bitc = bitcount(x);
    printf("bitcount in %o is %d", x, bitc);
    return 0;
}

// unsigned so that right shift will fill with 0s.
int bitcountv1(unsigned x) {
    int bitc;
    for(bitc = 0; x != 0; x >>= 1)
        if (x & 01)
            bitc++;

    return bitc;
}

/*
using property that x &= x-1 , deletes rightmost 1 bit.
*/

int bitcount(unsigned x) {
    int bitc;
    for (bitc = 0; x != 0; x &= x-1, ++bitc);

    return bitc;
}
