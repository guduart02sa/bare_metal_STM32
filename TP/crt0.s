    .syntax unified
    .global _start
    .thumb

_start:
    ldr sp, =0x10007FFF
    bl init_bss
    bl main
_end:
    b _end
