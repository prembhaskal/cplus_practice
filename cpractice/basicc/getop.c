#include <ctype.h>
#include <stdio.h>
#include "calc.h"
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
  static int bufferCh;

  // skip spaces, tabs
  if (bufferCh != EOF) {
    ch = bufferCh;
    bufferCh = EOF;
  }
  else {
    ch = getchar();
  }
  
  while ( ch == ' ' || ch == '\t') {
    ch = getchar();
  }

  if (!isdigit(ch) && ch != '.') {
    // check if we have a signed number.
    if (ch == '+' || ch == '-') { 
      afterSignCh = getchar();
      if (isdigit(afterSignCh) || afterSignCh == '.') {
        s[idx++] = ch;
        ch = afterSignCh;
      }
      else {
        // myungetch(afterSignCh);
        bufferCh = afterSignCh;
        return ch;
      }

    }
    else // for /, * operator
      return ch;
  }

// read decimal part.
  while(isdigit(ch)) {
    s[idx++] = ch;
    ch = getchar();
  }

// read decimal point (probably 2 times in case decimal point is absent)
  if (ch == '.') {
    s[idx++] = ch;
    ch = getchar();
  }

// read fraction part.
  while(isdigit(ch)) {
    s[idx++] = ch;
    ch = getchar();
  }

  if (ch != EOF) {
// unread the character.
    // myungetch(ch);
    bufferCh = ch;

  }

  s[idx] = '\0';

  return NUMBER;
}

