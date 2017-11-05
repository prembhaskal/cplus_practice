#include <stdio.h>
#include <string.h>

#define LIMIT 20

int getlineAndSize(char [], int);
int strIndex(char [], char []);

int main() {
  char t[] = "prem";
  char s[LIMIT];
  getlineAndSize(s, LIMIT);
  printf("read line is %s\n", s);
  printf("read line length is %ld\n", strlen(s));

  int matchIdx = strIndex(s, t);
  printf("pattern rightmost occurence found at %d\n", matchIdx);
}
