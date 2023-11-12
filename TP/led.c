#include "led.h"

void clock_init(){
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN;
}

void led_init(){
    clock_init();
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE14) | GPIO_MODER_MODE14_0;
    GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODE9;
}

static uint8_t led_state = 0;

void LED_g_on(){
    GPIOB->BSRR = GPIO_BSRR_BS14;
    led_state = 1;
}

void LED_g_off(){
    GPIOB->BSRR = GPIO_BSRR_BR14;
    led_state = 0;
}

void g_toggle() {
    if (led_state)LED_g_off();
    else LED_g_on();
}

void led(state desired){
    if(desired == LED_OFF){
        GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODE9;
        LED_g_off();
    }
    else if(desired == LED_YELLOW){
        LED_g_off();
        GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9) | GPIO_MODER_MODE9_0;
        GPIOC->BSRR = GPIO_BSRR_BS9;
    }
    else if(desired == LED_BLUE){
        LED_g_off();
        GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9) | GPIO_MODER_MODE9_0;
        GPIOC->BSRR = GPIO_BSRR_BR9;
    }
    else if(desired == LED_GREEN){
        GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODE9;
        LED_g_on();
    }
}