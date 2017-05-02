#include <stdio.h>

#define MAX_LIMIT 20

void squeeze(char s[], int c);
int getlinesize(char s[], int lim);
 
int main() {
  char str[MAX_LIMIT];

  int chrReplace = 'c';

  // read line
  getlinesize(str, MAX_LIMIT);

  squeeze(str, chrReplace);

  printf("after replacement - %s\n", str);
  
  return 0;
}

void squeeze(char s[], int c) {
  int i, j;
  for (i = 0, j = 0; s[i] != '\0'; ++i)
    if (s[i] != c)
      s[j++] = s[i];
  
  s[j] = '\0';
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
