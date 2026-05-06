#include "../include/SC.h"
#include "../include/Term.h"

#include <stdio.h>

extern int register_icounter;
extern char register_ignoredticks;

void
printCounters (void)
{
  mt_gotoXY (64, 5);
  printf ("T: %02d", register_ignoredticks);
  mt_gotoXY (74, 5);
  printf ("IC: %02x", register_icounter);
}
