#include "my_Term.h"

int
mt_setcursorvisible (int value)
{
  printf ("%s", value ? "\033[?25h" : "\033[?25l");
  fflush (stdout);
  return 0;
}
