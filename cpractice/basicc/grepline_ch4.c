#include <stdio.h>

#define LIMIT 20

int strIndex(char[], char[]);
int getLine(char  [], int);

/*
  searches for pattern in the input lines.
  prints all the matching lines.
*/
int main() {

  char s[LIMIT];
  int lineSize;
  char patrn[] = "prem";

  while ((lineSize = getLine(s, LIMIT)) > 0) {
    if (strIndex(s, patrn) != -1) {
      printf("%s\n", s);
    }
  }

  return 0;
}

// returns index of m in s if found, else return -1
int strIndex(char s[], char m[]) {
  int i, j, found;

  for (i = 0; s[i] != '\0'; ++i) {
    found = 0;

    for (j = 0; m[j] != '\0'; ++j) {
      if (m[j] != s[i + j]) {
      found = -1;
      break;
    }
  }

  if (found == 0)
    return i;
 }

 return -1;
}

/* 
we can read at most lim-1 chars, last char is for '\0', the NULL character
*/
int getLine(char s[], int lim) {
  int idx, ch;

  // check limit first
  for (idx = 0; idx<lim-1 && (ch = getchar()) != EOF && ch!='\n'; ++idx)
    s[idx] = ch;

  s[idx] = '\0';

  return idx;
}
