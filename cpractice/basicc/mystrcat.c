#include <stdio.h>

#define MAX_LIMIT 20

void mystrcat(char s[], char t[]);
int getlinesize(char s[], int lim);
 
int main() {
  char str[MAX_LIMIT];
  char appnd[] = "prem";


  // read line
  getlinesize(str, MAX_LIMIT);
  
  mystrcat(str, appnd);

  printf("after concatenation - %s\n", str);
  
  return 0;
}

void mystrcat(char s[], char t[]) {
  int i, j;
  i = j = 0;

  while (s[i] != '\0')
    ++i;

  while ((s[i++] = t[j++]) != '\0')
    ;
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
