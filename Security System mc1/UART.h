/*
 * UART.h
 *
 *  Created on: Aug 29, 2018
 *      Author: leenovoz510
 */

#ifndef UART_H_
#define UART_H_
#include "mainHeader.h"
void UART_Init();
void UART_SendByte(char sent);
char UART_RecieveByte();
void UART_SendString(const char * sent);
void UART_RecieveString(char * buffer);




#endif /* UART_H_ */
