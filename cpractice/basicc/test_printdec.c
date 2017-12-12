#include <stdio.h>

#define LIMIT 10

int readLineSize(char s[], int limit);

int main() {
  char s[LIMIT];
  int readChars = readLineSize(s, LIMIT);
  printf("read chars %d read line %s \n", readChars, s);
  return 0;
}

// read 1 input line in this. stop at newline/EOF
int readLineSize(char s[], int limit) {
  int ch, idx;

  for (idx = 0; idx < limit && (ch=getchar()) != EOF && ch != '\n'; ++idx) {
    s[idx] = ch;
  }

  s[idx] = '\0';

  return idx;
}