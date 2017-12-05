#include <stdio.h>
#include "calc.h"

#define LIMIT 100

/*
Reverse Polish Notation calculator
each line is processed and calculated.

gcc -Wall -g calc.h getop.c atof_float_e.c stack.c 
mygetch.c rpncalculator.c -o rpn.out


*/
int main() {
  char s[LIMIT];
  int read;
  double op2;

  while((read=getop(s)) != EOF) {
    switch(read) {
      case NUMBER:
        push(atof(s));
        break;

      case '+':
        push(pop() + pop());
        break;

      case '*':
        push(pop() * pop());
        break;

      case '-':
        op2 = pop();
        push(pop() - op2);
        break;

      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop()/op2);
        else 
          printf("error: division by zero\n");
        break;

      case '%':
        op2 = pop();
        if (op2 != 0.0) {
          push((int)pop() % (int)op2);
        }
        else 
          printf("error:modulus division by zero\n");
        break;

      case '\n':
        printf("printing top of stack %.8g\n", pop());
        break;

      default:
        printf("unknown character %c\n", read);
        break;

    }
  }

  return 0;
}