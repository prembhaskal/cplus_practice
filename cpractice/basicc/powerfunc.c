#include <stdio.h>

/*
power function. definition and declaration.
*/

// declare function
int power(int m, int n);

int main() {
	int i;
	
	for (i = 0; i < 10; i++) {
		printf("%d %d %d\n", i, power(2,i), power(-3,i));
	}
	
	return 0;
}

int power(int base, int n) {
	int pow;
	
	pow = 1;
	for (; n > 0; n--) {
		pow = pow * base;
	}
	
	return pow;
}