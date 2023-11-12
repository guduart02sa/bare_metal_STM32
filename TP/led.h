#ifndef LED_H
#define LED_H

#define STM32L475xx

#include <stdint.h>
#include <stm32l4xx.h>

#define RCC_AHB2_VALUE 0b00000000000000000000000000000110                     //GPIOBEN && GPIOCEN

#define GPIOB_VALUE 0b11011111111111111111111111111111                        //MODE 14 SORTIE
#define B_14_ALUMER 0b0000000000000000100000000000000                         //allumer
#define B_14_ETEINDRE 0b01000000000000000000000000000000                      //eteindre

#define GPIOC_ENTREE 0b11111111111100111111111111111111                        //MODE 9 entree
#define GPIOC_SORTIE 0b11111111111101111111111111111111                        //MODE 9 sortie


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