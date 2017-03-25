#include <stdio.h>

#define LEN_LIMIT 20
#define INPUT_PRESENT 0
#define END_OF_INPUT 1

int readlineandlength(char l[], int x);

/* print lines longer than 20 characters. book has limit of 80.*/
int main() {
	
	int c, linelen, i;
	int state = INPUT_PRESENT;
	char lineread[LEN_LIMIT];
	
	linelen = c = 0;
	
	while ((state == INPUT_PRESENT) && (linelen = readlineandlength(lineread, LEN_LIMIT)) > 0) {
		// check last char.
		if (lineread[linelen - 1] != '\n') { // we have more to read.
			// print current stuff first.
			for (i = 0; i < linelen; ++i) {
				putchar(lineread[i]);
			}
			// print remaining stuff after that.
			while((c = getchar()) != '\n' && c != EOF) {
				putchar(c);
			}
			if (c == '\n') {
				putchar(c);
			}
			if (c == EOF) {
				state = END_OF_INPUT;
			}
		}
	}
	
	return 0;
}

// reads input, copies to line, return line length, characters read is limited to limit.
int readlineandlength(char lin[], int maxlim) {
	int c;
	int i;
	
	c = 0;
	
	for (i = 0; i < maxlim && (c = getchar()) != EOF && c != '\n'; ++i) {
		lin[i] = c;
	}
	// val of i here is maxlim or lesser.
	// if last char is \n, then val of i lesser than maxlim.
	
	if (c == '\n') {
		lin[i++] = c;
	}
	
	return i;
	
}
