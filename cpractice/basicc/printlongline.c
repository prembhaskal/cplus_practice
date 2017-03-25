#include <stdio.h>

#define MAXLENGTH 20

/*
program reads input.
prints the longest line from its input, where maxlength is restricted here.
line is stored in character array as string. terminated by null character \0.
*/

int getlinesize(char s[], int lim);
void copy(char s[], char d[]);

int main() {
	int len, maxlen;
	
	char line[MAXLENGTH];
	char maxline[MAXLENGTH];
	
	len = maxlen = 0;
	while ((len = getlinesize(line, MAXLENGTH)) > 0) {
		if (len > maxlen) {
			maxlen = len;
			copy(line, maxline);
		}
	}
	
	printf("max length of lines is %d\n", maxlen);
	printf("max length line is %s\n", maxline);
	
	return 0;
}

/* reads one line of input limited to lim and returns the length of line read.  */
int getlinesize(char s[], int lim) {
	int idx, ch;
	idx = 0;
	
	for (idx = 0; idx < lim - 1 && (ch = getchar())!='\n' && ch!=EOF; ++idx) {
		s[idx] = ch;
	}
	
	if (ch == '\n') {
		s[idx] = ch;
		++idx;
	}
	
	// fill last char with NULL char
	s[idx] = '\0';
	
	return idx;
}

// copies from src array to dest array till NULL char is formed.
void copy(char src[], char dst[]) {
	int idx;
	
	idx = 0;
	while ((dst[idx] = src[idx]) != '\0') {
		++idx;
	}
}