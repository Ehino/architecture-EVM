#include "../include/Readkey.h"
#include <string.h>
#include <unistd.h>

int
rk_readkey (enum keys *key)
{
  if (key == NULL)
    return -1;

  // Буфер для чтения последовательности
  char buf[16] = { 0 };

  int num_read = read (STDIN_FILENO, buf, 15);

  if (num_read < 0)
    return -1;

  if (num_read == 0)
    return 0; // тайм-аут или EOF

  if (buf[0] == '\033')
    {
      if (num_read == 1)
        *key = KEY_ESC;
      else if (strcmp (buf, "\033[A") == 0)
        *key = KEY_UP;
      else if (strcmp (buf, "\033[B") == 0)
        *key = KEY_DOWN;
      else if (strcmp (buf, "\033[C") == 0)
        *key = KEY_RIGHT;
      else if (strcmp (buf, "\033[D") == 0)
        *key = KEY_LEFT;
      else if (strcmp (buf, "\033[15~") == 0)
        *key = KEY_F5;
      else if (strcmp (buf, "\033[17~") == 0)
        *key = KEY_F6;
      else
        *key = KEY_OTHER;
    }

  else if (num_read == 1)
    {
      switch (buf[0])
        {
        case 'l':
          *key = KEY_L;
          break;
        case 's':
          *key = KEY_S;
          break;
        case 'i':
          *key = KEY_I;
          break;
        case 'r':
          *key = KEY_R;
          break;
        case 't':
          *key = KEY_T;
          break;
        case '\n':
          *key = KEY_ENTER;
          break;
        default:
          *key = KEY_OTHER;
          break;
        }
    }
  else
    {
      *key = KEY_OTHER;
    }

  return 0;
}