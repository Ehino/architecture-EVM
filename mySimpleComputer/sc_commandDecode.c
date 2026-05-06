#include "../include/SC.h"

#ifndef STDDEF_H
#include <stddef.h>
#define STDDEF_H
#endif

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if (sign == NULL | command == NULL | operand == NULL)
    return -1;

  int s = (value >> 0xE) & 0x1;
  int cmd = (value >> 0x7) & 0x7F;
  int op = value & 0x7F;

  if (sc_commandValidate (cmd))
    return -1;

  *sign = s;
  *command = cmd;
  *operand = op;

  return 0;
}
