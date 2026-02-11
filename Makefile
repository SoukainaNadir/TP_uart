cc = avr-gcc
CFLAGS = -Os -DF_CPU=1000000UL -mmcu=attiny85
EXE = main


.PHONY: clean flash all
OBJ_FILES = $(C_SRCS:.c=.o)


all: $(EXE).hex

$(EXE).elf: main.c
	$(cc) $(CFLAGS) main.c -o $(EXE).elf

$(EXE).hex: $(EXE).elf
	avr-objcopy -O ihex $(EXE).elf $(EXE).hex

flash: $(EXE).hex
	avrdude -c avrisp -p attiny85 -b 19200 -P /dev/ttyACM0 -U flash:w:$(EXE).hex

clean:
	rm -f *.elf *.hex

