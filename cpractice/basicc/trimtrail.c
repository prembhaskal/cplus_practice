#include <stdio.h>
#include <ctype.h>

#define LIMIT 20

int main() {

}

void trimtrail(char s[]) {
	int idx;
	for (idx = strlen(s) - 1; idx >=0; --idx) {
		if (s[idx] != ' ' && s[idx] != '\t' && s[idx] != '\n')
			break;
	}
	s[idx + 1] = '\0';
}

int readLineAndSize(char s[], int limit) {
	int idx, ch;

	for (idx = 0; (ch = getchar()) != EOF && idx < limit; ++idx) {
		s[idx] = ch;
	}
	s[idx] = '\0';

	return idx;
}