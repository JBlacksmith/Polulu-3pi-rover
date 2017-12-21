/*
   Author : Jason Smith
 */
 
#ifndef MOTORS_H
#define MOTORS_H
#include <stdint.h>
#include <avr/io.h>
#define LEFT_MOTOR_A_LOC 6
#define LEFT_MOTOR_A_PORT D
#define LEFT_MOTOR_B_LOC 5
#define LEFT_MOTOR_B_PORT D
#define RIGHT_MOTOR_A_LOC 6
#define RIGHT_MOTOR_A_PORT D
#define RIGHT_MOTOR_B_LOC 5
#define RIGHT_MOTOR_B_PORT D
#define LEFT_MOTOR_TIMER 0
#define RIGHT_MOTOR_TIMER 2

#define FULL_SPEED 0xFF
#define HALF_SPEED 0x80
#define QUARTER_SPEED 0x40
#define TENTH_SPEED 0x1A

void initialize_left_motor();
void brake_left_motor();
void coast_left_motor();
void engage_left_motor_forward();
void engage_left_motor_reverse();
void set_left_motor_duty_cycle(uint8_t duty_cycle);
uint8_t get_left_motor_duty_cycle();
void initialize_right_motor();
void brake_right_motor();
void coast_right_motor();
void engage_right_motor_forward();
void engage_right_motor_reverse();
void set_right_motor_duty_cycle(uint8_t duty_cycle);
uint8_t get_right_motor_duty_cycle();

#endif
