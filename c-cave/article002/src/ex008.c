#include <stdio.h>
int main()
{
  /* Create an array with four element and assign values. */
  float fourVector[4]={1.0, 2.0, 0.5, 2.292};
  /* Print the number of elements in the array. */
  printf("There are %ld elements\n",sizeof(fourVector)/sizeof(float));
  printf("fourVector[3]=%f\n",fourVector[3]); /* Print the fourth element.*/
  return 0;   /* Return success to the operating system. */ 
}
