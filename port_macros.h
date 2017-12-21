#ifndef PORT_MACROS_H
	#define PORT_MACROS_H
	#define CONCATENATE(A,B) A##B
	#define CONCAT3(A,B,C) A##B##C
	#define PORT(letter) CONCATENATE(PORT, letter)
	#define DDR(letter) CONCATENATE(DDR, letter)
	#define PULLUP(letter) CONCATENATE(PORT, letter)
	#define PIN(letter) CONCATENATE(PIN, letter)
	#define TOGGLE(letter) CONCATENATE(PIN, letter)
	#define TCCRA(NUMBER) CONCAT3(TCCR, NUMBER, A)
	#define TCCRB(NUMBER) CONCAT3(TCCR, NUMBER, B)
	#define OCRA(NUMBER) CONCAT3(OCR, NUMBER, A)
	#define OCRB(NUMBER) CONCAT3(OCR, NUMBER, B)
#endif
