#include <stdio.h>

#define LIMIT 20

int main() {
  char t[] = "prem";
}

int getlineAndSize(char s[], int limit) {
  
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