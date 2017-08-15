#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 40

void expand(char [], char []);
int readLineSize(char [], int);

int main() {
    char s1[LIMIT], s2[LIMIT];
    readLineSize(s1, LIMIT);
    expand(s1, s2);

    printf("string %s is expanded to %s", s1, s2);
}

void expand(char s1[], char s2[]) {
    int idx, idy, lastch;

    int hypenbw = 0; // no hypen in between at start.


    int s1len = strlen(s1);

    // read leading hypens
    for (idx = 0, idy = 0; s1[idx] == '-'; ++idx, ++idy)
        s2[idy] = '-';

    for (; idx < s1len; ++idx) {
        if (s1[idx] == '-') {
            if (hypenbw) { // read continuous non-leading hypens.
                s2[idy++] = '-';
            }
            hypenbw = 1;
        }
        else if (hypenbw) {
            // read lastch, note lastch is already captured.
            ++lastch;
            for (; lastch <= s1[idx]; ++idy) {
                s2[idy] = lastch;
                lastch++;
            }
            lastch = s1[idx]; // last element read.
            hypenbw = 0;
        }
        else {
            s2[idy++] = s1[idx];
            lastch = s1[idx];
            hypenbw = 0;
        }
    }

    // last element was hypen
    s2[idy++] = '-';

    s2[idy] = '\0';
}

int readLineSize(char s[], int lim) {
    int ch, idx;
    for (idx = 0 ; ((ch = getchar()) != EOF) && idx < lim; ++idx) {
        s[idx] = ch;
    }

    s[idx] = '\0';
    return idx;
}

