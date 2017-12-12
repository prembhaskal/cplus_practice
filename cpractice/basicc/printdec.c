#include <stdio.h>

// print the number by using only putchar function
void printdec(int n) {
  int mod = n % 10;
  
  n = n / 10;
  if (n > 0)
    printdec(n);

  putchar('0' + mod);
  return;
}