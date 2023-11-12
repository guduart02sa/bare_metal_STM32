#include "buttons.h"

/*
To configure a line as an interrupt source, use the following procedure:
1. Configure the corresponding mask bit in the EXTI_IMR register.
2. Configure the Trigger Selection bits of the Interrupt line (EXTI_RTSR and EXTI_FTSR).
3. Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
EXTI so that an interrupt coming from one of the EXTI lines can be correctly
acknowledged.
Note: The direct lines do not require any EXTI configuration.
*/
void button_init(){
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    GPIOC->MODER &= ~(GPIO_MODER_MODE13);

    SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] & ~(0b1111 << SYSCFG_EXTICR4_EXTI13_Pos)) | SYSCFG_EXTICR4_EXTI13_PC;

    EXTI->IMR1 |= EXTI_IMR1_IM13;
    EXTI->RTSR1 |= EXTI_RTSR1_RT13;
    EXTI->FTSR1 |= EXTI_FTSR1_FT13;
    
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(){
    EXTI->PR1 |= EXTI_PR1_PIF13;
    g_toggle();
}