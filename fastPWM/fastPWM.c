/* fastPWM: setup 8-bit Fast PWM using Timer/Counter 0                            

Timer 0 Configuration, 8bit Fast PWM p113-7
TCCR0A - Timer/Counter0 Control Register                 
[ COM0A1 COM0A0 COM0B1 COM0B0 0 0 WGM01 WGM00 ]          

TCCR0B - Timer/Counter0 Control Register                 
[ FOC0A FOC0B 0 0 WGM02 CS02 CS01 CS20 ]                 

COM0A1:0 = 10 => Clear OC0A on compare match (non-inverting)             
COM0B1:0 = 11 => Set OC0B on compare match (inverting)
WGM02:0 = 011 => Fast PWM, Update at Bottom, TOV=MAX   
CS02:0 = 101 = clkio / 011 scalar 011 => 1/64                          

PWM Pins p97   
ARD5 PD5 OC2B 8bit Timer/Counter 0 OCR0B                        
ARD6 PD6 OC2A 8bit Timer/Counter 0 OCR0A

Specific to parameters below                             
Frequency: 16MHz / 256 / 64 = 976.56Hz                  
Pin 5/PD5/OCR0B has a 50% duty cycle or 127/255                          
Pin 6/PD6/OCR0A has a 25% duty cycle or 63/255
*/
#include <avr/io.h>

int main (void)
{   
    // reset both timer/counters
    TCCR0A = 0;
    TCCR0B = 0; 
    // set UNO pin 5/PD5 and pin 6/PD6 to output
    DDRD |= _BV(DDD5);
    DDRD |= _BV(DDD6);
 
    // TCCR0A [ COM0A1 COM0A0 COM0B1 COM0B0 0 0 WGM21 WGM20 ] = 0b10110011
    TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(COM0B0) | _BV(WGM21) | _BV(WGM20);
    // TCCR0B [ FOC2A FOC2B 0 0 WGM22 CS22 CS21 CS20 ] = 0b00000011
    TCCR0B = _BV(CS21) | _BV(CS20);
    OCR0A = 63;
    OCR0B = 127;
}
