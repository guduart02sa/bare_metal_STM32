.syntax unified
.arch armv7-m
.cpu cortex-m4

.thumb

.global _start

_start:

.equ const,	0xDEADBEEF
.equ taille,	0x10000000
.equ fin,	0x10000100

ldr r0, =const
ldr r1, =taille
ldr r2,	=fin

loop:
	str r0, [r1],#4
	cmp r1,r2
	bne loop

end:
	b end
