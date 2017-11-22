#include <stdio.h>

#define STACK_SIZE 20

double stack[STACK_SIZE];
int topOfStack = 0;

void push(double f) {
  // check if stack is full.
  if (topOfStack >= STACK_SIZE) {
    printf("Error - stack full, can't push %g\n", f);
    return;
  }

  stack[topOfStack++] = f;
  return;
}

double pop() {
  // check if stack is empty.
  if (topOfStack <= 0) {
    printf("Error - stack empty, can't pop\n");
    return -1;
  }

  return stack[--topOfStack];
}