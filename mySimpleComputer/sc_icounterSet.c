#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif

int
sc_icounterSet (int value)
{
  if ((value & ~0x7FFF) != 0)
    {
      return -1;
    }
  register_icounter = value;
  return 0;
}