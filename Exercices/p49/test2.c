#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t *a;
uint32_t *b;
uint32_t *c;

__attribute__((naked)) void f() {
 *a += *c;
 *b += *c;
}

int main(void) {
    f();
    return 0;
}
