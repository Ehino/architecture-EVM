#include "my_Term.h"

int
mt_setdefaultcolor (void)
{
  printf ("\033[0m");
  fflush (stdout);
  return 0;
}
