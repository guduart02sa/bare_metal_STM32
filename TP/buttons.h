#ifndef BUTTONS_H
#define BUTTONS_H

#define STM32L475xx

#include <stddef.h>
#include <stdint.h>
#include <stm32l4xx.h>

#include "irq.h"
#include "led.h"

void button_init(void);

#endif