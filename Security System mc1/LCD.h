/*
 * LCD.h
 *
 *  Created on: Aug 25, 2018
 *      Author: leenovoz510
 */

#ifndef LCD_H_
#define LCD_H_

void LCD_Init();
void LCD_sendCommand(unsigned char command);
void LCD_sendData(unsigned char data);
void LCD_sendString(const char * Str);
void LCD_goToRowCol(int grow, int gcol);
void LCD_intgerToString(int data);


#endif /* LCD_H_ */
