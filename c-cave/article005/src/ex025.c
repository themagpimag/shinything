#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  char fileName[100], suffix[10]="-data.txt";
  gethostname(fileName,100);
  strcat(fileName, suffix); /* Append the suffix to the fileName */
  printf("%s\n",fileName); 
  return 0;
}
