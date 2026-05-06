#include "../include/MyBC.h"
#include <stdlib.h>

int
bc_getbigcharpos (int *big, int x, int y, int *value)
{
  if (big == NULL || value == NULL || x < 0 || x > 7 || y < 0 || y > 7)
    return -1;
  int part = (x < 4) ? 0 : 1;
  int bit = (x % 4) * 8 + y;
  *value = (big[part] >> bit) & 1;
  return 0;
}