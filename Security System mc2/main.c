/*
 * main.c
 *
 *  Created on: Aug 25, 2018
 *      Author: leenovoz510
 */
#include "mainHeader.h"
#include "LCD.h"
#include "UART.h"
#include "PWM_Timer0.h"

const char password[5]="19965";
int main(void){
	UART_Init();
	DDRD |= (1<<PD2);
	DDRB &= ~(1<<PB0);
	//PORTB |= (1<<PB0);
	while(1){
		if(UART_RecieveByte() == 'O'){
			PORTD |= (1<<PD2);
			_delay_ms(30);
			PWM_Timer0_Init(124);
			_delay_ms(1500);
			PWM_Timer0_Init(187);
			_delay_ms(500);
			PORTD &= ~(1<<PD2);

		}
	}

return 0;
}

