    .syntax unified
    .global _start
    .thumb

.thumb_func
_start:
    ldr sp, =0x10008000
    bl init_bss
    bl init_data
    bl main
_end:
    b _end
