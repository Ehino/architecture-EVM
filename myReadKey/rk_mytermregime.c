#include "../include/Readkey.h"
#include <termios.h>
#include <unistd.h>

int
rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
{
  struct termios term;

  if (tcgetattr (STDIN_FILENO, &term) != 0)
    {
      return -1;
    }

  if (regime == 1)
    {
      term.c_lflag |= ICANON;
    }
  else if (regime == 0)
    {
      term.c_lflag &= ~ICANON;
      term.c_cc[VTIME] = vtime;
      term.c_cc[VMIN] = vmin;
    }
  else
    {
      return -1;
    }

  if (echo == 1)
    {
      term.c_lflag |= ECHO;
    }
  else
    {
      term.c_lflag &= ~ECHO;
    }

  if (sigint == 1)
    {
      term.c_lflag |= ISIG;
    }
  else
    {
      term.c_lflag &= ~ISIG;
    }

  if (tcsetattr (STDIN_FILENO, TCSANOW, &term) != 0)
    {
      return -1;
    }

  return 0;
}