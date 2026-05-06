CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -l../include
LDFLAGS = -lmyTerm
AR = ar
ARFLAGS = rcs

SRCS = bc_bigcharread.c bc_bigcharwrite.c bc_box.c \
	   bc_getbigcharpos.c bc_printA.c bc_printbigchar.c \
	   bc_setbigcharpos.c bc_strlen.c

OBJS = $(SRCS:.c=.o)
TARGET = libBC.a

all: $(TARGET)

%.o: %.c ../include/MyBC.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) ../myTerm/libmyTerm.a
	$(AR) $(ARFLAGS) $(LDFLAGS) $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
