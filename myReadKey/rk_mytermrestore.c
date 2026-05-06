#include "../include/Readkey.h"
#include <termios.h>
#include <unistd.h>

extern struct termios saved_attributes;

int
rk_mytermrestore (void)
{
  if (tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes) != 0)
    {
      return -1;
    }

  return 0;
}