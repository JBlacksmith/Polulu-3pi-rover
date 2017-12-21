#include "adc_sampling_driver.h"
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#define FIFO_SIZE NUMBER_SAMPLES_STORED
uint8_t fifo[FIFO_SIZE];
uint8_t head, tail, overflow;

#define ADC_TRIGGER_ON_TIMER0_OVERFLOW 4
#define VREF_AVCC 2


void initialize_adc_driver()
{
	head=0; tail=0, overflow=0;
	//set up timer
	TCCR0A=(0<<COM0A0)|(0<<COM0B0)|(2<<WGM00); //CTC mode
	TCCR0B=TIMER_PRESCALE;
	OCR0A=TIMER_TOP;
	
	//set up adc
	ADMUX = (VREF_AVCC<<REFS0) | (1<<ADLAR) | ADC_CHANNEL_SOURCE;
	ADCSRA = (1<<ADEN)|(1<<ADATE)|(1<<ADIE)|(7<<ADPS0);
	ADCSRB = ADC_TRIGGER_ON_TIMER0_OVERFLOW;
}


void fifo_add_item( uint8_t val)
{
	head=(head+1)%FIFO_SIZE;
	if( head == tail )
	{
		tail=(tail+1)%FIFO_SIZE;
		overflow=1;
	}
	fifo[head]=val;
}
bool fifo_empty()
{
	return head == tail;
}
uint8_t fifo_remove_item( void) 
{
	uint8_t retval;
	sei();
	retval=fifo[tail];
	if( !fifo_empty() )
		tail=(tail+1)%FIFO_SIZE;
	cli();
	return retval;
}
ISR( ADC_vect)
{
	fifo_add_item( ADCH );
}