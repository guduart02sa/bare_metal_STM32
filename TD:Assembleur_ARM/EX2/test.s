.syntax unified
.arch armv7-m
.cpu cortex-m4

.thumb

.global _start

_start:

.equ const,	0xDEADBEEF

ldr r0, =const
ldr r1, =0x10000000
ldr r2,	=0x10000100

loop:
	str r0, [r1],#4
	cmp r1,r2
	bne loop

ldr r1, = 0x10000000
ldr r2, = 0x10000300
ldr r3, = 0x10000400

loop2:
	ldr r4,[r1],#4
	str r4,[r2],#4
	cmp r2,r3
	bne loop2

end:
	b end