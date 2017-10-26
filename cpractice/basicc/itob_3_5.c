#include <stdio.h>
#include <ctype.h>

#define LIMIT 20

int readSizeAndLine(char[] , int);

/*
read integer n and convert to base b character representation into string s.
*/
int main() {

  char s[LIMIT];
  int lineSize = readSizeAndLine(s, LIMIT);
  printf("read line of size %d and content %s\n", lineSize, s);
  return 0;
}

int itob(int n, char s[], int base) {

}

int convertToDecimalInt(char s[]) {
  int i;
  int num = 0;
  for (i = 0; isdigit(s[i]); ++i) {
    num = num * 10 + (s[i] - '0');
  }
  return num;
}

int readSizeAndLine(char s[], int limit) {
  int idx, ch;

  for (idx = 0; (ch = getchar()) != EOF && idx < limit; ++idx) {
    s[idx] = ch;
  }
  s[idx] = '\0';

  return idx;
}
