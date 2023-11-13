#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"
#include "irq.h"
#include "buttons.h"

volatile rgb_color frame_set[512];

void config(){
    led_init();
    clocks_init();
    uart_init(38400);
    matrix_init();
    irq_init();
    button_init();
}

int main(){
    config();
    while(1){
        test_image((rgb_color *)frame_set);
    }
    return 0; 
}