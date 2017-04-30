#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
program to print the limits of different char types.
*/
void computecharlimits();
void computeintlimits();
void computeshortintlimits();
void computelongintlimits();
void computefloatlimits();
void computedoublelimits();

int main() {
	
	printf("char max %d, char min %d, unsigned char max %d\n", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
	printf("signed char max %d, signed char min %d\n", SCHAR_MAX, SCHAR_MIN);
	printf("short int max %d, short int min %d, unsigned short int max %u\n", SHRT_MAX, SHRT_MIN, USHRT_MAX);
	printf("int max %d, int min %d, unsigned int max %u\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("long max %ld, long min %ld, unsigned long max %lu\n", LONG_MAX, LONG_MIN, ULONG_MAX);
	printf("float max %f, float min %f\n", FLT_MAX, FLT_MIN);
	printf("double max %f, double min %f\n", DBL_MAX, DBL_MIN);
	
	printf("computing values...\n");
	
	computecharlimits();
	
	computeintlimits();
	
	computeshortintlimits();
	
	computelongintlimits();
	
	computefloatlimits();
	
	computedoublelimits();
	
	return 0;
}

void computeshortintlimits() {
	printf("\ncomputing short int limits...\n");
	short int c, n;
	c = n = 1;
	while (n > 0) {
		n = c + c;
		if (n < 0) {
			n = c - 1;
			n = n + c;
		}
		if (n < 0) // overflow occurred.
			printf("%d\n", c);
		c = n;
	}
}

void computecharlimits() {
	printf("\ncomputing char limits...\n");
	char c, n;
	c = n = 1;
	while (n > 0) {
		n = c + c;
		if (n < 0) {
			n = c - 1;
			n = n + c;
		}
		if (n < 0) // overflow occurred.
			printf("%d\n", c);
		c = n;
	}
}

void computeintlimits() {
	printf("\ncomputing int limits...\n");
	int c, n;
	c = n = 1;
	while (n > 0) {
		n = c + c;
		if (n < 0) {
			n = c - 1;
			n = n + c;
		}
		if (n < 0) // overflow occurred.
			printf("%d\n", c);
		c = n;
	}
}

void computelongintlimits() {
	printf("\ncomputing long int limits...\n");
	long int c, n;
	c = n = 1;
	while (n > 0) {
		n = c + c;
		if (n < 0) {
			n = c - 1;
			n = n + c;
		}
		if (n < 0) // overflow occurred.
			printf("%ld\n", c);
		c = n;
	}
}

void computefloatlimits() {
	int iter = 0;
	printf("\ncomputing float limits...\n");
	float c, n;
	c = n = 1;
	while (n > 0) {
		++iter;
		n = c + c;
		if (n < 0) {
			n = c - 1;
			n = n + c;
		}
			printf("%f\n", c);
		if (n == c) { // after limit, n is set to infinity, hence will remain same,
			printf("%f\n", c);
			n = -1;
		}
		if (iter > 100) {
			printf("%f\n", c);
			n = -1;
		}
			
		c = n;
	}
}

void computedoublelimits() {
	int iter = 0;
	printf("\ncomputing double limits...\n");
	long double c, n;
	c = n = 1.0;
	while (n > 0) {
		++iter;
		n = c + c;
		if (n < 0) {
			n = c - 1.0;
			n = n + c;
		}
			printf("%Lf\n", c);
		if (n == c) { // after limit, n is set to infinity, hence will remain same,
			printf("%Lf\n", c);
			n = -1;
		}
		if (iter > 100) {
			printf("%Lf\n", c);
			n = -1;
		}
			
		c = n;
	}
}

