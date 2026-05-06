#include "../include/MyBC.h"
#include "../include/Readkey.h"
#include "../include/SC.h"
#include "../include/Term.h"
#include "../mySimpleComputer/mySC.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void printCell (int register_icounter, enum colors fg, enum colors bg);
void printFlags (void);
void printAccumulator (void);
void printCounters (void);
void printDecodedCommand (void);
void printLayout (void);
void printBigCell (void);
void checkWinSize (void);

static int inout_gap_cnt;
static int inout_cnt;

int
main (void)
{
  checkWinSize ();
  mt_clrscr ();

  register_accumulator = 0x643;
  register_icounter = 0;
  enum keys key;
  _Bool is_running = 1;

  sc_memoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();

  rk_mytermsave ();
  rk_mytermregime (0, 0, 1, 0, 1);
  mt_setcursorvisible (0);

  int max = 10000, min = 1;
  for (int i = 0; i < RAM_SIZE; i++)
    ram[i] = (rand () % (max - min + 1)) + min;

  while (is_running)
    {
      printAccumulator ();
      printCounters ();
      printFlags ();
      printDecodedCommand ();

      printLayout ();

      rk_readkey (&key);
      switch (key)
        {
        case KEY_ESC:
          is_running = 0;
          break;
        case KEY_UP:
          register_icounter -= 10;

          if (register_icounter < 0)
            {
              register_icounter += 130;
              if (register_icounter > 127)
                register_icounter = 127;
            }

          printCell (register_icounter + 10, clr_white, clr_default);
          printCell (register_icounter, clr_black, clr_white);
          break;
        case KEY_DOWN:
          register_icounter += 10;

          if (register_icounter > 127)
            {
              register_icounter -= 130;
              if (register_icounter < 0)
                register_icounter = 0;
            }

          printCell (register_icounter - 10, clr_white, clr_default);
          printCell (register_icounter, clr_black, clr_white);
          break;
        case KEY_LEFT:
          --register_icounter;
          if (register_icounter < 0)
            register_icounter = 127;

          printCell (register_icounter + 1, clr_white, clr_default);
          printCell (register_icounter, clr_black, clr_white);
          break;
        case KEY_RIGHT:
          ++register_icounter;
          if (register_icounter > 127)
            register_icounter = 0;

          printCell (register_icounter - 1, clr_white, clr_default);
          printCell (register_icounter, clr_black, clr_white);
          break;
        case KEY_I:
          sc_memoryInit ();
          sc_regInit ();
          sc_accumulatorInit ();
          sc_icounterInit ();
          register_icounter = 0;
          break;
        case KEY_L:
          sc_memoryLoad ("mem.bin");
          break;
        case KEY_S:
          sc_memorySave ("mem.bin");
          break;
        case KEY_F5:
          int acc_value = 0;
          if (rk_readvalue (&acc_value, 0) == 0)
            sc_accumulatorSet (acc_value);
          break;
        case KEY_F6:
          int new_icounter_value = 0;
          if (rk_readvalue (&new_icounter_value, 0) == 0)
            sc_icounterSet (new_icounter_value);
          break;
        case KEY_ENTER:
          int new_mem_value = 0;

          inout_gap_cnt = inout_cnt % 5;

          mt_gotoXY (69, 20 + inout_gap_cnt);
          printf ("%d>", inout_cnt);
          mt_setcursorvisible (1);

          rk_mytermregime (1, 0, 1, 1, 1);
          rk_readvalue (&new_mem_value, 0);

          sc_memorySet (register_icounter, new_mem_value);
          rk_mytermregime (0, 0, 1, 0, 1);
          mt_setcursorvisible (0);

          int value = 0;
          sc_memoryGet (register_icounter, &value);
          int sign = (value >> 14) & 1;
          int command = (value >> 7) & 0x7F;
          int operand = value & 0x7F;

          mt_gotoXY (69, 20 + inout_gap_cnt);

          char buf[10];
          sprintf (buf, "%d>%c%02X%02X", inout_cnt, (sign ? '-' : '+'),
                   command, operand);

          printf ("%-8s", buf);

          ++inout_cnt;
          break;
        default:
          break;
        }
    }

  mt_setcursorvisible (1);
  rk_mytermrestore ();
  mt_clrscr ();
}

void
printLayout (void)
{
  for (int i = 0; i < RAM_SIZE; i++)
    {
      if (i == register_icounter)
        printCell (i, clr_black, clr_white);
      else
        printCell (i, clr_white, clr_default);
    }

  if (inout_gap_cnt > 4)
    {
      mt_gotoXY (69, 20);
      inout_gap_cnt = 0;
    }

  mt_gotoXY (5, 17);
  int mem_val = 0;
  sc_memoryGet (register_icounter, &mem_val);
  printf ("dec: %d | oct: %02o | hex: %02X | bin: %b", mem_val, mem_val,
          mem_val, mem_val);
  mt_gotoXY (69, 20);

  bc_box (1, 1, 62, 15, clr_white, clr_black, "Memory", clr_red, clr_default);
  bc_box (63, 1, 23, 3, clr_white, clr_black, "Accumulator", clr_red,
          clr_default);
  bc_box (86, 1, 23, 3, clr_white, clr_black, "Flags", clr_red, clr_default);
  bc_box (63, 4, 23, 3, clr_white, clr_black, "InstructionCounter", clr_red,
          clr_default);
  bc_box (86, 4, 23, 3, clr_white, clr_black, "Cmd", clr_red, clr_default);
  bc_box (1, 16, 62, 3, clr_white, clr_black, "Edited Cell (format)", clr_red,
          clr_white);
  bc_box (1, 19, 67, 7, clr_white, clr_black, "CPU Cache", clr_green,
          clr_white);
  bc_box (63, 7, 46, 12, clr_white, clr_black, "Edited Cell (Increased)",
          clr_red, clr_white);
  bc_box (68, 19, 10, 7, clr_white, clr_black, "IN--OUT", clr_green,
          clr_white);
  bc_box (78, 19, 31, 7, clr_white, clr_black, "Hotkeys", clr_green,
          clr_white);
  printBigCell ();
  mt_gotoXY (79, 20);
  printf ("l - load  s - save  i - reset");
  mt_gotoXY (79, 21);
  printf ("r - run   t - step");
  mt_gotoXY (79, 22);
  printf ("ESC - exit");
  mt_gotoXY (79, 23);
  printf ("F5 - accumulator");
  mt_gotoXY (79, 24);
  printf ("F6 - instruction counter");
  mt_gotoXY (1, 30);
}

void
checkWinSize (void)
{
  int screen_row = 0, screen_column = 0;
  mt_getscreensize (&screen_row, &screen_column);

  if (screen_column < MIN_LAYOUT_SIZE_COLUMN
      || screen_row < MIN_LAYOUT_SIZE_ROW)
    {
      fprintf (stderr, "[%s]: %s\n", "ERORR", "Not enough space");
      exit (0);
    }

  if (isatty (0))
    printf ("Поток ввода связан с терминалом [%s]\n", ttyname (0));
  else
    {
      printf ("Не связан с терминалом\n");
      exit (0);
    }
  if (isatty (1))
    printf ("Поток ввода связан с терминалом [%s]\n", ttyname (1));
  else
    {
      printf ("Не связан с терминалом\n");
      exit (0);
    }

  if (isatty (2))
    printf ("Поток ввода связан с терминалом [%s]\n", ttyname (2));
  else
    {
      printf ("Не связан с терминалом\n");
      exit (0);
    }
}
