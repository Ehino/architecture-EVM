#include "../include/SC.h"
#include "../include/Term.h"
#include <stdio.h>

extern int register_icounter;

void
printDecodedCommand (void)
{
  int value = 0;

  if (sc_memoryGet (register_icounter, &value) != 0)
    return;

  int sign = (value >> 14) & 1;
  int command = (value >> 7) & 0x7F;
  int operand = value & 0x7F;

  mt_gotoXY (92, 5);

  printf ("%c%02X : %02X      ", (sign ? '-' : '+'), command, operand);
}