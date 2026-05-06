CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -l../include
AR = ar
ARFLAGS = rcs

SRCS = sc_accumulatorGet.c sc_accumulatorInit.c sc_accumulatorSet.c \
	   sc_commandDecode.c sc_commandEncode.c sc_commandValidate.c \
	   sc_icounterGet.c sc_icounterInit.c sc_icounterSet.c \
	   sc_memoryGet.c sc_memoryInit.c sc_memoryLoad.c sc_memorySave.c \
	   sc_memorySet.c sc_regGet.c sc_regInit.c sc_regSet.c sc_variables.c

OBJS = $(SRCS:.c=.o)
TARGET = libSC.a

all: $(TARGET)

%.o: %.c ../include/SC.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
