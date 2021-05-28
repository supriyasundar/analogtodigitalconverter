#include<avr/io.h>
#include<util/delay.h>
void init_adc()

{
 ADCSRA=ADCSRA|(0b00000001<<ADEN);
ADCSRA=ADCSRA|(0b00000001<<ADPS2);
ADMUX=ADMUX|(0b00000001<<REFS0);
}
unsigned int read_adc1()
{
 int p=0b00000000;
ADMUX&=0b11111000;
ADMUX=ADMUX|p;
ADCSRA|=(1<<ADSC);
while((ADCSRA&(0b00000001<<ADIF))==0)
{}
ADCSRA=ADCSRA|(0b00000001<<ADIF);
return(ADC);

}
unsigned int read_adc2()
{ 
int q =0b00000001;
ADMUX&=0b11111000;
ADMUX=ADMUX|q;
ADCSRA|=(1<<ADSC);
while((ADCSRA&(0b00000001<<ADIF))==0)
{}
ADCSRA=ADCSRA|(0b00000001<<ADIF);
return(ADC);
}

void main()
{
 DDRB=0b11111111;
init_adc();
_delay_ms(50);
unsigned int a;
unsigned int b;
unsigned int q;
unsigned int p;
unsigned int T;
unsigned int TON;
unsigned int TOFF;
unsigned int TON1;
unsigned int TOFF1;
unsigned int TON2;
unsigned int TOFF2;

while(1)
{
p=read_adc1();
q=read_adc2();
a=(p/40);
b=(q/40);
T=25.6;
TOFF1=a;
TON1=T-TOFF1;
TOFF2=b;
TON2=T-TOFF2;
TON=TON1+TON2;
if (p<786 & q<786)
{
PORTB=0b00001010;
_delay_ms(TON);

}
else if  (p<786)
{
PORTB=0b00001001;
_delay_ms(TON1);

}
else if  (q<786)
{
PORTB=0b00000110;
_delay_ms(TON2);

}
else                
PORTB=0b00000000;

}
}
