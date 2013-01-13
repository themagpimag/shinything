#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <stdio.h>

#define MAX_BINS 1000

/* Define a data structure to hold histogram data. */
struct histogram {
  unsigned int nBins;
  float xMin;
  float xMax;
  float binContents[MAX_BINS]; 
};

/* Define the struct as a new type, as a shorthand. */
typedef struct histogram Histogram;

/* Initialise a histogram. */
int initHist(Histogram *hist, unsigned int nBins, float xMin, float xMax);

/* Fill a histogram. */
int fillHist(Histogram *hist, float value, float weight);

/* save a histogram to a file. */
int saveHist(Histogram *hist, const char *fileName);

#endif
