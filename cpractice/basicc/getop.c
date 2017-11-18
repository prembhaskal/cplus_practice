#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

int mygetch();
void myungetch(char);

/*
  reads space/tab seperated operands and operators from input.
  skips spaces, tabs

  does not yet handle positive/negative number, decimal number.

  returns '0' when number is read.
  else returns the character read.
*/
int getop(char s[]) {
  int idx = 0;
  int ch;

  // skip spaces, tabs
  while ( (ch=mygetch()) == ' ' || ch == '\t')
    ;

  if (!isdigit(ch) && ch != '.') {
    return ch;
  }

// read decimal part.
  while(isdigit(ch)) {
    s[idx++] = ch;
    ch = mygetch();
  }

// read decimal point (probably 2 times in case decimal point is absent)
  if (ch == '.') {
    s[idx++] = ch;
    ch = mygetch();
  }

// read fraction part.
  while(isdigit(ch)) {
    s[idx++] = ch;
    ch = mygetch();
  }

  if (ch != EOF) {
// unread the character.
    myungetch(ch);
  }

  s[idx] = '\0';

  return NUMBER;
}

char bufferch;
int present = 0;

int mygetch() {
  if (present) {
    present = 0;
    return bufferch;
  }
  return getchar();
}

void myungetch(char ch) {
  bufferch = ch;
  present = 1;
  return;
}
