#include <stdio.h>

int pgetch();
void pungetch(int);

int main() {

  int read = -1;
  int idx = 0;

  // read std input while EOF
  while(idx++ < 5 && (read=pgetch()) != EOF) {  
    printf("read character %c\n", read);
  }

  // un read two characters.
  pungetch('p');
  pungetch('r');
  pungetch('e');
  pungetch('m');

  // read again
  while((read=pgetch()) != EOF) {
    printf("read character %c\n", read);
  }

  return 0;
}