#include "mainHeader.h"
#include "LCD.h"


 void LCD_sendCommand(unsigned char command){
	 PORTD &= (~(1<<PD7));	// RS = 0
	 PORTD &= (~(1<<PD6));  // RW = 0

	 _delay_ms(1);
	 PORTD |= (1<<PD5);
	 _delay_ms(1);

	 PORTC = command;

	 _delay_ms(1);
	 PORTD &= (~(1<<PD5));
	 _delay_ms(1);

 }
 void LCD_Init(){
 	 DDRC=0XFF;
 	 DDRD|= (1<<5) | (1<<6) | (1<<7);
 	 LCD_sendCommand(0x38); //8-bit mode
 	 LCD_sendCommand(0x0C); // Display On
 	 LCD_sendCommand(0x01); // Clear Display
  }

 void LCD_sendData(unsigned char data){
	 PORTD |= (1<<PD7);	// RS = 1
	 PORTD &= (~(1<<PD6));  // RW = 0
	 _delay_ms(1);
	 PORTD |= (1<<PD5);
	 _delay_ms(1);

	 PORTC = data;

	 _delay_ms(1);
	 PORTD &= (~(1<<PD5));
	 _delay_ms(1);
 }

 void LCD_sendString(const char *Str){
	int i = 0;
	while(Str[i] != '\0')
	{
		LCD_sendData(Str[i]);
		i++;
	}
 }

 void LCD_goToRowCol(int grow, int gcol){
	 int Address;
	 switch(grow){
	 case 0: Address = gcol;
	 	 break;
	 case 1: Address =gcol+ 0x40;
	 	 break;
	 case 2: Address =gcol+0x10;
	 	 break;
	 case 3: Address = gcol+0x50;
	 	 break;
	 default: Address =gcol;
	 }
	 LCD_sendCommand(Address | 0x80); //start from the first place plus the Address
 }




 void LCD_intgerToString(int data)
 {
    char buff[16]; /* String to hold the ascii result */
    itoa(data,buff,10); /* 10 for decimal */
    LCD_sendString(buff);
 }
