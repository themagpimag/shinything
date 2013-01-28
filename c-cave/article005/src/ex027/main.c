#include "histogram.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int i;
  Histogram h;
  initHist(&h,10,0.,10.);
  for(i=0;i<1000;i++) { /* Generate 1000 random points */
    fillHist(&h,10*(float)rand()/RAND_MAX,1.0); /* Histogram each value. */
  }
  saveHist(&h,"Hist.txt"); /* Save the histogram. */
 
  return 0;
}
