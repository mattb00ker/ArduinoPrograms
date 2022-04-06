/* Blinking LED
*turns an LED on and off
*there is a resistor on pin 13
*connect LED to (positive) pin 13, (negative) GND
*/

int ledpin = 13;                //LED connected to digital pin 13

void setup()
{
  pinMode(ledpin, OUTPUT);      // sets the pin as an output
}

void loop()
{
  digitalWrite(ledpin, HIGH);   //turns the LED on
  delay(50);                    //waits one second
  digitalWrite(ledpin, LOW);    //turns the LED off
  delay(2000);                  //waits one second
}
