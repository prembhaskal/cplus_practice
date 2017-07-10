#include <stdio.h>

int setbits(int x, unsigned int p, int y, unsigned int n);

int main() {
  int octint = 052;
  int y = 07;
  octint = setbits(octint, 1, y, 3);

  printf("octal int printed %d, octal format %o \n", octint, octint);
  return 0;
}

int setbits(int x, unsigned int p, int y, unsigned int n) {

	int msk = ~(~0 << n);

	int y_rightn_bits = y & msk;
	int y_rightn_bits_shft = y_rightn_bits << p;

	int x_nbits_cleared = ~(msk << p) & x;

	return x_nbits_cleared | y_rightn_bits_shft;
}


int setbits1(int x, unsigned int p, int y, unsigned int n) {

	int msk = ~(~0 << n);
	unsigned int x_nbits_cleared = ~(msk << p) & x;

	int yl = 0;
	unsigned int ycp = y;
	while (ycp > 0) {
        ycp = ycp >> 1;
        ++yl;
	}

	int ymsk = ~0 << (yl - n);
	int y_rightn_bits = y & msk;

	int y_rightn_bits_shft = y_rightn_bits >> (yl - n);
	y_rightn_bits_shft = y_rightn_bits_shft << p;

	return x_nbits_cleared | y_rightn_bits_shft;
}
