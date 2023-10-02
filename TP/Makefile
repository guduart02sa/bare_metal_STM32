PREFIX=arm-none-eabi-
GDB   = $(PREFIX)gdb

debug:
	$(GDB) -x se203.gdb

connect:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto

.PHONY: connect debug