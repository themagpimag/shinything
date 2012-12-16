#include <stdio.h>
int main() {
  char str[33]; /* Declare a character array to hold the output. */
  int bit, i = 235643; /* Declare a number to convert to binary. */
  for(bit=31;bit>0;bit--) { /* Loop from left to right */
    if(((1<<bit) & i) == 0) str[31-bit] = '0'; /* False */
    else str[31-bit] = '1'; /* True */
  }
  str[32]='\0'; /* Add the string terminator */
  printf("%d (decimal) = %s (binary)\n", i, str);
  return 0; /* Return success to the operating system. */
}
