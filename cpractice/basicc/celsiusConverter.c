#include <stdio.h>

/*
program to convert fahrenheit to celsius for values from 0, 20, ..., 300
*/

int main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while(fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", celsius, fahr);
        fahr = fahr + step;
    }

    return 0;

}
