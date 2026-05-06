#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif
#ifndef STDDEF_H
#include <stddef.h>
#define STDDEF_H
#endif

int
sc_memoryGet (int address, int *value)
{
  if (address < 0 || address >= RAM_SIZE || value == NULL)
    {
      return -1;
    }
  *value = ram[address];
  return 0;
}