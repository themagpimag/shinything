#include <stdio.h>
int main() {
  int bit = 0, i = 1;
  while(i>0) { /* Loop until the sign bit is set */
    printf(" pow(2,%2d) = %11d\n",bit,i);
    i = i<<1; /* Shift value of i left by one. */ 
    bit++; /* Increment the counter by one. */
  }
  return 0; /* Return success to the operating system. */
}
