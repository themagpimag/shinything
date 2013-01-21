  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <sys/sysinfo.h>

  int main() {
    int i = 0;
    float ramUsed;
    char gnuplotCmdOne[250], gnuplotCmdTwo[250], systemCmd[1000];
    FILE *cmdPtr = 0, *outPtr = 0;
    char c, fileName[100], *strPtr = 0;
    struct sysinfo info; /* A sysinfo struct to hold the status. */

    cmdPtr = popen("hostname","r"); /* Run hostname command. */
    if(!cmdPtr) return 1;
    strPtr = &fileName[0]; /* Get a pointer to the string. */
    while((c=fgetc(cmdPtr)) != EOF) { /* Reach each character. */
      *strPtr = c; /* Set the character value. */
      strPtr++; /* Move to the next array position. */
    }
    pclose(cmdPtr); /* Close the hostname file. */
    strPtr--; /* Move backwards one array element. */
    sprintf(strPtr,"-data.txt"); /* Append the suffix. */
    printf("%s\n",fileName);
    outPtr = fopen(fileName,"w"); /* Open the output file. */
    if(!outPtr) return 1; /* If the output file cannot be opened return error */
    for(i=0;i<60;i++) {
      sysinfo(&info);  /* Get the system information */
      ramUsed = info.totalram - info.freeram;
      ramUsed /= 10240.0;
      fprintf(outPtr,"%d %f %d\n", i, ramUsed, info.loads[0]); /* Write the ram used. */
      usleep(500000); /* Sleep for 1/2 a second. */
    }
    fclose(outPtr); /* Close the output file. */ 

    /* Now plot the data */
    sprintf(gnuplotCmdOne, "plot \'%s\' using 1:2 title \'%s\'", fileName, "Ram used");
    sprintf(gnuplotCmdTwo, ", \'%s\' using 1:3 title \'%s\'\n", fileName, "Load");

    /* Create the full command, including the pipe to gnuplot */
    sprintf(systemCmd,"echo \"%s%s\" | gnuplot -persist",gnuplotCmdOne,gnuplotCmdTwo);
    
    system(systemCmd); /* Execute the system command. */
    return 0; /* Return success to the system. */
  }
