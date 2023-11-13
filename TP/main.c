#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"
#include "irq.h"
#include "buttons.h"
#include "timer.h"

volatile rgb_color frame_set[192];

void config(){
    led_init();
    clocks_init();
    uart_init(38400);
    matrix_init();
    irq_init();
    button_init();
    timer_init(16667/8); //60 Hz, but we need to divide by 8 since we have 8 rows
    //    timer_init(6944/8); //144 Hz
}

int main(){
    config();
    while(1){
//        test_image((rgb_color *)frame_set);
    }
    return 0; 
}
