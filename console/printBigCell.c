#include "../include/MyBC.h"
#include "../include/SC.h"
#include "../include/Term.h"
#include <stdio.h>

extern int register_icounter;

void
printBigCell (void)
{
  int value = 0;

  if (sc_memoryGet (register_icounter, &value) != 0)
    return;

  int sign = (value >> 14) & 1;
  int cmd = (value >> 7) & 0x7F;
  int op = value & 0x7F;

  mt_gotoXY (64, 17);
  mt_setfgcolor (clr_blue);

  printf ("Current edited cell: %c%02X%02X   ", (sign ? '-' : '+'), cmd, op);
  mt_setfgcolor (clr_default);

  char str[6];
  sprintf (str, "%c%02X%02X", (sign ? '-' : '+'), cmd, op);

  int bigcharpos_x = 63, bigcharpos_y = 9;
  mt_gotoXY (bigcharpos_x, bigcharpos_y);

  for (int i = 0; i < 5; i++)
    {
      int idx = -1;

      if (str[i] >= '0' && str[i] <= '9')
        idx = str[i] - '0';
      else if (str[i] >= 'A' && str[i] <= 'F')
        idx = str[i] - 'A' + 10;
      else if (str[i] == '+')
        idx = 16;
      else if (str[i] == '-')
        idx = 17;

      if (idx >= 0)
        {
          bc_printbigchar (font[idx], bigcharpos_x, bigcharpos_y, clr_default,
                           clr_default);
        }

      bigcharpos_x += 9;
    }
}