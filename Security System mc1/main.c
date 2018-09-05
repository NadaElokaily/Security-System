/*
 * main.c
 *
 *  Created on: Aug 25, 2018
 *      Author: leenovoz510
 */
#include "mainHeader.h"
#include "KeyPad.h"
#include "LCD.h"
#include "UART.h"

const char password[4]="1996";
int main(void){
	LCD_Init();
	UART_Init();
	UART_SendByte('X');
	_delay_ms(50);
	while(1){
			LCD_goToRowCol(0,0);
			LCD_sendCommand(0x01);
			LCD_sendString("Enter Password");
			static int keyVal;
			char givenPassword[4]="";
			int flag =0;
			char tempKeyVal[1]="";

			int i=0;
			while(1){
				LCD_goToRowCol(1,0);
				keyVal = keyPressesd();
				_delay_ms(200);
				if(keyVal == 42){
					LCD_goToRowCol(2,i++);
					LCD_sendString("*");
				}else if(keyVal == 35){
					LCD_goToRowCol(2,i++);
					LCD_sendString("#");
				}else{
					LCD_goToRowCol(2,i);
					LCD_intgerToString(keyVal);
					_delay_ms(70);
					itoa(keyVal,tempKeyVal,10);
					givenPassword[i]=tempKeyVal;
					LCD_goToRowCol(2,i);
					LCD_sendString("*");

					i++;
				}
				if (password[i-1]== tempKeyVal[0]){
					flag=1;
				}
				else{
					flag=0;
				}
				if (i==4){
					if (flag==1){
						flag=0;
						UART_SendByte('O');
						_delay_ms(50);
						LCD_sendCommand(0x01);
						LCD_goToRowCol(0,0);
						LCD_sendString("Door Open for 2 seconds");
						_delay_ms(2000);
						break;
					}
					else{
						UART_SendByte('X');
						_delay_ms(50);
						LCD_sendCommand(0x01);
						LCD_goToRowCol(0,0);
						LCD_sendString("Try Again!!");
						_delay_ms(200);
						break;
					}
				}
	}



	}

return 0;
}

