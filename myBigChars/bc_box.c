#include "../include/MyBC.h"

#include <string.h>
#include <unistd.h>

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  mt_setfgcolor (box_fg);
  mt_setbgcolor (box_bg);

  // Рисуем периметр
  for (int i = 0; i < x2; i++)
    {
      for (int j = 0; j < y2; j++)
        {
          mt_gotoXY (x1 + i, y1 + j);
          if (i == 0 && j == 0)
            bc_printA ("l");
          else if (i == 0 && j == y2 - 1)
            bc_printA ("m");
          else if (i == x2 - 1 && j == 0)
            bc_printA ("k");
          else if (i == x2 - 1 && j == y2 - 1)
            bc_printA ("j");
          else if (i == 0 || i == x2 - 1)
            bc_printA ("x");
          else if (j == 0 || j == y2 - 1)
            bc_printA ("q");
        }
    }

  // Заголовок
  if (header && bc_strlen (header) > 0)
    {
      int h_len = bc_strlen (header);
      if (h_len < x2 - 2)
        {
          mt_gotoXY (x1 + x2 / 2 - 0.5 * strlen (header), y1);
          mt_setfgcolor (header_fg);
          mt_setbgcolor (header_bg);
          write (1, header, strlen (header));
        }
    }
  mt_setfgcolor (clr_default);
  mt_setbgcolor (clr_default);
  return 0;
}