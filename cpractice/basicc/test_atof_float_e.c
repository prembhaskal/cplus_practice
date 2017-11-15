#include <stdio.h>

#define LIMIT 20

int readLineAndSize(char [], int);
double atof_exp(char []);

int main() {
  char s[LIMIT];

  while(readLineAndSize(s, LIMIT)) {
    printf("read value %s ", s);
    printf("converted value to %0.4f\n  ", atof_exp(s));
  }

  return 0;
}