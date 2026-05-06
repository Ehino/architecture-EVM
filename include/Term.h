#ifndef TERM_H
#define TERM_H

#define MIN_LAYOUT_SIZE_ROW 26
#define MIN_LAYOUT_SIZE_COLUMN 109

enum colors
{
  clr_black = 0,
  clr_red = 1,
  clr_green = 2,
  clr_yellow = 3,
  clr_blue = 4,
  clr_magenta = 5,
  clr_cyan = 6,
  clr_white = 7,
  clr_default = 9
};

int mt_clrscr (void);
int mt_gotoXY (int row, int col);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (enum colors color);
int mt_setbgcolor (enum colors color);
int mt_setdefaultcolor (void);
int mt_setcursorvisible (int value);
int mt_delline (void);

#endif
