#include <stdio.h>
#include <string.h>

void itoa(int, char []);
void reverse_str(char []);

int main() {
    char s[20] = "123";
    printf("before reverse %s\n", s);
    reverse_str(s);
    printf("after reverse %s\n", s);

    int num = 12345;
    itoa(num, s);
    printf("after conversion to string %s", s);
}

void itoa(int num, char s[]) {
    int idx;
    idx = 0;
    do {
        s[idx++] = '0' + num % 10;
    }
    while ((num /= 10) > 0);

    s[idx] = '\0';
    reverse_str(s);
}

void reverse_str(char s[]) {
    int i,j;
    int tmp;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
}
