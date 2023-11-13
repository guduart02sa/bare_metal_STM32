#ifndef UART_H
#define UART_H

#define STM32L475xx

#include <stddef.h>
#include <stdint.h>
#include <stm32l4xx.h>

void uart_init(int baudrate);
void uart_putchar(uint8_t c);
uint8_t uart_getchar();
void uart_puts(const char *s);
void uart_gets(char *s, size_t size);

#endif