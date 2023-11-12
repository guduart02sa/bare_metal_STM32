#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"
#include "irq.h"
#include "buttons.h"

void config(){
    led_init();
    clocks_init();
    uart_init();
    matrix_init();
    irq_init();
    button_init();
}

int main(){
    config();
    while(1){
//        uart_putchar('a');
        test_image();
    }
    return 0; 
}