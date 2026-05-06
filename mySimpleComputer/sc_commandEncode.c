#include "../include/SC.h"

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if (!value)
    return -1;
  if (sign != 0 && sign != 1)
    return -1;
  if (command < 0 || command > 0x7F)
    return -1;
  if (sc_commandValidate (command) != 0)
    return -1;

  *value = (sign << 0xE) | (command << 0x7) | operand;

  return 0;
}
