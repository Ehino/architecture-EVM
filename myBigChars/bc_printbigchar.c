#include "../include/MyBC.h"
#include "../include/Term.h"

#include <unistd.h>

int
bc_printbigchar (int big[2], int x, int y, enum colors fg, enum colors bg)
{
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
        {
          int val;
          if (bc_getbigcharpos (big, j, i, &val) != 0)
            return -1;
          mt_gotoXY (x + 8 - i, y + j);
          if (val)
            {
              mt_setfgcolor (fg);
              mt_setbgcolor (bg);
              bc_printA ("a");
            }
          else
            {
              mt_setbgcolor (bg);
              write (1, " ", 1);
            }
        }
    }
  mt_setbgcolor (clr_default);
  mt_setfgcolor (clr_default);
  return 0;
}