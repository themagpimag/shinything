#include "histogram.h"
#include <stdio.h>

int main() {
  Histogram h;
  initHist(&h,10,0.,10.);
  fillHist(&h,0.5,1.0);
  fillHist(&h,-1.,1.0);
  fillHist(&h,12.,1.0);
  saveHist(&h,"Hist.txt"); 
 
  return 0;
}
