#include "../include/MyBC.h"
#include <stdlib.h>

int
bc_setbigcharpos (int *big, int x, int y, int value)
{
  if (big == NULL || x < 0 || x > 7 || y < 0 || y > 7 || value < 0
      || value > 1)
    return -1;
  int part = (x < 4) ? 0 : 1;
  int bit = (x % 4) * 8 + y;
  if (value)
    big[part] |= (1 << bit);
  else
    big[part] &= ~(1 << bit);
  return 0;
}