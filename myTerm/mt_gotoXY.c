#include "my_Term.h"

int
mt_gotoXY (int row, int col)
{
  printf ("\033[%d;%dH", col, row);
  fflush (stdout);
  return 0;
}
