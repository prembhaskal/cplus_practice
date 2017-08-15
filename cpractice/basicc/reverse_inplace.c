#include <stdio.h>
#include <string.h>

#define LIMIT 20

void reverse_inplace(char []);
int readLineSize(char s[], int);

int main() {
    char s[LIMIT];
    readLineSize(s, LIMIT);
    printf("string is %s ", s);
    reverse_inplace(s);

    printf(" and reverse of it is %s \n", s);
}

void reverse_inplace(char s[]) {
    int i, j, ch;

    for(i= 0,j = strlen(s) - 1 ; i < j; ++i, --j) {
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }

}

int readLineSize(char s[], int lim) {
    int ch, idx;
    for (idx = 0 ; ((ch = getchar()) != EOF) && idx < lim; ++idx) {
        s[idx] = ch;
    }

    s[idx] = '\0';
    return idx;
}
