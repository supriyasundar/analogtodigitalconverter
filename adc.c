#include<avr/io.h>
#include<util/delay.h>
void init_adc()

{
 ADCSRA=ADCSRA|(0b00000001<<ADEN);
ADCSRA=ADCSRA|(0b00000001<<ADPS2);
ADMUX=ADMUX|(0b00000001<<REFS0);
}
unsigned int read_adc()
{
 int p=0b00000000;
ADMUX=ADMUX|p;
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
unsigned int p;
unsigned int T;
unsigned int TON;
unsigned int TOFF;
while(1)
{
p=read_adc();
a=(p/40);
T=25.6;
TOFF=a;
TON=T-TOFF;
if (p<786)
{
PORTB=0b00001010;
_delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);
}
else
PORTB=0b00000000;
}
}
