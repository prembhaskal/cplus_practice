#include <stdio.h>

int rightrot(int, unsigned int);

int main() {
    int x = 033;

    printf("number printed %o\n", x);

    x = rightrot(x, 2);
    printf("number printed after rotation %o\n", x);

    return 0;
}

int rightrot(int x, unsigned int n) {
    // mask with LSB set to 1;
    unsigned int msk = ~0;
    msk = msk ^ (msk >> 1);

    printf("mask is %o\n", msk);

    while ( n-- > 0) {
        if ((x&1)) {
            x = x >> 1;
            x = x | msk;
        }
        else {
            x = x >> 1;
        }
    }

    return x;
}
