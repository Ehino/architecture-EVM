#include "../include/Term.h"
#include "../mySimpleComputer/mySC.h"
#include <stdio.h>

void
printFlags (void)
{
  mt_gotoXY (93, 2);
  printf ("%c ", (register_flags & FLAG_OVERFLOW) ? 'P' : '_');
  printf ("%c ", (register_flags & FLAG_DIVZERO) ? '0' : '_');
  printf ("%c ", (register_flags & FLAG_OOB) ? 'M' : '_');
  printf ("%c ", (register_flags & FLAG_IGNORETICK) ? 'T' : '_');
  printf ("%c ", (register_flags & FLAG_INCORRECT_COMMAND) ? 'E' : '_');
}
