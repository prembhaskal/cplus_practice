#include <stdio.h>

int main() {
    int ndigit[10], nwhite, nothers, c, i;
    nwhite = nothers = 0;

    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        switch(c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': ++ndigit[c - '0'];
                    break;
            case ' ':
            case '\n':
            case '\t': ++nwhite;
                    break;
            default:
                ++nothers;
                break;
        }
    }

    for (i = 0; i < 10; ++i) {
        printf("digit %d count is %d\n", i, ndigit[i]);
    }
    printf("whitespace count is %d\n", nwhite);
    printf("other count is %d\n", nothers);

    return 0;
}
