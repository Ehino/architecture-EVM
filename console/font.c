#include "../include/MyBC.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int
main ()
{
  int font_desc = open ("font.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (font_desc < 0)
    {
      perror ("Error in making font");
      return -1;
    }
  if (bc_bigcharwrite (font_desc, (int *)font, 18) == 0)
    {
      printf ("Font written sucessfully\n");
    }
  else
    {
      printf ("Error in writting font\n");
      close (font_desc);
      return -1;
    }
  close (font_desc);
  return 0;
}