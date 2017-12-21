/*
   Author : Jason Smith
 */
#include "leds.h"

void initialize_red_led(){
	LEDS |= (1 << RED_LED_LOC);
}

void initialize_green_led(){
	LEDS |= (1 << GREEN_LED_LOC);
}

uint8_t turn_on_red_led(){
	return LEDS |= (1 << RED_LED_LOC);
}
uint8_t turn_off_red_led(){
	return LEDS &= ~(1 << RED_LED_LOC);
}
uint8_t turn_on_green_led(){
	return LEDS |= (1 << GREEN_LED_LOC);
}
uint8_t turn_off_green_led(){
	return LEDS &= (1 << GREEN_LED_LOC);
}
uint8_t toggle_red_led(){
	return LEDS ^= (1 << RED_LED_LOC);
}
uint8_t toggle_green_led(){
	return LEDS ^= (1 << GREEN_LED_LOC);
}
