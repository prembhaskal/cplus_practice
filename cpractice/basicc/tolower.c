#include <stdio.h>

int main() {
    char str[] = "AbcdDeE";
    int i;
    for( i = 0; str[i] != '\0'; ++i) {
        str[i] = tolowerCase(str[i]);
    }

    printf("after lower case conversion %s\n", str);

    return 0;
}

int tolowerCase(int ch) {
    return (ch >= 'A' && ch <= 'Z') ? ch + 'a' - 'A' : ch;
}
