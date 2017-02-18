#include <stdio.h>

/*
print Fahrenheit - Celsius scale for fahr = 0, 20, ..., 300;
floating point version
printf formatting.
*/

int main() {
    float fahr, celsius;
    int step, lower, upper;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius); // %6 6 char wide right justified.
        fahr = fahr + step;
    }

    return 0;
}
