#include <ctype.h>
#include <stdio.h>

double readExponentValue(char [], int);

/*
  extension to existing atof
  it handles scientific notation too. like e,E and +16,16,-16 etc 
*/
double atof_exp(char s[]){
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
  
  for (fracdiv = 0.1; s[idx] != '\0' && isdigit(s[idx]); ++idx, fracdiv /= 10.0) {
    value = value + (s[idx] - '0') * fracdiv;
  }

  value = value * readExponentValue(s, idx);

  return value * sign;
}

double readExponentValue(char s[], int idx) {
  double expValue = 1.0;
  int expSign, expNum;
   // read exponent sign
  if (s[idx] == 'e' || s[idx] == 'E') {
    ++idx;
    expSign = 1;
    if (s[idx] == '-' || s[idx] == '+') {
      if (s[idx] == '-') {
        expSign = -1;
      }
      ++idx;
    }

    // read exponent value
    expNum = 0;
    for (; isdigit(s[idx]); ++idx) {
      expNum = expNum * 10 + (s[idx] - '0');
    }

    // create power value;
    while(expNum-- > 0) {
      expValue *= 10.0;
    }

    // printf("expValue is %g expSign is %d\n", expValue, expSign);

    if (expSign == -1)
      expValue = 1.0/expValue;
  }

  return expValue;
}