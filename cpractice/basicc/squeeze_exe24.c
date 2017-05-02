#include <stdio.h>

#define MAX_LIMIT 20

void squeeze(char s1[], char s2[]);
int getlinesize(char s[], int lim);

int main() {
	char str[MAX_LIMIT];
	char repstr[] = "bac";
	
	getlinesize(str, MAX_LIMIT);
	
	squeeze(str, repstr);
	
	printf("word after the replacement is %s\n", str);
	
	return 0;
}

/*
remove a character from s1 if it is present in s2.
*/
void squeeze(char s1[], char s2[]) {
	int i, j, k;
	
	for (k = 0; s2[k] != '\0'; ++k) {
		for (i = 0, j = 0; s1[i] != '\0'; ++i)
			if (s1[i] != s2[k])
				s1[j++] = s1[i];
		
		s1[j] = '\0';
	}
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
