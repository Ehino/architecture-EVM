#include "my_Term.h"

int
mt_clrscr (void)
{
  printf ("\033[H\033[2J");
  fflush (stdout);
  return 0;
}
