CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
GDB=arm-none-eabi-gdb
OBJ=arm-none-eabi-objcopy
CFLAGS=-c -g -O2 -mcpu=cortex-m4 -I./CMSIS/Device/ST/STM32L4xx/Include -I./CMSIS/Include -Wall -Wextra -Werror -mthumb -ffreestanding -mfloat-abi=hard -mfpu=fpv4-sp-d16			#Enters the C flags
ASFLAGS=-g -mcpu=cortex-m4																									#Enters the S flags
LDFLAGS=-T ld_ram.lds -nostdlib																								#Enters the loadscript flags

EXECFILES = $(filter-out clocks.o, $(wildcard *.o *.elf))

all: main

main: main.o crt0.o init.o memfuncs.o led.o clocks.o uart.o matrix.o image.o irq.o buttons.o

image.o: image.raw
	$(OBJ) -I binary -O elf32-littlearm -B arm image.raw image.o

.PHONY: connect debug clean

connect:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto

debug: main
	$(GDB) -x se203.gdb main

clean:
	rm -f $(EXECFILES)