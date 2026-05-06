#ifndef MYSC_H
#include "mySC.h"
#define MYSC_H
#endif
#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

int
sc_memorySave (char *filename)
{
  if (filename == NULL)
    return -1;

  FILE *f = fopen (filename, "wb");
  if (!f)
    return -1;

  size_t written = fwrite (ram, sizeof (int), RAM_SIZE, f);
  fclose (f);

  return (written == RAM_SIZE) ? 0 : -1;
}