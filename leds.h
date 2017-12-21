/*
   Author : Jason Smith
 */
#ifndef LEDS_H
#define LEDS_H
#include <stdint.h>
#include <avr/io.h>
#define LEDS PORTD
#define RED_LED_LOC 7
#define GREEN_LED_LOC 1

void initialize_red_led();
void initialize_green_led();
uint8_t turn_on_red_led();
uint8_t turn_off_red_led();
uint8_t turn_on_green_led();
uint8_t turn_off_green_led();
uint8_t toggle_red_led();
uint8_t toggle_green_led();

#endif