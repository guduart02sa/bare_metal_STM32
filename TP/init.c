#include <stdint.h>

extern uint8_t _bstart, _bend;

//static uint8_t *src = &_bstart;
static uint8_t *dst = &_bstart;

void init_bss(){
    for (dst = &_bstart; dst < &_bend; dst++) *dst = 0;
}