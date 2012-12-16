#include <stdio.h>
int main()
{
  char str[50]="A test string";   /* Create a 50 character string */
  printf("\"%s\"\n",str);   /* Print the string. */
  printf("The third character = \'%c\'\n",str[2]);
  return 0;   /* Return success to the operating system. */
}
