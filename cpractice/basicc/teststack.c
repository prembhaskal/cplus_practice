#include <stdio.h>

double pop();
void push(double);
double peek();
void duplicateTop();
void swapTopTwo();
void clear();
int size();

int main() {
  int i;
  double f;

  printf("started testing the stack\n");
  printf("started pushing in the stack\n");
  for (i = 0; i < 5; ++i) {
    f = 1.001 * i;
    printf("pushing %.3f\n", f);
    push(f);
  }

  printf("started popping from stack\n");
  for (i = 0; i < 7; ++i) {
    f = pop();
    printf("popped %.3f\n", f);
  }

  printf("testing stack size %d\n", size());

  printf("testing peek\n");

  printf("peek on empty stack %g\n", peek());

  for (i = 0; i < 5; ++i) {
    f = 1.0 * i;
    printf("pushing %.3f\n", f);
    push(f);
  }

  for (i=0; i < 6; ++i) {
    printf("testing item %d ---> ", i);
    printf("testing peek %g -- ", peek());
    printf("tested pop %g\n",pop());
  }

  printf("refilling the stack\n");
  for (i = 0; i < 5; ++i) {
    f = 1.0 * i;
    printf("pushing %.3f\n", f);
    push(f);
  }

  printf("testing swap top two elements\n");
  swapTopTwo();
  for (i = 0; i < 6; ++i) {
    printf("popped %.3f\n", pop());
  }

  printf("refilling the stack\n");
  for (i = 0; i < 5; ++i) {
    f = 1.0 * i;
    printf("pushing %.3f\n", f);
    push(f);
  }

  printf("getting the size before clear %d\n", size());
  printf("clearing the stack \n"); 
  clear();
  printf("getting the size after clear %d\n", size());

}