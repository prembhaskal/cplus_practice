#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 40

void expand(char [], char []);
int readLineSize(char [], int);
int fillGaps(char [], int, int, int);

int main() {
    char s1[LIMIT], s2[LIMIT];
    readLineSize(s1, LIMIT);
    expand(s1, s2);

    printf("string %s is expanded to %s", s1, s2);
}

/*
reads fragment by fragment
startchar-endchar   =
a is start of fragment,
- is important to find presence of fragment
endchar is end of fragment.
*/
void expand(char s1[], char s2[]) {
    int idx, idy, lastch;

    int hypenbw = 0; // no hypen in between at start.


    int s1len = strlen(s1);

    // read leading hypens
    for (idx = 0, idy = 0; s1[idx] == '-'; ++idx, ++idy)
        s2[idy] = '-';

    for (; idx < s1len; ++idx) {
        if (s1[idx] == '-') { // hypen indicates that it is middle of fragment
            if (hypenbw) { // read continuous non-leading hypens.
                s2[idy++] = '-';
            }
            hypenbw = 1;
        }
        else if (hypenbw) { // end of fragment
            // read last ch, note last ch is already captured.
            ++lastch;
            idy = fillGaps(s2, lastch, s1[idx], idy);
            lastch = s1[idx]; // last element read.
            hypenbw = 0;
        }
        else { // start of a fragment
            s2[idy++] = s1[idx];
            lastch = s1[idx];
            hypenbw = 0;
        }
    }

    // last element was hypen.
    s2[idy++] = '-';

    s2[idy] = '\0';
}

int fillGaps(char s2[], int startch, int lastch, int idx) {
    for (; startch <= lastch; ++idx, ++startch) {
        s2[idx] = startch;
    }
    return idx;
}

int readLineSize(char s[], int lim) {
    int ch, idx;
    for (idx = 0 ; ((ch = getchar()) != EOF) && idx < lim; ++idx) {
        s[idx] = ch;
    }

    s[idx] = '\0';
    return idx;
}

