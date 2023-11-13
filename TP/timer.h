#ifndef TIMER_H
#define TIMER_H

#define STM32L475xx

#include <stddef.h>
#include <stdint.h>
#include <stm32l4xx.h>

#include "led.h"
#include "matrix.h"

void timer_init(int max_us);

#endif
