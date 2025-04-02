/*
 * LED_TEST.c
 *
 * Created: 3/30/2025 12:32:04 AM
 * Author : Ahmed Azzam
 */ 

#include <avr/io.h>

#include "../../../interfaceing_with_ATmega32_workspace/LIB/BIT_MATH.h"
#include "../../../interfaceing_with_ATmega32_workspace/LIB/STD_TYPES.h"

#define F_CPU 8000000
#include <util/delay.h>

#define ZERO 0b00111111 
#define ONE 0b00000110
#define TWO 0b01011011
#define THREE 0b01001111 
#define FOUR 0b01100110
#define FIVE 0b01101101
#define SIX 0b01111101 
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE 0b01101111

int main(void)
{
	u8 segment[10] = {ZERO , ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
	/* Configure OUTPUT pins for the led*/
	DDRA = 0b00000001;
	
	/* Configure 7-segment display for cathode which means dot pin (pin 8) connected to ground for DDRD*/
	DDRD = 0b11111111; // ===  DDRD = 255 this will make them all output
	
	/* Turn on the led by writing 1 on the led to output voltage */
    while (1) 
    {
		for (u8 i = 0; i < 10; i++)
		{
			/* ON states */
			PORTA = 0b00000001;
			PORTD = segment[i];
			_delay_ms(500);
			
			/* OFF states */
			PORTA = 0b00000000;
			PORTD = 0b00000000;
			_delay_ms(500);
		}
	}					
}

