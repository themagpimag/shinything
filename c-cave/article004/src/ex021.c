#include <stdio.h>
int main() {
  int c;
  FILE *ptr = 0; /* Create a null FILE pointer */
  ptr = popen("ls ./", "r"); /* List the files in the directory and listen */
  if(!ptr) return 1; /* If the command fails return failure. */
  while((c=fgetc(ptr)) != EOF) { /* Read each character. */
    printf("%c",(char)c); /* Print the characters. */
  }
  pclose(ptr); /* Close the pipe */
  return 0; /* Return success to the operating system. */
}
