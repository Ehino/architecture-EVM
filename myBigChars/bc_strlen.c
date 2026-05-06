#include "../include/MyBC.h"
#include <stdlib.h>

int
bc_strlen (char *str)
{
  if (str == NULL)
    return 0;
  int len = 0;
  while (*str)
    {
      // Если это не продолжение многобайтового символа (10xxxxxx), то это
      // начало нового символа
      if ((*str & 0xC0) != 0x80)
        len++;
      str++;
    }
  return len;
}