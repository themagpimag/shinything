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




Pointers can also be used together with arrays,

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

The name of an array is also a pointer.  Therefore, an array can be modified within a function via,

  void changeArray(int *p, unsigned int n) {
    int i;
    for(i=0;i<n;i++) p[i] = i;
  }

  int main() {
    int arr[4] = {0, 0, 0, 0};
    changeArray(arr,4);

Command line

Arguments from the command line can be used by using another form of the main function,

  #include <stdio.h>
  int main(int argc, char *argv[]) { 
    int i;
    for(i=0;i<argc;i++) {  /* Loop over the arguments */
      printf("argv[%d] = %s\n",i,argv[i]); /* Print each argument out */
    }
    return 0;
  }

The arguments are passed as an array of strings, where a string is a character array.  Test this program out by running it with some command line arguments, e.g.:

./commandLine oneArg otherArg

Files

Other than reading from the keyboard or writing to the screen, it is often necessary to write to or read from files stored on a hard drive or memory card.  File accesses can be made using binary or ASCII mode.  In this tutorial only ASCII mode will be discussed.  Before a file can be opened a FILE pointer should be declared,

  FILE *filePtr = 0; /* Declare a file pointer and set it to null */

Then the file can be opened for reading "r", or writing "w".  For example, to write a file called textFile.txt:

  filePtr = fopen("textFile.txt","w");   /* Open textFile.txt for writing */

If the fopen call fails, then FILE pointer is set to null.  Once the file has been opened, commands very similar to those used to read from the keyboard or write to the screen can be used to access the file,

  fprintf(filePtr,"Writing out some important data...%d, %d, %d\n",2,3,4);

When the file access has been completed it has to be closed, flushing any data in memory to the disk.

  fclose(filePtr);   /* Close textFile.txt, flushing data to disk */

The final example program uses many of the concepts discussed so far, to provide a simple encryption algorithm,

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

The program uses an exclusive-OR to encrypt and decrypt files. An exclusive-OR is true if either bit is set and false if both or no bits are set. For example, 2 ^ 3 = 1 in decimal or in binary 10 ^ 11 = 01.  Type in a text file with nano and then try to encode the file.  Then run the program again to decode the file.

Challenge problem

Improve the encryption algorithm by using a simple random number generator, e.g:

  #include <stdlib.h>
  int newMask() {
    int mask = (double)rand()/RAND_MAX*254+1; /* Number between 1 and 255 */
    return mask;
  }
  int main(){
    srand(1234567); /* Set the seed once */
    int mask = newMask(); /* Get a new mask each time it is used. */
    return 0;
  }

The solution to the problem will be given next time. 
Article by W. H. Bell & D. Shepley
