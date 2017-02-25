#include <stdio.h>
/*
Program to count lines.
*/
int main() {
  int c;
  long nl;
  
  printf("counting no. of lines...\n");
  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
		++nl;
	}
  }
  
  printf("Total number of lines are %ld\n", nl);
  
  return 0;
}