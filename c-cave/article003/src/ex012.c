#include <stdio.h>

unsigned int factorial(unsigned int x)
{
  /* 0! is one. */
  unsigned int result = 1;   /* Declare an variable to hold the return value */
  while(x>0)   /* Loop while x is greater than zero */
  {
    result *= x;   /* multiply x by result and assign to result */
    x--;  /* Decrement x by one */
  }
  return result;   /* Return x! when x is not zero. */
}

int main()
{
  unsigned int i = 3;   /* Declare an int and assign it the value three. */
  printf("%d! = %d\n",i,factorial(i));   /* Print factorial of i */
  return 0; /* Return success to the operating system. */
}
