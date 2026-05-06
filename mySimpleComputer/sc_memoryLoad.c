#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif
#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

int
sc_memoryLoad (char *filename)
{
  if (filename == NULL)
    return -1;

  FILE *f = fopen (filename, "rb");
  if (!f)
    return -1;

  int buffer[RAM_SIZE];
  size_t read_count = fread (buffer, sizeof (int), RAM_SIZE, f);
  fclose (f);

  if (read_count == RAM_SIZE)
    {
      for (int i = 0; i < RAM_SIZE; i++)
        {
          ram[i] = buffer[i];
        }
      return 0;
    }

  return -1;
}