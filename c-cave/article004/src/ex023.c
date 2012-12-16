#include <stdio.h>
#include <sys/sysinfo.h>
int main() {
  struct sysinfo info; /* Create a sysinfo instance to hold the result. */
  sysinfo(&info); /* Get the system information */
  printf("Memory used = %d\n",info.totalram - info.freeram);
  return 0; /* Return success to the operating system. */
}
