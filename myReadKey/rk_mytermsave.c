#include "../include/Readkey.h"
#include <termios.h>
#include <unistd.h>

struct termios saved_attributes;

int
rk_mytermsave (void)
{

  if (tcgetattr (STDIN_FILENO, &saved_attributes) != 0)
    {
      return -1;
    }

  return 0;
}