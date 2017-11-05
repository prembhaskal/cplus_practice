#include<stdio.h>
#include <ctype.h>

#define LIMIT 20

int readLineSize(char [], int);
double atof(char []);

int main() {
  // char s[LIMIT];

  char s[LIMIT];
  readLineSize(s, LIMIT);

  printf("converting string %s to double representation \n", s);

  double val = atof(s);
  printf("double representation is %f\n", val);
}
  
int readLineSize(char s[], int limit) {
  int idx, ch;
  for (idx = 0; idx < limit-1 && (ch = getchar()) != EOF; ++idx) {
    s[idx] = ch;
  }

  s[idx] = '\0';

  return idx;
}

/*
read string
ignore leading whitespaces
read sign
read decimal + fractional part.
convert to double value.
*/
double atof(char s[]){
  double value = 0.0;
  double fracdiv = 1.0;

  int idx, sign;

  for (idx = 0; isspace(s[idx]); ++idx)
    ;

  sign = 1;

  if (s[idx] == '-' || s[idx] == '+') {
    if (s[idx] == '-')
      sign = -1;

    ++idx;
  }

  // read decimal part
  for (; s[idx] != '\0' && isdigit(s[idx]); ++idx) {
    value = value * 10.0 + (s[idx] - '0');
  }

  // read fractional part
  if (s[idx] == '.') {
    ++idx;
    for (; s[idx] != '\0' && isdigit(s[idx]); ++idx) {
      fracdiv = fracdiv / 10.0;
      value = value + (s[idx] - '0') * fracdiv;
    }
  }

  return value * sign;

}