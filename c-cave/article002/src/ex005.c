#include <stdio.h>
int main()
{
  float f = 3.14159;   /* Assign the approximate value of PI. */
  f+=0.0000001;   /* Add a very small number to it. */
  printf("%f\n",f);   /* Print the value stored in f. */
  return 0;   /* Return success to the operating system */
}
