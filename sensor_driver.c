/* Implementation of Sensor Driver */
/* sensor_driver.c */

#include <avr/io.h>
#include <stdbool.h>
#include "sensor_driver.h"


#define SENSOR_DDR DDRC
#define SENSOR_PORT PORTC
#define SENSOR_PIN PINC
#define SENSOR_PULLUP PORTC

#define LEFT_SENSOR 0x01
#define LEFT_MIDDLE_SENSOR 0x02
#define MIDDLE_SENSOR 0x04
#define RIGHT_MIDDLE_SENSOR 0x08
#define RIGHT_SENSOR 0x10

void initialize_sensor_driver()
{
	SENSOR_DDR |= 0x1F; //all outputs
	SENSOR_PORT &= ~(0x1F); //init to low
}
void configure_sensor_input()
{
	SENSOR_DDR &= ~(0x1F); 
}
void configure_sensor_output()
{
	SENSOR_DDR |= (0x1F); 
}
void set_sensor_high()
{
	SENSOR_PORT |=  (0x1F); 
}
void set_sensor_low()
{
	SENSOR_PORT &=  ~(0x1F); 
}
uint8_t get_sensor_value()
{
	configure_sensor_output(); 
	set_sensor_high(); 
	_delay_us(10); 
	configure_sensor_input();
	set_sensor_low(); 
	_delay_us(300); 
	uint8_t current_val = SENSOR_PIN & 0x1F;
	return current_val;
}

int8_t weighted_sum_sensor_value( uint8_t sensor_array )
{
	int8_t sum = 0;
	if(( sensor_array & LEFT_SENSOR) == LEFT_SENSOR  )
		sum += -2;
	if(( sensor_array & LEFT_MIDDLE_SENSOR) == LEFT_MIDDLE_SENSOR)
		sum += -1;
	if( (sensor_array & MIDDLE_SENSOR) == MIDDLE_SENSOR)
		sum += 0;
	if( (sensor_array & RIGHT_MIDDLE_SENSOR) == RIGHT_MIDDLE_SENSOR)
		sum += 1;
	if( (sensor_array & RIGHT_SENSOR) == RIGHT_SENSOR)
		sum += 2;

	return sum;
}


