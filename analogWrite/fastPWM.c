/* fastPWM(pin, value) in avr-gcc                       */
/* This specific routine will deliver a Fast PWM signal     */
/* Frequency: 16MHz / 256 / 64 = 976.56Hz                   */
/* Pin 3/PD3 has a 50% duty cycle                           */
/* Pin 11/PB3 has a 25% duty cycle                          */
#include <avr/io.h>

int main (void)
{   
    // reset both timer/counters
    TCCR2A = 0;
    TCCR2B = 0; 
    // set UNO pin 3/PD3 and pin 11/PB3 to output
    DDRD |= _BV(DDD3);
    DDRB |= _BV(DDB3);
 
    // [ COM2A1 COM2A0 COM2B1 COM2B0 0 0 WGM21 WGM20 ] = %10100011
    TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
    // [ FOC2A FOC2B 0 0 WGM22 CS22 CS21 CS20 ] = %0100
    TCCR2B = _BV(CS22);
    OCR2A = 127;
    OCR2B = 63;
}
