#ifndef PYTHIA_H
#define PYTHIA_H

/* W. H. Bell
** Some C declarations to match this version of Pythia
** Only the functions and common block used are included here.
*/

typedef struct {
  int msel;
  int mselpd;
  int msub[500];
  int kfin[81][2];
  double ckin[200];
} PYSUBS;
extern PYSUBS pysubs_;

void pyinit_(char *, char *, char *, double *, int, int, int);
void pystat_(int *);
void pyevnt_(void);
void pylist_(int *);
void pyhepc_(int *);

#endif
