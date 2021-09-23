#include "avr_uno.h"
#include "pinMode.h"
#include "digitalWrite.h"
 
#define BLINK_DELAY_MS 200
 
int main (void)
{
 /* set Uno LED to output*/
 pinMode(13, OUTPUT);
 
 while(1) {
  /* turn led on */
  digitalWrite(13, HIGH);
  _delay_ms(BLINK_DELAY_MS);
 
  /* turn led off */
  digitalWrite(13, LOW);
  _delay_ms(BLINK_DELAY_MS);
 }
}
