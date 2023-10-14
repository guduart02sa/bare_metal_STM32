#include "led.h"

int test_bss = 0;

int fibo(int n){
    if(n == 1 || n == 2) return 1;
    else return fibo(n-1) + fibo(n-2);
}

int main(){
    led_init();
    while(1){
        led(LED_GREEN);
        for(int i = 0; i<100000;i++);
        led(LED_YELLOW);
        for(int i = 0; i<100000;i++);
        led(LED_BLUE);
        for(int i = 0; i<100000;i++);
    }
    return 0;
}