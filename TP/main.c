#include "led.h"
#include "clocks.h"
#include "uart.h"

void uart_echo(){
    char intro[] = "Executing Echo, ecrivez quelque chose: ";
    uart_puts(intro);
    char a[10];
    while(1){
        uart_gets(a,10);
        uart_puts(a);
    }
}

void uart_checksum(){
    uint32_t result = 0;
    char a = 0;
    while(1){
        result = result + uart_getchar();
    }
}
void config(){
    led_init();
    clocks_init();
    uart_init();
}

int main(){
    config();
    //uart_echo();
    uart_checksum();
    return 0; 
}