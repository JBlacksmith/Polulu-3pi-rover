#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "pushbutton.h"
#include "adc_sampling_driver.h"
#include "motors.h"

int main(){
	initialize_pushbutton_array();
	initialize_left_motor();
	initialize_right_motor();
}