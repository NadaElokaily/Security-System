#include "UART.h"

void UART_Init(){
	UCSRA = (1<<U2X);
	UCSRB = (1<<TXEN)|(1<<RXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRH = (103>>8);
	UBRRL = (103);
}
void UART_SendByte(char sent){
	while(BIT_IS_CLEAR(UCSRA,UDRE)){};
	UDR=sent;
}
char UART_RecieveByte(){

	while(BIT_IS_CLEAR(UCSRA,RXC)){};
	return UDR;
}

void UART_SendString(const char * sent){
	int i =0;
	while (sent[i]!= '\0'){
		UART_SendByte(sent[i]);
		i++;
	}
}

void UART_RecieveString(char * buffer){

	int i=0;
	buffer[i]=UART_RecieveByte();
	while(buffer[i]!='#'){
		i++;
		buffer[i]=UART_RecieveByte();
	}
	buffer[i]='\0';
}
