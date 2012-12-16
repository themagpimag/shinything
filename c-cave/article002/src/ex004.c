#include <stdio.h>
int main()
{
  int i = 2147483647;   /* Assign (2^31)-1 to i */
  i++;   /* Increment i by one */
  printf("%d\n",i);   /* Print the value of i */
  return 0;   /* Return success to the operating system. */
}
