#include "my_Term.h"

int
mt_setbgcolor (enum colors color)
{
  printf ("\033[4%dm", (int)color);
  fflush (stdout);
  return 0;
}
