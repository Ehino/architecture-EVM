#include "../include/MyBC.h"

#include <stdlib.h>
#include <unistd.h>

int
bc_bigcharwrite (int fd, int *big, int count)
{
  if (fd < 0 || big == NULL)
    return -1;
  ssize_t size = count * (sizeof (int) * 2);
  if (write (fd, big, size) != size)
    return -1;
  return 0;
}