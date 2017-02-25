#include <stdio.h>
// program to count the tabs, blanks and newlines.
int main() {
  int c;
  long tabc, spacec, nwlinec;
  
  tabc = spacec = nwlinec = 0;
  
  while ((c = getchar()) != EOF) {
    if (c == ' ')
		++spacec;
	else if (c == '\t') 
		++tabc;
	else if (c == '\n')
		++nwlinec;
  }
  
  printf("counting done\n");
  printf("no. of spaces %ld\n", spacec);
  printf("no. of tabs %ld\n", tabc);
  printf("no. of new lines %ld\n", nwlinec);
  
  return 0;
}