#include <stdio.h>
int main() {
  int i, *p, arr[4] = {6,2,4,7};
  p = &arr[0]; /* Assign the address of the first element to p */
  for(i=0;i<(sizeof(arr)/sizeof(int));i++) { 
    printf("arr[%d]=%d\n",i,*p);
    p++; /* Increment the address by sizeof(int) */
  }
  return 0;   /* Return success to the operating system. */
}
