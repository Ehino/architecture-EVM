CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -l../include
LDFLAGS = -lmyReadKey
AR = ar
ARFLAGS = rcs

SRCS = rk_mytermregime.c rk_mytermrestore.c rk_mytermsave.c \
	   rk_readkey.c rk_readvalue.c
OBJS = $(SRCS:.c=.o)
TARGET = libRK.a

all: $(TARGET)

%.o: %.c ../include/Readkey.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $(LDFLAGS) $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
