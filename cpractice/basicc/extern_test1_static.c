#include <stdio.h>

int vara = 1.0;

void test1();
void test2();


int main() {
  test1();
  test2();
}

void test1() {
  printf("printing from test1 - vara value %d\n", vara);
  return;
}