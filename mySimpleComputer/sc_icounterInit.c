#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif

int
sc_icounterInit (void)
{
  register_icounter &= 0x00;
  return 0;
}