#include "../include/MyBC.h"

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int
bc_bigcharread (int fd, int *big, int need_count, int *count)
{
  if (fd < 0 || big == NULL || count == NULL)
    return -1;
  ssize_t bytes_read = read (fd, big, need_count * sizeof (int) * 2);
  if (bytes_read < 0)
    {
      *count = 0;
      return -1;
    }
  *count = bytes_read / (sizeof (int) * 2);
  return 0;
}