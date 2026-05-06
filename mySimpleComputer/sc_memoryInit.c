#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif

int
sc_memoryInit (void)
{
  for (int i = 0; i < RAM_SIZE; i++)
    {
      ram[i] = 0;
    }
  return 0;
}