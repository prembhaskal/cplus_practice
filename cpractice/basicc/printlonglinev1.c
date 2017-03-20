#include <stdio.h>

#define MAXLENGTH 20

/*
program reads input.
prints the longest line from its input, where maxlength is restricted here.
line is stored in character array as string. terminated by null character \0.
*/

int readlineandgetsize(char s[], int lim);
void copy(char s[], char d[]);

int main() {
	
	int linesize = 0;
	int maxsize = 0;
	char firstpart[MAXLENGTH];
	char lineread[MAXLENGTH];
	char maxline[MAXLENGTH];
	
	int totalLineSize = 0;
	
	while ((linesize = readlineandgetsize(firstpart, MAXLENGTH)) > 0) {
		totalLineSize = linesize;
		copy(firstpart, lineread);
		// printf("first part read is %s\n", lineread);
		// printf("first size read is %d\n",linesize);
		
		// check if we had read complete line.
		while(lineread[linesize - 1] != '\n') {
			linesize = readlineandgetsize(lineread, MAXLENGTH);
			totalLineSize = totalLineSize + linesize;
			// printf("line part read is %s\n", lineread);
			// printf("line size read is %d, total size is %d\n",linesize, totalLineSize);
		}
		
		if (totalLineSize > maxsize) {
			maxsize = totalLineSize;
			copy(firstpart, maxline);
		}
	}
	
	printf("max size of lines read is %d \n", maxsize);
	printf("max line is %s\n", maxline);
	
	return 0;
}

// reads input into array s, limited to lim.
int readlineandgetsize(char s[], int lim) {
	int idx;
	int c;
	
	for (idx = 0; idx < lim-1 && (c=getchar())!='\n' && c!=EOF; ++idx ) {
		s[idx] = c;
	}
	
	if (c == '\n'){
		s[idx++] = c;
	}
	
	s[idx] = '\0';
	
	return idx;
}

void copy(char src[], char dst[]) {
	int idx =0;
	while((dst[idx] = src[idx]) != '\0')
		++idx;
	
}