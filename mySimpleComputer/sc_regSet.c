#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif

int
sc_regSet (int reg, int value)
{
  if ((reg & ~0x1F) != 0 || reg == 0)
    {
      return -1;
    }
  if (value)
    {
      register_flags |= value;
    }
  else
    {
      register_flags &= ~reg;
    }
  return 0;
}