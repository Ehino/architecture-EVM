#ifndef MY_SIMPLE_COMPUTER_INTERNAL_H
#define MY_SIMPLE_COMPUTER_INTERNAL_H

#define RAM_SIZE 128
#define MAX_VALUE 0x3FFF // 16383 (14 бит)

extern int register_accumulator;
extern int register_icounter;
extern char register_flags;
extern char register_ignoredticks;
extern int ram[RAM_SIZE];

#define FLAG_OVERFLOW 0x01
#define FLAG_DIVZERO 0x02
#define FLAG_OOB 0x04
#define FLAG_INCORRECT_COMMAND 0x08
#define FLAG_IGNORETICK 0x10

#endif