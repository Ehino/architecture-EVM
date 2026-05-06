#include "../include/SC.h"
#include "../include/Term.h"

#include <stdio.h>

extern int register_accumulator;

void
printAccumulator (void)
{
  mt_gotoXY (64, 2);
  printf ("sc: +%04X hex: %x", register_accumulator, register_accumulator);
}
