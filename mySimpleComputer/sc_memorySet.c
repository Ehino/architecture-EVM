#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif

int
sc_memorySet (int address, int value)
{
  if (address < 0 || address >= RAM_SIZE)
    {
      return -1;
    }
  if (value < 0 || value > MAX_VALUE)
    {
      return -1;
    }
  ram[address] = value;
  return 0;
}