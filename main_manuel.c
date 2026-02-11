#include <avr/io.h>
#include <util/delay.h>

#define TX PB4
#define BIT_US 3333 


int main(void)
{
	DDRB  |= (1 << TX);     // TX en sortie
  	PORTB |= (1 << TX); 	// HIGH
	
	while(1)
	{
		char c = 'A';
		
		// START bit
		PORTB &= ~(1 << TX);
		_delay_us(BIT_US);
		
		// 8 bits
		for (uint8_t i = 0; i < 8; i++)
		{
		    if (c & 1)
			PORTB |= (1 << TX);
		    else
			PORTB &= ~(1 << TX);

		    _delay_us(BIT_US);
		    c >>= 1;
		}
		//STOP Bit
		
		PORTB |= (1 << TX);
        	_delay_us(BIT_US);
        	
        	_delay_us(1000);
        	
	}
	
}
