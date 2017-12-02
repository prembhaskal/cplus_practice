#include <stdio.h>

#define TOTAL_SIZE 30

char mygetch();
void myungetch(int ch);
void myungets(char s[]);


int main() {
  printf("testing the ungets \n");
  char s1[] = "123456";
  char s2[] = "12345";
  char s3[TOTAL_SIZE];
  int ch;

  myungets(s1);
  myungets(s2);

  myungetch('1');
  myungetch('2');
  myungetch('3');
  myungetch('4');
  myungetch('5');
  myungetch('6');

  int i = 0;
  while((ch=mygetch()) != EOF) {
    s3[i++] = ch;
  }
  printf("final content of buffer %s\n", s3);

  myungetch('a');
  myungetch('b');
  myungetch('c');
  printf("putting the EOF %d\n", EOF);
  myungetch(EOF);
  myungetch(EOF);
  myungetch(EOF);

  printf("reading the character again %d\n", mygetch());
  printf("reading the character again %d\n", mygetch());
  printf("reading the character again %d\n", mygetch());
  printf("reading the character again %c\n", mygetch());

}