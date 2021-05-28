  
#include<avr/io.h>

void main()
{ 
  DDRD=0b00000000;
  DDRB=0b11111111;
  PORTD=0b11111111;
  int c;
  while (1)
  { 
    c=PIND;
	if(c==0b11111101)          //low and high
	   PORTB=0b00001001;       //forward and reverse
	if(c==0b11111110)          //high and low
	   PORTB=0b00000110;       //reverse and forward    
	if(c==0b11111100)          //low and low
	   PORTB=0b00001010;       //forward all
	if(c==0b11111111)          //high and high
	   PORTB=0b00011010;       //beep and move forward


   } 
}
