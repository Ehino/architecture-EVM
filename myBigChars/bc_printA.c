#include "../include/MyBC.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
bc_printA (char *str)
{
  if (str == NULL)
    return -1;
  write (1, "\E(0", 3); // Вход в ACS
  write (1, str, strlen (str));
  write (1, "\E(B", 3); // Выход в ASCII
  return 0;
}