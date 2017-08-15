#include <stdio.h>
#include <ctype.h>

#define LIMIT 20

int atoi(char[]);
int readLineAndSize(char [], int);

int main() {
    char s[LIMIT];
    int len = readLineAndSize(s, LIMIT);

    int num = atoi(s);

    printf("string %s of len %d and converted to number is %d", s, len, num);
}

/*
skip whitespaces if any
read sign if any
read integer part and convert it.
*/
int atoi(char s[]) {
    int sign, n , idx;

    for (idx = 0; isspace(s[idx]); ++idx)
        ;

    sign = (s[idx] == '-') ? -1 : 1;

    if (s[idx] == '-' || s[idx] == '+')
        ++idx;

    for (n = 0; isdigit(s[idx]); ++idx) {
        n = n*10 + (s[idx] - '0');
    }

    return sign * n;
}

int readLineAndSize(char s[], int limit) {
    int ch, idx;

    for (idx = 0; (ch = getchar()) != EOF && idx < limit; ++idx) {
        s[idx] = ch;
    }

    s[idx] = '\0';
    return idx;
}
