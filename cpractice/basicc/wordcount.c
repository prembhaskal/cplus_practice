#include <stdio.h>

#define INSIDE_WORD 0
#define OUTSIDE_WORD 1

/* word count program. unix wc program.
   counts words, lines and characters.
   word count is incremented on beginning of word.
   word are separated by blanks, tabs and newlines.
*/
int main() {
	int c;
	int state;
	long nw, nl, nc;
	
	nw = nl = nc = 0;
	state = OUTSIDE_WORD;
	
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == ' ' || c == '\t') {
			state = OUTSIDE_WORD;
		}
		else if (c == '\n') {
			++nl;
			state = OUTSIDE_WORD;
		}
		else if (state == OUTSIDE_WORD) {
			state = INSIDE_WORD;
			++nw;
		}
	}
	
	printf("line %ld words %ld chars %ld\n", nl, nw, nc);
	
	return 0;
}

