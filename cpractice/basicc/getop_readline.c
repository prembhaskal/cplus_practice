#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'
#define LIMIT 100

int readLineAndSize(char s[], int limit);// from file readLineAndSize.c
int lgetch();
void lungetch();
int lgetchnow();

char rline[LIMIT]; // read line
int lidx = -1; // line index

/*
  reads space/tab seperated operands and operators from input.
  skips spaces, tabs

  it does now handle positive/negative number.

  returns '0' when number is read.
  else returns the character read.
  if newline is read, return it like other character. it may be used 
  as special signal.
*/
int getop_readline(char s[]) {
  int ch, nextCh;
  int idx = 0;

  if ((ch = lgetchnow()) == '\0') {
    lidx = 0;
    if (readLineAndSize(rline, LIMIT) == 0)
      return EOF;
  }

  // skip spaces and tabs
  while ((ch = lgetch()) == ' ' || ch == '\t')
    ;


  // check if we have a signed number.
  if (!isdigit(ch) && ch != '.') {
    if (ch == '+' || ch == '-') { 
      nextCh = lgetch();
      if (isdigit(nextCh) || nextCh == '.') {
        s[idx++] = ch;
        ch = nextCh;
      }
      else {
        lungetch(); // un read
        return ch;
      }

    }
    else // for /, * operator
      return ch;
  }

  // read decimal part.
  while(isdigit(ch)) {
    s[idx++] = ch;
    ch = lgetch();
  }

// read decimal point (probably 2 times in case decimal point is absent)
  if (ch == '.') {
    s[idx++] = ch;
    ch = lgetch();
  }

// read fraction part.
  while(isdigit(ch)) {
    s[idx++] = ch;
    ch = lgetch();
  }

  if (ch != EOF) {
// unread the character.
    lungetch();
  }

  s[idx] = '\0';

  return NUMBER;
}

int lgetchnow() {
  return rline[lidx];
}

int lgetch() {
  // we have not read anything yet.
  if (lidx == -1) {
    return '\0';
  }

  // we are already at the NULL char.
  if (rline[lidx] == '\0')
    return '\0';
  else
    return rline[lidx++];
}

void lungetch() {
  if (lidx > 0) {
    --lidx;
  }
  else
    printf("ERROR!!!. nothing to unread. \n");
}