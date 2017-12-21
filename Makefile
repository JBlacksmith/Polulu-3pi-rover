F_CPU = 20000000
MCU = atmega328p
CCOPTS= -g -Wall -Os -std=c99


all: program program3

pushbutton.o: pushbutton.c pushbutton.h 
	avr-gcc -c $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) pushbutton.c -o pushbutton.o

leds.o: leds.c leds.h 
	avr-gcc -c $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) leds.c -o leds.o
motors.o: motors.c motors.h
	avr-gcc -c $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) motors.c -o motors.o

program3: program3.c motors.o pushbutton.o leds.o
	avr-gcc  $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -o program3 -g program3.c motors.o pushbutton.o leds.o

program3.hex: program3
	avr-strip program3 
	avr-objcopy -R .eeprom -O ihex program3 program3.hex

program: program3.hex
	avrdude -p m328p -c avrisp2 -P /dev/ttyACM0 -U flash:w:program3.hex

clean:
	-rm -f program3 program3.hex motors.o pushbutton.o leds.o

