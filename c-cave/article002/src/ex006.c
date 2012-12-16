#include <stdio.h>
int main()
{
  int i = 3;   /* Declare an int and assign it the value three. */
  float f = 3.;   /* Declare a float and assign it the value three. */ 
  i /= 2;   /* Divide i by two and assign the result to i.*/
  f /= 2.;   /* Divide f by two and assign the result to f. */
  printf("int (3/2) = %d, float (3./2.) = %f\n",i,f);   /* Print the result. */
  return 0; /* Return success to the operating system. */
}
