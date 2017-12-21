/*
   Author : Jason Smith
 */ 
#include "pushbutton.h"


bool left_button_is_pressed(){
	return(PUSHBUTTON_PIN & (1 << LEFT_BUTTON_LOC)) == 0;
}

bool middle_button_is_pressed(){
	return(PUSHBUTTON_PIN & (1 << MIDDLE_BUTTON_LOC)) == 0;
}

bool right_button_is_pressed(){
	return(PUSHBUTTON_PIN & (1 << RIGHT_BUTTON_LOC)) == 0;
}

bool any_button_is_pressed(){
	return left_button_is_pressed() || right_button_is_pressed() || middle_button_is_pressed();
}

void initialize_pushbutton_array(){
	PUSHBUTTON_DDR &= ~((1 << LEFT_BUTTON_LOC)|(1<<RIGHT_BUTTON_LOC)|(1 << MIDDLE_BUTTON_LOC));
	PUSHBUTTON_PULLUP |= ((1 << LEFT_BUTTON_LOC)|(1 << RIGHT_BUTTON_LOC)|(1 << MIDDLE_BUTTON_LOC));
}
