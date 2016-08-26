RM=rm -f
PORT=/dev/ttyUSB0

blink.hex: blink.elf
	avr-objcopy -O ihex blink.elf blink.hex


blink.elf: blink.o
	avr-gcc -DF_CPU=16000000UL -mmcu=atmega328p -o blink.elf blink.o

blink.o: blink.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink.o blink.c

install: blink.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P $(PORT) -b 57600 -U flash:w:blink.hex
clean:
	$(RM) blink.elf blink.hex blink.o
	
