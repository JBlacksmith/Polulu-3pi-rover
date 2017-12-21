#ifndef SENSOR_DRIVER_H
#define SENSOR_DRIVER_H

#include <avr/io.h>
#include "adc_driver.h"
#include <stdbool.h>

#define SENSOR_DDR DDRC
#define SENSOR_PORT PORTC
#define SENSOR_PIN PINC
#define SENSOR_PULLUP PORTC


void initialize_sensor_driver();
void configure_sensor_input();
void configure_sensor_output();
void set_sensor_high();
void set_sensor_low();
uint8_t get_sensor_value();
int8_t weighted_sum_sensor_value( uint8_t sensor_array );




#endif