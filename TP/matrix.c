#include "matrix.h"

#define RST(x) if(x) GPIOC->BSRR = GPIO_BSRR_BS3; else GPIOC->BSRR = GPIO_BSRR_BR3;
#define SB(x) if(x) GPIOC->BSRR = GPIO_BSRR_BS5; else GPIOC->BSRR = GPIO_BSRR_BR5;
#define LAT(x) if(x) GPIOC->BSRR = GPIO_BSRR_BS4; else GPIOC->BSRR = GPIO_BSRR_BR4;
#define SCK(x) if(x) GPIOB->BSRR = GPIO_BSRR_BS1; else GPIOB->BSRR = GPIO_BSRR_BR1;
#define SDA(x) if(x) GPIOA->BSRR = GPIO_BSRR_BS4; else GPIOA->BSRR = GPIO_BSRR_BR4;
#define ROW0(x) if(x) GPIOB->BSRR = GPIO_BSRR_BS2; else GPIOB->BSRR = GPIO_BSRR_BR2;
#define ROW1(x) if(x) GPIOA->BSRR = GPIO_BSRR_BS15; else GPIOA->BSRR = GPIO_BSRR_BR15;
#define ROW2(x) if(x) GPIOA->BSRR = GPIO_BSRR_BS2; else GPIOA->BSRR = GPIO_BSRR_BR2;
#define ROW3(x) if(x) GPIOA->BSRR = GPIO_BSRR_BS7; else GPIOA->BSRR = GPIO_BSRR_BR7;
#define ROW4(x) if(x) GPIOA->BSRR = GPIO_BSRR_BS6; else GPIOA->BSRR = GPIO_BSRR_BR6;
#define ROW5(x) if(x) GPIOA->BSRR = GPIO_BSRR_BS5; else GPIOA->BSRR = GPIO_BSRR_BR5;
#define ROW6(x) if(x) GPIOB->BSRR = GPIO_BSRR_BS0; else GPIOB->BSRR = GPIO_BSRR_BR0;
#define ROW7(x) if(x) GPIOA->BSRR = GPIO_BSRR_BS3; else GPIOA->BSRR = GPIO_BSRR_BR3;

void matrix_init(){
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN;        //CLOCK ENABLING
    
    /* GPIO MODER */
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER2_1) | GPIO_MODER_MODER2_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER3_1) | GPIO_MODER_MODER3_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER4_1) | GPIO_MODER_MODER4_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER5_1) | GPIO_MODER_MODER5_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER6_1) | GPIO_MODER_MODER6_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER7_1) | GPIO_MODER_MODER7_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER15_1) | GPIO_MODER_MODER15_0;

    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER0_1) | GPIO_MODER_MODER0_0;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER1_1) | GPIO_MODER_MODER1_0;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER2_1) | GPIO_MODER_MODER2_0;

    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER3_1) | GPIO_MODER_MODER3_0;
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER4_1) | GPIO_MODER_MODER4_0;
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER5_1) | GPIO_MODER_MODER5_0;

    /* High speed */
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2 | GPIO_OSPEEDER_OSPEEDR3 | GPIO_OSPEEDER_OSPEEDR4 |
                      GPIO_OSPEEDER_OSPEEDR5 | GPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR7 |
                      GPIO_OSPEEDER_OSPEEDR15;

    GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0 | GPIO_OSPEEDER_OSPEEDR1 | GPIO_OSPEEDER_OSPEEDR2;

    GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3 | GPIO_OSPEEDER_OSPEEDR4 | GPIO_OSPEEDER_OSPEEDR5;

    GPIOC->BSRR = GPIO_BSRR_BR_3;   // RST: 0 (reset DM163)
    GPIOC->BSRR = GPIO_BSRR_BS_4;   // LAT: 1
    GPIOC->BSRR = GPIO_BSRR_BS_5;   // SB: 1
    GPIOB->BSRR = GPIO_BSRR_BR_1;   // SCK: 0
    GPIOA->BSRR = GPIO_BSRR_BR_4;   // SDA: 0

    // Definir C0 a C7: 0 (éteint toutes les lignes)
    GPIOA->BSRR = GPIO_BSRR_BR_2 | GPIO_BSRR_BR_3 | GPIO_BSRR_BR_5 | GPIO_BSRR_BR_6 |
                    GPIO_BSRR_BR_7 | GPIO_BSRR_BR_15;
    GPIOB->BSRR = GPIO_BSRR_BR0 | GPIO_BSRR_BR2;

    GPIOC->BSRR = GPIO_BSRR_BS_3;   // RST: 1 (SET DM163)

    init_bank0();
}

void pulse_SCK(){
    SCK(0);
    SCK(1);
    SCK(0);
}

void pulse_LAT(){
    LAT(1);
    LAT(0);
    LAT(1);
}

void deactivate_rows() {
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);
}

void activate_row(int row){
    switch(row) {
        case 0: ROW0(1); break;
        case 1: ROW1(1); break;
        case 2: ROW2(1); break;
        case 3: ROW3(1); break;
        case 4: ROW4(1); break;
        case 5: ROW5(1); break;
        case 6: ROW6(1); break;
        case 7: ROW7(1); break;
        default: break;
    }
}

void send_byte(uint8_t val, int bank){
    SB(bank);
    uint8_t ctr = 5;
    if(bank) ctr = 7;
    for(int i = ctr; i >= 0; i--) {
        SDA((1<<i) & val);
        pulse_SCK();
    }
}

void mat_set_row(int row, const rgb_color *val){
    for(int i = 7; i >= 0; i--) {
        send_byte(val[i].b, 1);
        send_byte(val[i].g, 1);
        send_byte(val[i].r, 1);
    }
    deactivate_rows();
    for(uint8_t i = 0; i < 100; i++) asm volatile("nop");
    pulse_LAT();
    activate_row(row);
}

void init_bank0(){
    for(int i = 0; i < 24; i++) {       //24 since we fill send 6 bits at each send_byte call when dealing with bank 0
        send_byte(0xFF, 0);
    }
    pulse_LAT();
}

void test_pixels(){
    rgb_color val[8];
    for(int color = 0; color < 3; color++) {
        for(int intensity = 0; intensity < 256; intensity++) {
            for(int i = 0; i < 8; i++) {
                val[i].b = (color == 0) ? intensity : 0;
                val[i].g = (color == 1) ? intensity : 0;
                val[i].r = (color == 2) ? intensity : 0;
            }
            for(int row = 0; row < 8; row++) {
                mat_set_row(row, val);
                    for(uint32_t i = 0; i < 10000; i++) asm volatile("nop");
            }
        }
    }
}

uint8_t row = 0;
void test_image(const rgb_color *image){
    mat_set_row(row, &image[row * 8]);
    if (row == 7) row = 0;
    else row++;
}
