#include "led.h"

/*
#define RCC_AHB2ENR *(uint32_t*)0x4002104C

#define GPIOB_MODER *(uint32_t*)0x48000400
#define GPIOB_BSRR *(uint32_t*)0x48000418

#define GPIOC_MODER *(uint32_t*)0x48000800
#define GPIOC_BSRR *(uint32_t*)0x48000818


#define RCC_AHB2_VALUE 0b00000000000000000000000000000110                     //GPIOBEN && GPIOCEN

#define GPIOB_VALUE 0b11011111111111111111111111111111                        //MODE 14 SORTIE
#define B_14_ALUMER 0b0000000000000000100000000000000                         //allumer
#define B_14_ETEINDRE 0b01000000000000000000000000000000                      //eteindre

#define GPIOC_ENTREE 0b11111111111100111111111111111111                        //MODE 9 entree
#define GPIOC_SORTIE 0b11111111111101111111111111111111                        //MODE 9 sortie
*/

// uint32_t *RCC_AHB2ENR = (uint32_t*)0x4002104C;                                   //ADDRESS AHB1 RCC
// uint32_t *GPIOB_MODER = (uint32_t*)0x48000400;                                   //ADDRESS GPIO B


void clock_init(){
    RCC->AHB2ENR |= RCC_AHB2_VALUE;
}

void led_init(){
    clock_init();
    GPIOC->MODER |= GPIOC_ENTREE;
    GPIOB->MODER |= GPIOB_VALUE;
}

void LED_g_on(){
    GPIOB->BSRR = B_14_ALUMER;
}

void LED_g_off(){
    GPIOB->BSRR = B_14_ETEINDRE;
}

void led(state desired){
    if(desired == LED_OFF){
        GPIOC->MODER = GPIOC_ENTREE;                                                 //METTRE GPIOC EN ENTREE
        LED_g_off();
    }
    else if(desired == LED_YELLOW){
        LED_g_off();
        GPIOC->MODER = GPIOC_SORTIE;
        GPIOC->BSRR = (1<<9);
    }
    else if(desired == LED_BLUE){
        LED_g_off();
        GPIOC->MODER = GPIOC_SORTIE;
        GPIOC->BSRR = (1<<25);
    }
    else if(desired == LED_GREEN){
        GPIOC->MODER = GPIOC_ENTREE;                                                 //METTRE GPIOC EN ENTREE
        LED_g_on();
    }
}