#include <stdio.h>
/* read input. replace tab, backspace and newline with literal. put output.*/
int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		}
		else if (c == '\n') {
			putchar('\\');
			putchar('n');
		}
		else if (c == '\b') {
			putchar('\\');
			putchar('b');
		}
		else {
			putchar(c);
		}
	}
	
	return 0;
}