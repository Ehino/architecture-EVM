#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif

#ifndef STDDEF_H
#include <stddef.h>
#define STDDEF_H
#endif

int
sc_regGet (int reg, int *value)
{
  if ((reg & ~0x1F) != 0 || value == NULL)
    {
      return -1;
    }
  *value = (register_flags & reg) ? 1 : 0;
  return 0;
}