#include "my_Term.h"

int
mt_delline (void)
{
  printf ("\033[2K");
  fflush (stdout);
  return 0;
}
