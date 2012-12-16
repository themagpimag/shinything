#include <stdio.h>
void fun(int, int *); /* A function with no return value. */
int main()
{
  int np = 1, p = 1; /* Initialise two int variables */
  printf("&np=%p, p=%p\n",&np, &p); /* Print the addresses. */ 
  printf("Before fun(): np=%d, p=%d\n",np,p);   /* Print the values. */
  fun(np,&p); /* Pass the value of np and the address of p. */
  return 0;   /* Return success to the operating system. */
}

void fun(int np, int *p)
{
  np = 2;  /* Assign 2 to the local variable np. */
  *p = 2;  /* Assign 2 to the memory of p defined in main. */
  printf("&np=%p, p=%p\n",&np, p); /* Print the addresses. */
}
