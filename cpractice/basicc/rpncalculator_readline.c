#include <stdio.h>

#define NUMBER '0'
#define LIMIT 100

int getop_readline(char []); // from getop_readline.c file
double pop(); // from stack.c file
void push(double); // from stack.c file
double atof(char []); // from atof_float_e.c file

/*
Reverse Polish Notation calculator
each line is processed and calculated.

02/12/1987 -- compile using these files gcc -Wall -g rpncalculator_readline.c atof_float_e.o 
stack.o getop_readline.o readLineAndSize.o -o rpnline.o
*/
int main() {
  char s[LIMIT];
  int read;
  double op2;

  while((read=getop_readline(s)) != EOF) {
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

      case '\0':
        printf("read NULL character\n");
        break;

      default:
        printf("unknown character %c\n", read);
        break;

    }
  }

  return 0;
}