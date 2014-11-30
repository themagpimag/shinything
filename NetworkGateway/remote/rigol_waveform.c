/*
   rigol_waveform.c
   Convert binary aveforms from Rigol scopes to ascii tables 
   Usage: rigol_waveform < file_with_waveform_data.raw
   Compile with: gcc rigol_waveform.c -o rigol_waveform
   140731, Volker Ziemann
   License: http://www.gnu.org/licenses/gpl.txt
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

//.........................................................main
int main(int argc, char *argv[]) {
  int i,npts=-1;
  ssize_t is;
  uint8_t txt[2000000],tmp[20];
  float time_div,time_offs,chan1_div,chan1_offs,volt,time;
  float chan2_div,chan2_offs,volt2,rate;
  FILE *fp;

  for (i=0;i<argc;i++) {
    if (strstr(argv[i],"-h")) {
      printf("Usage: rigol_waveform < infil.raw\nExpects file settings.txt with scope settings data\n");
      exit(1);
    }
  }

  fp=fopen("settings.txt","r");  // scope settings
  if (fp==NULL) {printf("Cannot open settings file"); exit(1);}
  fscanf(fp,"%g",&time_div);
  fscanf(fp,"%g",&time_offs);
  fscanf(fp,"%g",&chan1_div);
  fscanf(fp,"%g",&chan1_offs);
  fscanf(fp,"%g",&chan2_div);
  fscanf(fp,"%g",&chan2_offs);
  fscanf(fp,"%g",&rate);
  fclose(fp);

  is=fread(txt,2000000,1,stdin);  // read waveform from stdin
  memcpy(tmp,&txt[2],10); tmp[8]='\0';
  sscanf(tmp,"%d",&npts);
  for (i=0;i<npts;i++) {
    volt=(240-txt[10+i])*(chan1_div/25)-(chan1_offs+chan1_div*4.6);
    if (npts<1000) { time=i*time_div/50-(time_div*6-time_offs); }
    else { time=time_offs+(i-0.5*npts)/rate; }
    printf(" %14.6e    %14.6e\n",time,volt);
  }
  printf("# npts=%d  is=%d rate=%g time_div/offs=%g %g \n",npts,is,rate,time_div,time_offs);
  printf("# ch1_div/offs=%10.4f %10.4f   ch2_div/offs=%10.4f %10.4f\n",
    chan1_div,chan1_offs,chan2_div,chan2_offs);
  exit(0); 
}
