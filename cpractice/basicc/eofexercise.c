#include <stdio.h>

int main() {

    printf("Program to check EOF value \n");

    printf("value of eof is %d", EOF);

    printf("value of comparison is %d", getchar() != EOF);

    return 0;
}
