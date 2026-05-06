#include "my_Term.h"

int
mt_setfgcolor (enum colors color)
{
  printf ("\033[3%dm", (int)color);
  fflush (stdout);
  return 0;
}
