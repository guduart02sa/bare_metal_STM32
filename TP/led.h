#ifndef LED_H
#define LED_H

#define STM32L475xx

#include <stdint.h>
#include <stm32l4xx.h>


typedef enum {
   LED_OFF,
   LED_YELLOW,
   LED_BLUE,
   LED_GREEN
} state;

void clock_init(void);
void led_init(void);

void LED_g_on(void);
void LED_g_off(void);
void g_toggle(void);

void led(state);

#endif