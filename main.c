#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define TX PB4
#define BIT_US 3333


void uart_char(char c)
{
	// START bit
	PORTB &= ~(1 << TX);
	_delay_us(BIT_US);
	
	// 8 bits
	for (int i = 0; i < 8; i++)
	{
	    if (c & 1)
			PORTB |= (1 << TX); // Si bit = 1 → sortie HIGH
	    else
			PORTB &= ~(1 << TX); // Si bit = 0 → sortie LOW

	    _delay_us(BIT_US);

	    c >>= 1;	// Décaler le caractère vers la droite
					// pour envoyer le bit suivant
	}
	//STOP Bit
	PORTB |= (1 << TX);
	_delay_us(BIT_US);
	
	
}


void uart(const char *str)
{
	int len = strlen(str);
  	for(int i = 0; i < len; ++i) 
  	{
  		uart_char(str[i]);
  	}
}

int main(void)
{
	DDRB  |= (1 << TX);     // TX en sortie
  	PORTB |= (1 << TX); 	// HIGH
	
	while(1)
	{
		
		uart("coucou\n\r");
		_delay_ms(1000);
        	
	}
	
}
