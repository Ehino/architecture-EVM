CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -I../include
LDFLAGS = -L../mySimpleComputer -L../myTerm -L../myBigChars -L../myReadKey -lSC -lmyTerm -lBC -lRK

SRCS = pr01.c printCell.c printAccumulator.c printCounters.c \
	   printDecodedCommand.c printFlags.c printBigCell.c font_range.c
FONT_SRC = font.c font_range.c
FONT_TARGET = font.out
OBJS = $(SRCS:.c=.o)
TARGET = pr01.out

all: $(TARGET) 

%.o: %.c ../include/SC.h ../include/MyBC.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) ../mySimpleComputer/libSC.a ../myTerm/libmyTerm.a ../myBigChars/libBC.a
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

font:
	$(CC) $(CFLAGS) $(FONT_SRC) -o $(FONT_TARGET) $(LDFLAGS) && ./$(FONT_TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
