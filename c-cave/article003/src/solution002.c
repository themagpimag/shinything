#include <stdio.h>
int main()
{
  int nterms, term = 0, i;
  printf("How many terms? ");  /* Ask the user for input */
  scanf("%d", &nterms);  /* Read the whole number */
  for(i=1;i<=nterms;i++)  /* Loop over the terms in the series */
  {
    term += i;  /* Sum the counter to produce each term */
    printf("%d ",term);  /* Print this term */
  }
  printf("\n");  /* Print a new line character before the program exits */
  return 0;
}
