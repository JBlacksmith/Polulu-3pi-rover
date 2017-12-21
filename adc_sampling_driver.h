#ifndef ADC_SAMPLING_DRIVER_H
#define ADC_SAMPLING_DRIVER_H
#include <avr/io.h>
#include <stdint.h>

//DIRVER CONFIGURATION
#define ADC_CHANNEL_SOURCE 4
#define NUMBER_SAMPLES_STORED 16 //power of 2 most efficient
#define SAMPLING_RATE_HZ 80

//choose closest supported sampling rate
#if SAMPLING_RATE_HZ  > F_CPU/256
	#define TIMER_PRESCALE 1
	#define TIMER_TOP (F_CPU / SAMPLING_RATE_HZ )
#elif SAMPLING_RATE_HZ > F_CPU/8/256
	#define TIMER_PRESCALE 2
	#define TIMER_TOP (F_CPU / (2*SAMPLING_RATE_HZ) )
#elif SAMPLING_RATE_HZ > F_CPU/64/256
	#define TIMER_PRESCALE 3
	#define TIMER_TOP (F_CPU / (64*SAMPLING_RATE_HZ) )
#elif SAMPLING_RATE_HZ > F_CPU/256/256
	#define TIMER_PRESCALE 4
	#define TIMER_TOP (F_CPU / (256*SAMPLING_RATE_HZ) )
#elif SAMPLING_RATE_HZ > F_CPU/1024/256
	#define TIMER_PRESCALE 5
	#define TIMER_TOP (F_CPU / (1024*SAMPLING_RATE_HZ) )
#else
	#error "SAMPLING RATE TOO LOW"
#endif
#endif