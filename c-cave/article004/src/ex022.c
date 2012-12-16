#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  int x_min = 0, x_max = 4; /* Set the range for the plot. */
  char commandStr[100], systemCmd[200];
  if(argc < 2) {
    printf("Usage %s <function>\n", argv[0]); /* One argument is needed.*/
    return 1; /* Return error. */
  }
  /* Build the command in two steps to show what is going on. */
  sprintf(commandStr, "plot [x=%d:%d] %s(x)", x_min, x_max, argv[1]);
  
  /* Run the command so that gnuplot stays open. */
  sprintf(systemCmd,"echo \"%s\" | gnuplot --persist",commandStr);
  system(systemCmd); /* Tell gnuplot to plot it. */
  return 0; /* Return success to the operating system. */
}
