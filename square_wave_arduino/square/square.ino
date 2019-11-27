#include <util/delay.h>
/*
 *  https://www.nongnu.org/avr-libc/user-manual/group__util__delay.html 
 * 
 *  void _delay_us ( double  __us  ) 
 *  
 *  Perform a delay of __us microseconds, using _delay_loop_1().
 *  1sec = 1 000 000 microseconds
 *  
 *  
 *  4000 =  125Hz
 *  2000 =  250Hz
 *  1000 =  500HZ
 *  500  =  996Hz
 *  498  = 1000Hz
 * 
 *  void _delay_ms  ( double  __ms  ) 
 *  
 *  Perform a delay of __ms milliseconds, using _delay_loop_2().
 *  1sec = 1 000 milliseconds
 *  
 *  4.0   = 125Hz
 *  2.0   = 250Hz   using assembly
 *  0.995 = 500Hz   using assembly
 *  0.490 =1000Hz   using assembly
 *      
 */




void setup() 
{
  // put your setup code here, to run once:
  
  //pinMode(10,OUTPUT);
  DDRB |= 0B00000100;
  cli();
  TIMSK0 &= ~(1<<TOIE0);
  sei();
}

void loop() 
{
  //digitalWrite(10,HIGH);
  //cli();
  //noInterrupts();
  PORTB |= 0B00000100;
  _delay_us(498);
  //digitalWrite(10,LOW);
  PORTB &= 0B11111011;
  _delay_us(498);
  //sei();
}
