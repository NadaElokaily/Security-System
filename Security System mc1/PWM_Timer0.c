#include "PWM_Timer0.h"

void PWM_Timer0_Init (unsigned char dutyCycle){
	TCNT0  = 0;
	OCR0   = dutyCycle;
	DDRB  |= (1<<PB3);
	TCCR0 |= (1<<COM00)|(1<<COM01)| (1<<WGM00)|(1<<WGM01);
}
