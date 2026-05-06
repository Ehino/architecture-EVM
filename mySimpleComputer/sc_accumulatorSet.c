#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif

int
sc_accumulatorSet (int value)
{
  if ((value & ~0x7FFF) != 0)
    {
      return -1;
    }
  else
    {
      register_accumulator = value;
    }
  return 0;
}