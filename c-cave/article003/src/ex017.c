#include <stdio.h>
int main(int argc, char *argv[]) {
  int mask = 163; /* Declare an int and assign it with a value less than 256. */
  char c; /* Declare a character (which is one byte, maximum value 255.) */
  FILE *inputFile = 0, *outputFile = 0; /* declare two file pointers */
  
  if(argc!=3) {  /* Check the number of arguments */
    printf(" Usage: %s <input file> <output file>\n",argv[0]);
    return 1; /* Report an error */
  }
  
  inputFile = fopen(argv[1],"r"); /* Open the input file. */
  if(!inputFile) return 2; /* If file pointer is null return an error. */
  
  outputFile = fopen(argv[2],"w"); /* Open the output file. */
  if(!outputFile) return 3; /* If the file pointer is null return an error */
  
  c = fgetc(inputFile); /* Get the first character. */
  while(c != EOF) {  /* Loop until end-of-file is reached. */
    c ^= mask; /* Exclusive-OR with the mask. */
    fputc(c,outputFile); /* Write to the output file. */
    c = fgetc(inputFile); /* Get another character. */
  }
  
  fclose(inputFile);  /* Close the input file. */
  fclose(outputFile);  /* Close the output file. */
  
  return 0; /* Return success to the operating system */
}
