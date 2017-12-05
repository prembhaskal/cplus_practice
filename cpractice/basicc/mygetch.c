#include <stdio.h>

static char bufferch;
static int present = 0;

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
