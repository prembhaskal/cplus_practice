#include <stdio.h>

/*
    print Fahrenheit Celsius scale.
*/

int main() {
    int fahr;
    printf("printing in forward...\n");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    printf("printing in reverse...\n");

    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}
