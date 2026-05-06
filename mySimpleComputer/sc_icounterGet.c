#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif

#ifndef STDDEF_H
#include <stddef.h>
#define STDDEF_H
#endif

int
sc_icounterGet (int *value)
{
  if (value == NULL)
    {
      return -1;
    }
  *value = register_icounter;
  return 0;
}