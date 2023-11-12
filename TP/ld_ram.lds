ENTRY(_start)

MEMORY
{
  SRAM1 (rwx) : org = 0x20000000, LENGTH = 96K
  SRAM2 (rwx) : org = 0x10000000, LENGTH = 32K
}

SECTIONS {
  .IRQ :{
    *(.irq)
  } > SRAM1
  .text : {
    *(.text) 
  }
    .rodata :
  {
    *(.rodata)
  }
  .data : {
    *(.data) 
  }
  .bss : {
    _bstart = .;
    *(.bss)
    _bend  = .;
  }
  .stack (NOLOAD) : {
    _stack_start = .;
  } > SRAM2
}