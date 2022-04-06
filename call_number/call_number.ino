#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);

void setup()
{
  SIM900.begin(19200);
  SIM900power();
  delay(20000);

}

void SIM900power()
{
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(5000);
}

void callSomeone()
{
  SIM900.println("ATD + +447814739070;");
  delay(100);
  SIM900.println();
  delay(3000);
  SIM900.println("ATH");
}

void loop()
{
  Serial.println(digitalRead(8));
  callSomeone();
  SIM900power();
  do {} while (1);
}
