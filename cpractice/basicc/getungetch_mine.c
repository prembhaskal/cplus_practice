#include <stdio.h>
#define BUFF_SIZE 20
// with buffer array

char buff[BUFF_SIZE];
int bufp = 0; // buffer pointer

int pgetch() {
  if (bufp > 0)
    return buff[--bufp];
  else
    return getchar();
}

void pungetch(int ch) {
  if (bufp > BUFF_SIZE)
    printf("buffer already full\n");
  else
    buff[bufp++] = ch;
}