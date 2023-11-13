ENTRY(_start)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1M
  SRAM1 (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
  SRAM2 (rwx) : ORIGIN = 0x10000000, LENGTH = 32K
}

SECTIONS {
  .IRQ :{
    *(.irq)
  } > FLASH
  .text : {
    *(.text) 
  } > FLASH
  .rodata :
  {
    *(.rodata)
  } > FLASH
  .data : {
    _data_start = .;
    *(.data)
    _data_end = .;
  } >SRAM1 AT>FLASH
  .bss : {
    _bstart = .;
    *(.bss)
    _bend  = .;
  } > SRAM1
}

_stack_start = ORIGIN(SRAM2) + LENGTH(SRAM2);

_data_LMA = LOADADDR(.data);