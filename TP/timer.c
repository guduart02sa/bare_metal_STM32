#include "timer.h"

void timer_init(int max_us){
//    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM2RST; //Reset TIM2, BUT REALLY NEEDED?
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;

    TIM2->SR = 0;       //Clear status register(BUT NOT RELLY CLEAR, SEE AGAIN IF IT DOESN'T WORK)
    TIM2->CNT = 0;

    /*
    In upcounting mode, the counter counts from 0 to the auto-reload value (content of the
TIMx_ARR register), then restarts from 0 and generates a counter overflow event.
    */
    TIM2->ARR = max_us;

    //Prescaler = (Timer Clock Frequency / Desired Counter Frequency) - 1
    TIM2->PSC = 80 - 1; //1MHz(80000000/1000000 = 80)

    TIM2->CR1 &= ~TIM_CR1_DIR;  //upcounting mode
    
    TIM2->DIER |= TIM_DIER_UIE; //enable update interrupt
    NVIC_EnableIRQ(TIM2_IRQn);  //enable TIM2 interrupt in NVIC

    TIM2->CR1 |= TIM_CR1_CEN;   //enable counter
}

extern volatile uint8_t frame_set[512];

//extern const uint8_t _binary_image_raw_start[];
//Since it's upcounting mode, we don't need to set the counter to 0
void TIM2_IRQHandler(void){
    test_image((const rgb_color*)frame_set);
    TIM2->SR &= ~TIM_SR_UIF;    //clear update interrupt flag
}
