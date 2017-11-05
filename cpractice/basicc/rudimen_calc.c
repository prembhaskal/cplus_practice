#include <stdio.h>

#define LIMIT 20

int readLineAndSize(char [], int);
double atof(char []);

int main() {
  char s[LIMIT];
  int len;
  double val = 0.0;

  printf("started the rudimentary calculator.\n");

  while((len=readLineAndSize(s, LIMIT)) > 0) {
    printf("read line %s and sum till here is %g\n",s, val += atof(s));
  }

  return 0;
}