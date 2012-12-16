#include <stdio.h>
int main()
{
  int apples = 20;  /* Start with twenty apples. */
  float cost, costPerApple = 0.20;  /* Set the price. */
  printf("How many apples would you like to buy?\n");  /* Ask the customer */
  scanf("%d",&apples); /* Read the number of apples needed. */
  if(apples > 20) {   /* Check if there are enough apples left. */
    printf("Sorry we only have 20 apples left.\n"); /* Apologise. */
  }
  else {
    cost = costPerApple*apples;   /* Caculate the total cost. */
    printf("That will be %.2f pounds please.\n",cost);   /* Ask for the money. */
  }
  return 0;
}
