#include <stdint.h>

extern uint8_t _bstart, _bend;
extern uint8_t _data_start, _data_end, _data_LMA;

//static uint8_t *src = &_bstart;

void init_bss(){
    for (uint8_t *dst = &_bstart; dst < &_bend; dst++) *dst = 0;
}

/* Since the FLASH is READ-ONLY in our case, we have to recopy the section .data from the flash to the RAM */
void init_data(){
    uint8_t *dst = &_data_start;
    uint8_t *src = &_data_LMA;
    for (dst = &_data_start; dst < &_data_end; dst++, src++) *dst = *src;
}