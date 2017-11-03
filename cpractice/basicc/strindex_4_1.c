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

int getlineAndSize(char s[], int limit) {
  int idx,ch;

  for (idx = 0; idx < limit-1 && (ch = getchar()) != EOF; ++idx) {
    s[idx] = ch;
  }

  s[idx] = '\0';
  return idx;
}

/*
 return position of rightmost occurence of string t in string s, else return -1
*/
int strIndex(char s[], char t[]) {
  int i,j;
  int matchIdx, found;

  matchIdx = -1;

  for (i = 0; s[i] != '\0'; ++i) {
    found = 0;
    
    for (j = 0; t[j] != '\0'; ++j) {
      if (s[i + j] != t[j]) {
        found = -1;
        break;
      }
    }

    if (found == 0) {
      matchIdx = i;
    }
  }

  return matchIdx;
}