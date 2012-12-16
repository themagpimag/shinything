#include <stdio.h>
int main(int argc, char *argv[]) { 
  int i;
  for(i=0;i<argc;i++) {  /* Loop over the arguments */
    printf("argv[%d] = %s\n",i,argv[i]); /* Print each argument out */
  }
  return 0;
}
