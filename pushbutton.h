/*
   Author : Jason Smith
 */
#ifndef PUSHBUTTON_H
	#define PUSHBUTTON_H
	#include <stdint.h>
	#include <stdbool.h>
	#include <avr/io.h>
	#define PUSHBUTTON_DDR DDRB
	#define PUSHBUTTON_PORT PORTB
	#define PUSHBUTTON_PIN PINB
	#define PUSHBUTTON_PULLUP PORTB
	#define LEFT_BUTTON_LOC 1
	#define MIDDLE_BUTTON_LOC 4
	#define RIGHT_BUTTON_LOC 5

	void initialize_pushbutton_array();
	bool left_button_is_pressed();
	bool right_button_is_pressed();
	bool middle_button_is_pressed();
	bool any_button_is_pressed();
#endif
