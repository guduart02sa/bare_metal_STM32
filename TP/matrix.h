#ifndef MATRIX_H
#define MATRIX_H

#define STM32L475xx

#include <stddef.h>
#include <stdint.h>
#include <stm32l4xx.h>

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb_color;

void matrix_init();
void test_pixels();
void init_bank0();
void test_image(const rgb_color *image);

#endif