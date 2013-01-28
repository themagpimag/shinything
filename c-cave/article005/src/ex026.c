#include <stdio.h>

struct dataPoint {
  unsigned int timeSeconds;
  float value;
};

void printDataPoint(struct dataPoint *dp);

int main() {
  /* Declare a variable of "struct dataPoint" type. */
  struct dataPoint s;

  /* Assign the struct s some starting values. */
  s.timeSeconds = 60;
  s.value = 100.0;

  /* Print the size and memory locations */ 
  printf("sizeof(s) = %ld\n", sizeof(s));
  printf("&(s.timeSeconds) = %p\n", &(s.timeSeconds));
  printf("&(s.value) = %p\n", &(s.value));
  printf("sizeof(unsigned int) = %ld\n", sizeof(unsigned int));
  printf("sizeof(float) = %ld\n", sizeof(float)); 

  /* Print the values */
  printDataPoint(&s);

  return 0;
}

void printDataPoint(struct dataPoint *dp) {
  printf("timeSeconds = %d, value = %f\n",dp->timeSeconds,dp->value);
}
