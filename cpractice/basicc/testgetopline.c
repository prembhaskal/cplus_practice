#include <stdio.h>

#define NUMBER '0'
#define LIMIT 20

int getop_readline(char []);

int main () {
  int read;
  char s[LIMIT];
  int max = 40;

  printf("testing the getop readline \n");

  while((read=getop_readline(s)) != EOF) {
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