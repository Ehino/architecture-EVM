#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif
int
sc_regInit (void)
{
  register_flags &= 0x00;
  register_flags |= FLAG_IGNORETICK;
  return 0;
}