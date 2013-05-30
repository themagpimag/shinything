/* W. H. Bell
*/

#include <stdio.h>
#include "pythia.h"

int main() {
  int i, mstat;
  double ecm;

  /* Set the centre of mass energy to be 14TeV. */
  ecm=14000.0;

  /* Select Wh and Zh production. */
  pysubs_.msel=17;

  /* Initialise PYTHIA with the setup and beam energy */
  pyinit_("CMS","p","p",&ecm,3,1,1);

  /* Generate 10 events */
  for(i=0;i<10;i++) {
    pyevnt_(); /* Generate an event with PYTHIA */
  }

  /* Print a report of what was generated */ 
  mstat=1;
  pystat_(&mstat);

  return 0;
}
