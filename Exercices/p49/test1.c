#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t a;

__attribute__((naked)) void g() {
    int b = 3;
}

int main(void) {
    a = 2;
    for (unsigned int i = 0; i <= a; i++) {
        g();
    }
    return 0;
}
