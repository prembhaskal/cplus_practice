#include <stdio.h>

#define MAX_LIMIT 20

int any(char s1[], char s2[]);
int getlinesize(char s[], int lim);

int main() {
	char str[MAX_LIMIT];
	char repstr[] = "bac";
	
	getlinesize(str, MAX_LIMIT);
	
	int matchIdx = any(str, repstr);
	
	printf("match string %s, matching content in string %s matching index %d, matching character %c \n", 
			repstr, str, matchIdx, matchIdx > -1 ? str[matchIdx] : '-');
	
	return 0;
}

/*
returns the first location in string s1, where any char from from string s2 occurs.
*/
int any(char s1[], char s2[]) {
	int i, j;
	
	for (i = 0; s1[i] != '\0'; ++i)
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j])
				return i;
	
	return -1;
}

/* reads one line of input limited to lim and returns the length of line read.  */
int getlinesize(char s[], int lim) {
	int idx, ch;
	idx = 0;
	
	for (idx = 0; idx < lim - 1 && (ch = getchar())!='\n' && ch!=EOF; ++idx)
		s[idx] = ch;
	
	if (ch == '\n')
		s[idx++] = ch;
	
	// fill last char with NULL char
	s[idx] = '\0';
	
	return idx;
}
