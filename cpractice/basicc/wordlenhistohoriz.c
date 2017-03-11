#include <stdio.h>

/*
program prints the histogram of length of words in its input.
program prints horizontal histogram.
*/

#define MAXWORDLENGTH 10
#define INSIDE_WORD 0
#define OUTSIDE_WORD 1

int main() {
	int ch, i, state, wordlen;
	int lenhisto[MAXWORDLENGTH + 1];
	
	// vertical histogram
	int maxht;

	for (i = 0; i < MAXWORDLENGTH + 1; ++i) {
		lenhisto[i]= 0;
	}

	wordlen = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\n' || ch == '\t') {
			if (state == INSIDE_WORD){
				++lenhisto[wordlen];
				wordlen = 0;
			}
			state = OUTSIDE_WORD;
		}
		else {
			state = INSIDE_WORD;
			++wordlen;
			if (wordlen > MAXWORDLENGTH) {
                wordlen = MAXWORDLENGTH;
			}
		}
	}

	// print the horizontal histogram
	for (wordlen = 0; wordlen < MAXWORDLENGTH + 1; ++wordlen) {
		printf("%d ", wordlen);
		for (i = 0; i < lenhisto[wordlen]; ++i) {
			putchar('*');
		}
		printf(" %d", lenhisto[wordlen]);
		putchar('\n');
	}
	
	printf("\n\n\n");
	
	// print the vertical histogram
	
	// find max height
	maxht = 0;
	for (wordlen = 0; wordlen < MAXWORDLENGTH + 1; ++wordlen) {
		if (lenhisto[wordlen] > maxht) {
			maxht = lenhisto[wordlen];
		}
	}
	
	printf("max height is %d \n", maxht);
	
	for (wordlen = 0; wordlen < MAXWORDLENGTH + 1; ++wordlen) {
		printf("%d ", lenhisto[wordlen]);
	}
	putchar('\n');
	
	for (maxht = maxht; maxht >= 0; --maxht) {
		for (wordlen = 0; wordlen < MAXWORDLENGTH + 1; ++wordlen) {
			if (lenhisto[wordlen] == maxht) {
				--lenhisto[wordlen];
				putchar('*');
			}
			else {
				putchar(' ');
			}
			putchar(' ');
		}
		putchar('\n');
	}
	
	for (wordlen = 0; wordlen < MAXWORDLENGTH + 1; ++wordlen) {
		printf("%d ", wordlen);
	}
	putchar('\n');
	
	

	return 0;
}
