CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -I../include
AR = ar
ARFLAGS = rcs

SRCS = mt_getscreensize.c mt_setcursorvisible.c \
	   mt_clrscr.c mt_gotoXY.c mt_setdefaultcolor.c \
	   mt_delline.c mt_setbgcolor.c mt_setfgcolor.c

OBJS = $(SRCS:.c=.o)
TARGET = libmyTerm.a

all: $(TARGET)

%.o: %.c ../include/my_Term.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
