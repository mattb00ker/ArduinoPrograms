#include <SoftwareSerial.h>
SoftwareSerial bluetooth(5,3);
/*
simple LED test
*/

char val;         // variable to receive data from the serial port
int redledpin = 8;  // LED connected to pin 8 
int greenledpin = 12;

void setup()
{
  pinMode(redledpin, OUTPUT);  // pin 13 (on-board LED) as OUTPUT
  pinMode(greenledpin, OUTPUT);
 
  Serial.begin(9600);       // start serial communication at 9600bps
  bluetooth.begin(9600);
 
}
 
void loop() {
  
  bluetooth.listen();
  while (bluetooth.available() > 0){
    char inByte = bluetooth.read();
    Serial.write(inByte);
  
 
 
  if( inByte == '0' )               // if '0' was received led 13 is switched off

  {
   digitalWrite(redledpin, LOW);    // turn Off pin 13 off
   digitalWrite(greenledpin, LOW);
   
delay(1000);                  // waits for a second   
Serial.println("all off");
  }

if( inByte == '1' )               // if '1' was received led 13 on
 {
    digitalWrite(redledpin, HIGH);  // turn ON pin 13 on
    delay(1000);                  // waits for a second
   
    Serial.println("red on");
 }
if(inByte =='2')
{
  digitalWrite(greenledpin, HIGH);
  delay(1000);
  
  Serial.println("green on");
}

  }
}


