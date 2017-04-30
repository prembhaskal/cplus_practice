#include <stdio.h>
#include <ctype.h>

#define MAXLENGTH 20

unsigned int htoi(char[]);
int getlinesize(char[], int);
int hexvalue(char);
int ishexchar(char);

int main() {
	
	char str[MAXLENGTH];
	
	getlinesize(str, MAXLENGTH);
	
	int value = htoi(str);
	
	printf("value of %s is %d\n", str, value);
	
	return 0;
}

/*
converts hex digits to equivalent integer value.
1F
0x1F
0X1F

*/
unsigned int htoi(char s[]) {
	unsigned int ans = 0;
	int i = 0;
	
	if (s[i] == '0')
		++i;
	
	if (tolower(s[i]) == 'x')
		++i;
	
	for (; ishexchar(s[i]); ++i) {
		ans = 16 * ans + hexvalue(tolower(s[i]));
	}	
	
	return ans;
}

// expects only lower char.
int hexvalue(char c) {
	if (isdigit(c))
		return c - '0';
	
	return 10 + c - 'a';
}

int ishexchar(char c) {
	int ch;
	if (isdigit(c))
		return 1;
	
	ch = tolower(c);
	if (ch >= 'a' && ch <= 'f')
		return 1;
	
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

