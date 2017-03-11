#include <stdio.h>

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

/*
program which prints its input one word per line.
word is separated by tab, spaces and newline.
*/
int main() {
	int ch;
	int state;
	
	state = OUTSIDE_WORD;
	
	while ((ch = getchar()) != EOF) {	
		if (ch == ' ' || ch == '\t' || ch == '\n') {
			if (state == INSIDE_WORD) {
				putchar('\n');
			}
			state = OUTSIDE_WORD;
		}
		else {
			state = INSIDE_WORD;
			putchar(ch);
		}
	}
	
	return 0;
}


