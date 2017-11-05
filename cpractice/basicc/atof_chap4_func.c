#include <ctype.h>

/*
read string
ignore leading whitespaces
read sign
read decimal + fractional part.
convert to double value.
*/
double atof(char s[]){
  double value = 0.0;
  double fracdiv;

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
  for (; s[idx] != '\0' && isdigit(s[idx]); ++idx)
    value = value * 10.0 + (s[idx] - '0');

  // read fractional part
  if (s[idx] == '.')
    ++idx;

  for (fracdiv = 0.1; s[idx] != '\0' && isdigit(s[idx]); ++idx, fracdiv /= 10.0)
    value = value + (s[idx] - '0') * fracdiv;

  return value * sign;

}