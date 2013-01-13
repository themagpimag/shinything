#include "histogram.h"

int initHist(Histogram *hist, unsigned int nBins, float xMin, float xMax) {
  unsigned int i;
  if((hist->nBins+2) >= MAX_BINS) {
    printf("Error: too many bins requested.\n");
  }
  hist->nBins = nBins;
  hist->xMin = xMin;
  hist->xMax = xMax;
  for(i=0;i<(hist->nBins+2);i++) hist->binContents[i] = 0.;
}

int fillHist(Histogram *hist, float value, float weight) {
  unsigned int ibin;
  float binSize;
  if(value < hist->xMin) ibin = 0; /* Underflow */
  else if(value >= hist->xMax) ibin = hist->nBins+1; /* Overflow */
  else {
    ibin = 1;
    binSize = (hist->xMax - hist->xMin)/hist->nBins;
    while(value >= (ibin*binSize + hist->xMin) && 
          ibin < hist->nBins && ibin < MAX_BINS) {
      ibin++;
    }
  }
  if(ibin >= MAX_BINS) {
    printf("Error: ibin = %u is out of range\n",ibin);
    return 1;
  }

  hist->binContents[ibin] += weight;

  return 0;
}

int saveHist(Histogram *hist, const char *fileName) {
  FILE *outputFile = 0;
  unsigned int ibin;
  float binSize;
  
  /* Open the output file. */
  outputFile = fopen(fileName, "w");
  if(!outputFile) {
    printf ("Error: could not open %s for writing\n",fileName);
    return 1;
  }

  binSize = (hist->xMax - hist->xMin)/hist->nBins;

  /* Write the bin centres and their contents to file. */
  ibin=0;
  while (ibin < (hist->nBins+2) && ibin < MAX_BINS) {
    fprintf(outputFile,"%lf %lf\n",
            binSize*((double)ibin+0.5) + hist->xMin,
            hist->binContents[ibin]);
    ibin++;
  }

  /* Close output file. */
  fclose(outputFile);

  return 0;
}
