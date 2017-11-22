#include <stdio.h>

#define LIMIT 20

int readLineAndSize(char [], int);
double atof(char []);

int main() {
  char s[LIMIT];

  while(readLineAndSize(s, LIMIT)) {
    printf("read value %s ", s);
    printf("converted value to %0.4f\n  ", atof(s));
  }

  return 0;
}