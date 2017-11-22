#include <stdio.h>

double pop();
void push(double);

int main() {
  int i;
  double f;

  printf("started testing the stack\n");
  printf("started pushing in the stack\n");
  for (i = 0; i < 30; ++i) {
    f = 1.001 * i;
    printf("pushing %.3f\n", f);
    push(f);
  }

  printf("started popping from stack\n");
  for (i = 0; i < 30; ++i) {
    f = pop();
    printf("popped %.3f\n", f);
  }
}