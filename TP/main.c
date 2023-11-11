#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"

void config(){
    led_init();
    clocks_init();
    uart_init();
    matrix_init();
}

int main(){
    config();
    while(1){
        test_image();
    }
    return 0; 
}