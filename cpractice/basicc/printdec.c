#include <stdio.h>

// print the number by using only putchar function
void printdec(int n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  
  if (n/10 > 0)
    printdec(n/10);

  putchar('0' + n%10);
  return;
}