#include <stdio.h>

int main() {
  char pattern[] = "ould";

  printf("printing char array %s\n", pattern);

  int days[] = {1, 2, 3};
  size_t arraySize = sizeof(days)/sizeof(days[0]);

  printf(" the size of array is %lu and just sizeof val is %lu\n",
   arraySize, sizeof(days));
}