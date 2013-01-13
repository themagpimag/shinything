#include "histogram.h"

int initHist(Histogram *hist, unsigned int nBins, float xMin, float xMax) {
  unsigned int i;
  if((hist->nBins+3) >= MAX_BINS) {
    printf("Error: too many bins requested.\n");
  }
  hist->nBins = nBins;
  hist->xMin = xMin;
  hist->xMax = xMax;
  for(i=0;i<hist->nBins+3;i++) hist->binContents[i] = 0.;
}

int fillHist(Histogram *hist, float value, float weight) {
  unsigned int ibin;
  float binSize;
  if(value < hist->xMin) ibin = 0; /* Underflow */
  else if(value > hist->xMax) ibin = hist->nBins+1; /* Overflow */
  else {
    ibin = 1;
    binSize = (hist->xMax - hist->xMin)/hist->nBins;
    while(value > (ibin*binSize) && ibin < hist->nBins && ibin < MAX_BINS) {
      ibin++;
    }
  }
  if(ibin >= MAX_BINS) {
    printf("Error: ibin = %d is out of range\n",ibin);
    return 1;
  }
}

int saveHist(Histogram *hist, FILE *outputFile) {
  return 0;
}
