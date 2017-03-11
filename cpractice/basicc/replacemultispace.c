#include <stdio.h>

#define PRE_SPACE 0
#define PRE_NOT_SPACE 1
/* program to read input and produce output replace multi blanks with single blank.*/
int main() {
	int c;
	int state;
	
	state = PRE_NOT_SPACE;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (state == PRE_NOT_SPACE) {
				putchar(c);
				state = PRE_SPACE;
			}
		}
		else {
			putchar(c);
			state = PRE_NOT_SPACE;
		}
	}
	
	return 0;
}