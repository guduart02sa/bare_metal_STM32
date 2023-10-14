#PREFIX=arm-none-eabi-
#GDB   = $(PREFIX)gdb
#GCC   = $(PREFIX)gcc

#debug:
#	$(GDB) main -x se203.gdb

#connect:
#	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto

#compile:
#	$(GCC) -g -c -O1 -mcpu=cortex-m4 -mthumb main.c -o main.o

#link:
#	$(GCC) -T ld_ram.lds -g -nostdlib main.o -o main

#.PHONY: connect debug

CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
GDB=arm-none-eabi-gdb
CFLAGS=-c -g -O0 -mcpu=cortex-m4 -mthumb -ffreestanding			#Enters the C flags
ASFLAGS=-g -mcpu=cortex-m4										#Enters the S flags
LDFLAGS=-T ld_ram.lds -nostdlib									#Enters the loadscript flags

EXECFILES = $(wildcard *.o *.elf)

all: main

main: main.o crt0.o init.o memfuncs.o led.o

.PHONY: connect debug clean

connect:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto

debug: main
	$(GDB) -x se203.gdb main

clean:
	rm -f $(EXECFILES)