#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LIMIT 20

int itob(int, char[], int);
int convertToDecimalInt(char[]);
int readSizeAndLine(char[], int);
char convertToAscii(int);
void reverseStr(char[]);

/*
read integer n and convert to base b character representation into string s.
*/
int main() {

  int base = 8;

  char s[LIMIT];
  int lineSize = readSizeAndLine(s, LIMIT);
  printf("read line of size %d and content %s\n", lineSize, s);

  int readNum = convertToDecimalInt(s);
  printf("converted number is %d\n", readNum);

  char convertedStr[LIMIT];
  itob(readNum, convertedStr, base);

  printf("string after conversion to base %d is %s", base, convertedStr);
  printf("\n");

  return 0;
}

int itob(int n, char s[], int base) {
  int idx = 0;
  int rem;

  while (n > 0) {
    rem = n % base;
    s[idx++] = convertToAscii(rem);
    n /= base;
  }
  s[idx] = '\0';

  reverseStr(s);

  return 0;
}

void reverseStr(char s[]) {
  int i, j;
  int tmp;
  for (i = 0, j = strlen(s) - 1;i < j ; ++i, --j) {
    tmp = s[i];
    s[i] = s[j];
    s[j]= tmp;
  }
}

char convertToAscii(int n) {
  if (n >= 0 && n < 10) {
    return '0' + n;
  }

  if (n > 10 && n < 16) {
    return 'A' + n - 10;
  }

  return 'X';
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
