#include <stdio.h>

#define LIMIT 20

int readLineAndSize(char[], int);
void escape(char[], char[]);
void unescape(char[], char[]);

int main() {
	int strlen;
	char s[LIMIT];
	char t[2*LIMIT];
	
	strlen = readLineAndSize(s, LIMIT);
	
	printf("line length is %d \n", strlen);
	
	escape(s, t);
	printf("string after escape is %s \n", t);
	
	unescape(s, t);
	printf("string after unescaping is %s \n", t);
	
	printf("\n");
	
	return 0;
}

int readLineAndSize(char s[], int lim) {
	int idx;
	int ch;
	for (idx = 0; ((ch = getchar()) != EOF) && idx < lim; ++idx) {
		s[idx] = ch;
	}
	
	s[idx] = '\0'; // NULL char for string array.
	
	return idx;
}

/*
converts the tab and newline to literal characters.
*/

void escape(char s[], char t[]) {
	int idx, idy;
	idy = 0;
	for (idx = 0; s[idx] != '\0'; ++idx) {
		switch(s[idx]) {
			case '\t':
				t[idy++] = '\\';
				t[idy++] = 't';
				break;
			case '\n':
				t[idy++] = '\\';
				t[idy++] = 'n';
				break;
			default:
				t[idy++] = s[idx];
				break;
		}
	}
	t[idy] = '\0';
}

void unescape(char s[], char t[]) {
	int idx, idy;
	idy = 0;
	for (idx = 0; s[idx] != '\0'; ++idx) {
		switch(s[idx]) {
			case '\\':
				if ((s[idx+1] != '\0')) {
					if (s[idx+1] == 't') {
						t[idy++] = '\t';
						++idx;
					}
					else if (s[idx+1] == 'n'){
						t[idy++] = '\n';
						++idx;
					}
				}
				else {
					t[idy++] = '\\';
				}
				break;
			default:
				t[idy++] = s[idx];
				break;
		}
	}
	t[idy] = '\0';
}


