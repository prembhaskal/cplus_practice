#include <stdio.h>

/*
program to print histogram frequencies of different characters in its input.
*/

#define MAX_CHAR_CODE 128

int main() {
	
	int ch, i, freq;
	int charfreq[MAX_CHAR_CODE];
	
	for(i = 0; i < MAX_CHAR_CODE; i++) {
		charfreq[i] = 0;
	}
	
	while((ch = getchar()) != EOF) {
		if (ch < MAX_CHAR_CODE) {
			++charfreq[ch];
		}
	}
	
	printf("\n\n------ histogram of char frequencies ------\n\n");
	
	for (i = 0; i < MAX_CHAR_CODE; i++) {
		if (charfreq[i] > 0) {
			printf("charcode:%d ", i);
			for (freq = charfreq[i]; freq > 0; freq--) {
				putchar('*');
				putchar(' ');
			}
			putchar('\n'); // next line
		}
	}
	
	return 0;
}