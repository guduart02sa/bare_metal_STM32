ENTRY(_start)

MEMORY
{
  SRAM1 (rwx) : org = 0x20000000, LENGTH = 96K
}

SECTIONS {
  .text : {
    *(.text) 
  } > SRAM1
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
}