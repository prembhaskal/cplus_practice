#include <stdio.h>

#define MAXLENGTH 20


// external definition
int maxlen;
char line[MAXLENGTH];
char longest[MAXLENGTH];

/*
program reads input.
prints the longest line from its input, where maxlength is restricted here.
line is stored in character array as string. terminated by null character \0.
*/
int getlinesize(void);
void copy(void);

int main() {
	int len;
	
	// extern declaration.
	extern int maxlen;
	extern char longest[];
	
	len = maxlen = 0;
	while ((len = getlinesize()) > 0) {
		if (len > maxlen) {
			maxlen = len;
			copy();
		}
	}
	
	if (maxlen > 0)
		printf("max length line is %s\n", longest);
	
	return 0;
}

/* reads one line of input limited to lim and returns the length of line read.  */
int getlinesize() {
	int idx, ch;
	extern char line[];
	
	idx = 0;
	
	for (idx = 0; idx < MAXLENGTH - 1 && (ch = getchar())!='\n' && ch!=EOF; ++idx)
		line[idx] = ch;
	
	if (ch == '\n')
		line[idx++] = ch;
	
	line[idx] = '\0'; // fill last char with NULL char
	
	return idx;
}

// copies from src array to dest array till NULL char is formed.
void copy(void) {
	int idx;
	extern char line[], longest[];
	
	idx = 0;
	while ((longest[idx] = line[idx]) != '\0')
		++idx;
}