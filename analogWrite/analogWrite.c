/* analogWrite(pin, n): setup the Timer/Counters to provide a PWM signal
Parameters:
* pin = Arduino UNO Pin Number, must have a "~" in its name (3, 5, 6, 9, 10, 11)
* n = n/255 Duty Cycle, i.e; n=127, 127/255 = 49.8% duty cycle
### Pin PWM Frequencies
UNO pin 3/PD3, 488.3Hz
UNO pin 5/PD5, 976.6Hz
UNO pin 6/PD6, 976.6Hz
UNO pin 9/PB1, 976.6Hz
UNO pin 10/PB2, 976.6Hz
UNO pin 11/PB3, 488.3Hz

Arduino     ATmega328   Register    Timer   # bits  Control Registers
3           PD3         OC2B        2       8       TCCR2A/TCCR2B
5           PD5         OC0B        0       8       TCCR0A/TCCR0B
6           PD6         OC0A        0       8       TCCR0A/TCCR0B
9           PB1         OC1A        1       16      TCCR1A/TCCR1B
10          PB2         OC1B        1       16      TCCR1A/TCCR1B
11          PB3         OC2A        2       8       TCCR2A/TCCR2B                        

Timer Configurations
TCCRnA - Timer/Counter Control Register A                 
[ COM0A1 COM0A0 COM0B1 COM0B0 0 0 WGM01 WGM00 ]          

TCCRnB - Timer/Counter0 Control Register B               
[ FOC0A FOC0B 0 0 WGM02 CS02 CS01 CS20 ]                 

0. Clear all Timer/Counter Registers
1. Set pin to be output pin
2. Setup Timer Register A 
3. Setup Timer Register B
*/

// #define delay 500
// #include <avr/io.h>
// #include <util/delay.h>
#include "analogWrite.h"

int main (void)
{   
    clear_all_TC();

    short int ard, duty_cycle;

    ard = 6;
    duty_cycle = 127; // 127 = 50%
    if (analogWrite(ard, duty_cycle)) {
        blink(2);
    }

    ard = 5;
    duty_cycle = 63; // 63 = 25%
    if (analogWrite(ard, duty_cycle)) {
        blink(4);
    }
    off_led();
}
