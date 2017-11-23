#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

int mygetch();
void myungetch(char);

/*
  reads space/tab seperated operands and operators from input.
  skips spaces, tabs

  it does now handle positive/negative number.

  returns '0' when number is read.
  else returns the character read.
  if newline is read, return it like other character. it may be used 
  as special signal.
*/
int getop(char s[]) {
  int idx = 0;
  int ch;
  int afterSignCh;

  // skip spaces, tabs
  while ( (ch=mygetch()) == ' ' || ch == '\t')
    ;

  if (!isdigit(ch) && ch != '.') {
    // check if we have a signed number.
    if (ch == '+' || ch == '-') { 
      afterSignCh = mygetch();
      if (isdigit(afterSignCh) || afterSignCh == '.') {
        s[idx++] = ch;
        ch = afterSignCh;
      }
      else {
        myungetch(afterSignCh);
        return ch;
      }

    }
    else // for /, * operator
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
