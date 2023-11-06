#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/* KEEPING EVERY VARIABLE IN UINT_32T TO KEEP "EASY ALIGNMENT" AND EASY INTERPRETATION */

void local_variable() {                 //Creating local variable by creating a function
    uint32_t stack;
    printf("stack 2 (sense):    %p\n",&stack);
}

uint32_t var1;                           //Non initialized global -> bss
uint32_t var2 = 15;                      //Initialized global -> data
uint32_t const var3;                     //Const -> rodata

int main() {
    uint32_t var4 = 7;                               //Creating another local variable to see in which sense the pile grow.
    uint32_t* tas_variable = (uint32_t*)malloc(sizeof(uint32_t));
    printf(".rodata:    %p\n",&var3);
    printf(".data:    %p\n",&var2);
    printf("bss:    %p\n",&var1);
    printf("heap:    %p\n",(void*)tas_variable);
    printf("stack:   %p\n",&var4);
    local_variable();
    return 0;
}
