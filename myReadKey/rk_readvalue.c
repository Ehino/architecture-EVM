#include "../include/Readkey.h"
#include "../include/Term.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/poll.h>
#include <termios.h>
#include <unistd.h>

extern int register_icounter;

int
rk_readvalue (int *value, int timeout)
{
  if (value == NULL)
    return -1;

  struct pollfd fds = { STDIN_FILENO, POLLIN, 0 };
  int poll_timeout = (timeout <= 0) ? -1 : (timeout * 1000);

  char buffer[10] = { 0 };
  int pos = 0;

  rk_mytermregime (0, 0, 1, 0, 1);

  while (1)
    {
      char display[6] = "+0000";
      for (int i = 0; i < pos; i++)
        display[i] = buffer[i];

      printf ("\033[s");

      mt_gotoXY (2 + (register_icounter % 10) * 6,
                 2 + (register_icounter / 10));
      mt_setfgcolor (clr_black);
      mt_setbgcolor (clr_white);

      printf ("%s", display);

      mt_setfgcolor (clr_default);
      mt_setbgcolor (clr_default);

      printf ("\033[u");
      fflush (stdout);

      if (poll (&fds, 1, poll_timeout) <= 0)
        break;

      char c;
      if (read (STDIN_FILENO, &c, 1) != 1)
        continue;

      if (c == '\n' || c == '\r')
        {
          if (pos > 0)
            break;
          else
            continue;
        }

      if (c == 127 || c == 8)
        {
          if (pos > 0)
            {
              pos--;
              write (STDOUT_FILENO, "\b \b", 3);
            }
          continue;
        }

      if (pos < 5)
        {
          int valid = 0;
          if (pos == 0)
            {
              if (c == '+' || c == '-' || (c >= '0' && c <= '9')
                  || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
                valid = 1;
            }
          else
            {
              if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')
                  || (c >= 'a' && c <= 'f'))
                valid = 1;
            }

          if (valid)
            {
              if (c >= 'a' && c <= 'f')
                c -= 32;
              buffer[pos++] = c;
              write (STDOUT_FILENO, &c, 1);
            }
        }
    }

  buffer[pos] = '\0';

  if (pos == 0)
    {
      tcflush (STDIN_FILENO, TCIFLUSH);
      return -1;
    }

  int is_neg = (buffer[0] == '-');
  char *start
      = (buffer[0] == '+' || buffer[0] == '-') ? &buffer[1] : &buffer[0];

  if (*start == '\0')
    {
      tcflush (STDIN_FILENO, TCIFLUSH);
      return -1;
    }

  int mag = (int)strtol (start, NULL, 16);
  mag &= 0x3FFF;

  if (is_neg)
    *value = (1 << 14) | mag;
  else
    *value = mag;

  tcflush (STDIN_FILENO, TCIFLUSH);
  return 0;
}