#include <stdio.h>
#define BUFFER_SIZE 10

char mygetch();
void myungetch(int ch);
void myungets(char s[]);

char buf[BUFFER_SIZE];
int bufp = 0;

char mygetch() {
  return bufp > 0 ? buf[--bufp] : getchar();
}

void myungetch(int ch) {
  if (bufp >= BUFFER_SIZE)
    printf("Error buffer is full. cannot return char %c !!! \n", ch);
  else 
    buf[bufp++] = ch;
}

/*
  unget the whole string back onto input.
*/
void myungets(char s[]) {
  int i;
  int len = 0;
  while(s[len] != '\0')
    len++;

  // check if we have space to keep the whole line.
  // available space is BUFFER_SIZE - bufp
  if (len > BUFFER_SIZE - bufp)
    printf("Error. cannot keep the string %s \n", s);
  else {
    for (i=0; i < len; ++i) 
      myungetch(s[i]);
  }

}
