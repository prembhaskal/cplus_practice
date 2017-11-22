#include <stdio.h>

#define NUMBER '0'
#define LIMIT 20

int getop(char []);

int main () {
  int read;
  char s[LIMIT];
  int max = 40;

  while((read=getop(s)) != EOF) {
    switch(read) {
      case NUMBER :
        printf("in NUMBER ... read line %s\n", s);
        break;

      default:
        printf("in default ... read character %c\n", read);
        break;
    }

    if (max-- == 0)
      break;
  }

  return 0;
}