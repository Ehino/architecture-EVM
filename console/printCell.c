#include "../include/SC.h"
#include "../include/Term.h"
#include <stdio.h>

extern int ram[];

void
printCell (int address, enum colors fg, enum colors bg)
{
  int value;
  if (sc_memoryGet (address, &value) != 0)
    return;

  int x = 2 + (address % 10) * 6;
  int y = 2 + (address / 10);

  mt_gotoXY (x, y);
  mt_setfgcolor (fg);
  mt_setbgcolor (bg);

  int sign = (value >> 14) & 1;
  int command = (value >> 7) & 0x7F;
  int operand = value & 0x7F;

  printf ("%c%02X%02X", (sign ? '-' : '+'), command, operand);

  mt_setfgcolor (clr_default);
  mt_setbgcolor (clr_default);
}