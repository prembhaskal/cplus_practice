#include <stdio.h>

#define STACK_SIZE 20

static double stack[STACK_SIZE];
static int topOfStack = 0;

void push(double);
double pop();
double peek();
void duplicateTop();
void swapTopTwo();
void clear();
int size();

void push(double f) {
  // check if stack is full.
  if (topOfStack < STACK_SIZE)
    stack[topOfStack++] = f;
  else
    printf("Error - stack full, can't push %g\n", f);
}

double pop() {
  // check if stack is empty.
  if (topOfStack > 0)
    return stack[--topOfStack];
  else {
    printf("Error - stack empty, can't pop\n");
    return -1.0;
  }
}

int size() {
  return topOfStack;
}

double peek() {
  if (topOfStack > 0)
    return stack[topOfStack - 1];
  else {
    printf("Error -stack is empty\n");
    return -1.0;
  }
}

void duplicateTop() {
  push(peek());
  return;
}

void swapTopTwo() {
  double op1, op2;
  if (topOfStack > 0) {
    op1 = pop();
    op2 = pop();
    push(op1);
    push(op2);
  }
  else 
    printf("Error - stack has less than 2 elements\n");
}

void clear() {
  topOfStack = 0;
  return;
}

