#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
program to print the limits of different char types.
*/

int main() {
	
	printf("char max %d, char min %d, unsigned char max %d\n", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
	printf("signed char max %d, signed char min %d\n", SCHAR_MAX, SCHAR_MIN);
	printf("short int max %d, short int min %d, unsigned short int max %u\n", SHRT_MAX, SHRT_MIN, USHRT_MAX);
	printf("int max %d, int min %d, unsigned int max %u\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("long max %ld, long min %ld, unsigned long max %lu\n", LONG_MAX, LONG_MIN, ULONG_MAX);
	printf("float max %f, float min %f\n", FLT_MAX, FLT_MIN);
	printf("double max %f, double min %f\n", DBL_MAX, DBL_MIN);
	
	printf("computing values...\n");
	
	printf("char value computation\n");
	char ch;
	ch = -1;
	while (ch < 0) {
		ch = ch * 2;
		printf("%d\n", ch);
	}
	
	char chc, chn;
	chc = 1;
	chn = 1;
	while (chn > 0) {
		chn = chc + chc;
		if (chn < 0) {
			chn = chc + chc - 1;
		}
		chc = chn;
		printf("%d\n", chn);
	}
	
	printf("\ncomputing integers limits...\n");
	int ic, in;
	ic = 1;
	in = 1;
	while (in > 0) {
		in = ic + ic;
		if (in < 0) {
			in = ic + ic - 1;
		}
		ic = in;
		printf("%d\n", in);
	}
	
	return 0;
}
