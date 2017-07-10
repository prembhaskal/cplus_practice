#include <stdio.h>

int invert(int, unsigned int, unsigned int);

int main() {

    printf("running program invert x, p, n ...\n\n");
    int x = 0153;
    unsigned int p = 5;
    unsigned int n = 2;
    int invx;

    invx = invert(x, p, n);

    printf("x is %o, inverted x is %o\n", x, invx);
    return 0;
}

/*
x -> 1010011.....................
        P............p-n+1      0
invert n bits starting from p that is p to p-(n-1)

*/
int invert(int x, unsigned int p, unsigned int n) {
    if ( p < n ) {
        printf("The p value should be higher than n.");
        return 0;
    }

    int msk = ~0 << n;
    msk = ~msk << (p + 1 - n);

    printf("mask is %o\n", msk);

    int invbits = (x ^ ~0) & msk;
    int xbitsremoved = x & ~msk;

    int finalx = xbitsremoved | invbits;
    return finalx;
}
