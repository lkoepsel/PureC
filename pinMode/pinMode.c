#include <util/delay.h>
#include <avr/io.h>

#define BLINK_DELAY_MS 1000
#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

void off_led ()
{
    // Set the built-in LED PB5 to be an output
    DDRB |= _BV(DDB5);
    PORTB &= ~(_BV(PORTB5));
}

void on_led ()
{
    // Set the built-in LED PB5 to be an output
    DDRB |= _BV(DDB5);
    PORTB |= (_BV(PORTB5));
}

short int pinMode(short int apin, short int mode) {
    short int errno = 0;
    switch (apin) {
        case 0:
        if (mode == INPUT) {
            DDRD &= ~_BV(DDD0);
        }
        else if (mode == OUTPUT) {
            DDRD |= _BV(DDD0);
        }
        else if (mode == INPUT_PULLUP) {
            DDRD &= ~_BV(DDD0);
            PORTD |= _BV(DDD0);
        }
        else {
            errno = 1;
        }
        break;
        case 1:
        if (mode == INPUT) {
            DDRD &= ~_BV(DDD1);
        }
        else if (mode == OUTPUT) {
            DDRD |= _BV(DDD1);
        }
        else if (mode == INPUT_PULLUP) {
            DDRD &= ~_BV(DDD1);
            PORTD |= _BV(DDD1);
        }
        else {
            errno = 1;
        }
        break;
        case 2:
        if (mode == INPUT) {
            DDRD &= ~_BV(DDD2);
        }
        else if (mode == OUTPUT) {
            DDRD |= _BV(DDD2);
        }
        else if (mode == INPUT_PULLUP) {
            DDRD &= ~_BV(DDD2);
            PORTD |= _BV(DDD2);
        }
        else {
            errno = 1;
        }
        break;
        case 3:
        if (mode == INPUT) {
            DDRD &= ~_BV(DDD3);
        }
        else if (mode == OUTPUT) {
            DDRD |= _BV(DDD3);
        }
        else if (mode == INPUT_PULLUP) {
            DDRD &= ~_BV(DDD3);
            PORTD |= _BV(DDD3);
        }
        else {
            errno = 1;
        }
        break;
        case 4:
        if (mode == INPUT) {
            DDRD &= ~_BV(DDD4);
        }
        else if (mode == OUTPUT) {
            DDRD |= _BV(DDD4);
        }
        else if (mode == INPUT_PULLUP) {
            DDRD &= ~_BV(DDD4);
            PORTD |= _BV(DDD4);
        }
        else {
            errno = 1;
        }
        break;
        case 5:
        if (mode == INPUT) {
            DDRD &= ~_BV(DDD5);
        }
        else if (mode == OUTPUT) {
            DDRD |= _BV(DDD5);
        }
        else if (mode == INPUT_PULLUP) {
            DDRD &= ~_BV(DDD5);
            PORTD |= _BV(DDD5);
        }
        else {
            errno = 1;
        }
        break;
    }
    return(errno);
}  

int main (void)
{
    off_led();
    pinMode(3, OUTPUT);
    PORTD |= _BV(DDD3);
    _delay_ms(BLINK_DELAY_MS);
    PORTD &= ~_BV(DDD3);
    _delay_ms(BLINK_DELAY_MS);
    on_led();
}
