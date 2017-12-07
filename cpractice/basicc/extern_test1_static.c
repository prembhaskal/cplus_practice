#include <stdio.h>

int vara = 1.0;

void test1(register int);
void test2();


int main() {
  test1(6);
  test2();
}

void test1(register int registerVar) {
  printf("printing from test1 - vara value %d\n", vara);
  register long x = 1000000000;
  while(x-- > 0)
    ;
  return;
}