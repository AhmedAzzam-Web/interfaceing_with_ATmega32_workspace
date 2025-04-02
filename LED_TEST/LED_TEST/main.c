/*
 * LED_TEST.c
 *
 * Created: 3/30/2025 12:32:04 AM
 * Author : Ahmed Azzam
 */ 

#include <avr/io.h>

#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
    /* Configure OUTPUT pins */
	DDRA = 0b00000001;
	
	/* Configure 7-segment display for cathode which means dot pin (pin 8) connected to ground for DDRD*/
	DDRD = 0b11111111;
	
	/* Turn on the led by writing 1 on the led to output voltage */
    while (1) 
    {
		/* ON states */		
		PORTA = 0b00000001;
		PORTD = 0b01111111;
		_delay_ms(1000);
		
		/* OFF states */
		PORTA = 0b00000000;
		PORTD = 0b00000000;
		_delay_ms(1000);
		}					
}

