#include <stdio.h>

#define MAXLENGTH 20
#define END_OF_FILE 0
#define INPUT_PRESENT 1

/*
read line in char[]
copy into another char[], don't copy trailing spaces,blanks.
print the line in char[]
*/
int readlineAndReturnLength(char[], int);
int removeTrailTabBlanks(char[], int);
int copyLine(char[], char[]);

int main() {
	char line[MAXLENGTH];
	char dest[MAXLENGTH];
	int linelen;
	int copiedChars;
	int state = INPUT_PRESENT;
	
	linelen = 0;
	copiedChars = 0;
	while (state == INPUT_PRESENT && (linelen = readlineAndReturnLength(line, MAXLENGTH)) > 0) {
		// ignore extra chars after the limit from the line.
		if (line[linelen - 1] != '\n') {
			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF)
				;
			
			if (ch == EOF) {
				state = END_OF_FILE;
			}
		}
		
		linelen = removeTrailTabBlanks(line, linelen);
		copiedChars = copyLine(line, dest);
		if (copiedChars > 0) {
			printf("%s", dest);
			
			if (linelen > 1 && line[linelen - 1] != '\n')
				putchar('\n');
		}
		
	}
	
	return 0;
}

// read line, read at max maxlen chars, append \0 at end of line, return length of line read.
// length returned is excluding the last NULL character.
int readlineAndReturnLength(char line[], int maxlen) {
	int ch;
	int i;
	
	for (i = 0; i < maxlen-1 && (ch = getchar())!=EOF && ch!='\n'; ++i) {
		line[i] = ch;
	}
	
	if (ch == '\n') {
		line[i++] = '\n';
	}
	
	line[i] = '\0';
	
	return i;
}
/*
removes trailing space,tab.
ignores null, newlines at the end of the line.
returns length of line excluding the null, for empty line (having only null chars, returns -1)
*/
int removeTrailTabBlanks(char line[], int lengthWithoutNull) {
	int idx = lengthWithoutNull;
	// ignore null
	--idx;
	// ignore new line character, if present.
	if (line[idx] == '\n') {
		--idx;
	}
	
	while (idx >= 0 && (line[idx]==' ' || line[idx]=='\t')) {
		line[idx] = '\0';
		lengthWithoutNull = idx;
		--idx;
	}
	
	return lengthWithoutNull;
}

int copyLine(char src[], char dest[]) {
	int i = 0;
	while((dest[i] = src[i]) != '\0')
		++i;
	
	return i;
}
