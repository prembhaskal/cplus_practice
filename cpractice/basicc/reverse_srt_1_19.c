#include <stdio.h>

#define MAXLENGTH 20

int readlineandlen(char[], int);
void reverse(char[], int);

int main() {
	
	int len;
	char line[MAXLENGTH];
	
	while ((len = readlineandlen(line, MAXLENGTH)) > 0 ) {
		if (line[len - 1] == '\n') {
			--len; // we don't want newline to put as first character.
		}
		reverse(line, len);
		printf("%s", line);
	}
	
	return 0;
}

int readlineandlen(char line[], int lim) {
	int c;
	int i;
	for (i = 0; i < lim - 1 && (c = getchar())!=EOF && c!='\n'; ++i) {
		line[i] = c;
	}
	
	if (c == '\n') {
		line[i++] = c;
	}
	
	line[i] = '\0';
	
	return i;
	
}

// reverse a given character array inline.
// len is without the last null character.
void reverse(char line[], int len) {
	int i, j, tmp;
	
	// we keep the last null char intact.
	
	for (i = 0, j = len - 1; i < j; ++i, --j) {
		// swap
		tmp = line[i];
		line[i] = line[j];
		line[j] = tmp;
	}
}