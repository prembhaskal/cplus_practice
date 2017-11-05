#include <stdio.h>

int readLineAndSize(char s[], int limit) {
  int idx, ch;

  for (idx = 0; idx < limit-1 && (ch = getchar()) != EOF && ch != '\n'; ++idx) 
    s[idx] = ch;

  if (ch == '\n')
    s[idx++] = ch;

  s[idx] = '\0';

  return idx;
}