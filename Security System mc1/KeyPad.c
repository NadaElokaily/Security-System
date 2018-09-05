#include "KeyPad.h"


int keyPressesd(){
	int col , row;
	while(1){
		for(col=0;col<3;col++){

			DDRA|=(0b00100000<<col);
			PORTA = (~(0b00100000<<col));

			for(row=0;row<4;row++){
				if( (PINA&(1<<row)) == 0){
				return adjustKeyPressed((row*3)+col+1);
				}
			}
		}
	}
}

 int adjustKeyPressed(int keyVal){
	switch(keyVal){
		case 10 : return '*';
				  break;
		case 11 : return 0 ;
				  break;
		case 12 : return '#' ;
				  break;
		default: return keyVal;
	}
}
