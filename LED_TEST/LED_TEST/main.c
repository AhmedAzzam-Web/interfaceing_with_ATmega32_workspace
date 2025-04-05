#include <avr/io.h>

#include "../../../interfaceing_with_ATmega32_workspace/LIB/BIT_MATH.h"
#include "../../../interfaceing_with_ATmega32_workspace/LIB/STD_TYPES.h"

#define F_CPU 8000000
#include <util/delay.h>

// macros for PIN usage
#define LED_BTN_DDR DDRA
#define LED_BTN_PORT PORTA
#define LED_PIN PA0

#define SEG_DDR DDRD
#define SEG_PORT PORTD
#define BTN_PINR PINA
// R stands for register
#define BTN_PIN PA1

// Macros for 7-segment display
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
	LED_BTN_DDR = 0b00000001;
	
	/* Configure 7-segment display for cathode which means dot pin (pin 8) connected to ground for DDRD*/
	SEG_DDR = 0b11111111; // ===  DDRD = 255 this will make them all output
	
	/* Turn on the led by writing 1 on the led to output voltage */
    while (1) 
    {
		/* Set all states off if input button is not clicked (0) and on if input button is clicked ... PORTA 1 to fire up internal pull up resistor */
		LED_BTN_PORT = 0b11111110;
		
		if ((BTN_PINR & 0b00000010) == 0)
		{
			_delay_ms(50); // debounce
			// Check if A1 is connected to the ground
			if ((BTN_PINR & (1 << BTN_PIN)) == 0){
				for (u8 i = 0; i < 10; i++)
				{
					/* ON states */
					PORTA = 0b11111111;
					SEG_PORT = segment[i];
					_delay_ms(500);
					
					/* OFF states */
					CLR_BIT(PORTA, PA0);
					SET_BIT(PORTA, PA1);
					SEG_PORT = 0b00000000;
					_delay_ms(500);
				}
			}
		}
	}					
}

