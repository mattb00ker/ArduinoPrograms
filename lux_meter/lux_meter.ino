
/*
 #######################################################
 Project: Arduino Light Meter
 Description: This project measures ambient light intensity and displays it on seven segment
              LEDs in Lux or Foot Candel units. The BH1750 sensor is used for
              measuring light intensity. 
 Written by: Raj Bhatt (June 17, 2013)
 www.embedded-lab.com
 #######################################################
 
 BH1750 sensor module connections:
 -------------------------------------
 BH1750                        Arduino
 VCC      --------------->     5V
 SCL      --------------->     Analog pin 5 (A5)
 SDA      --------------->     Analog pin 4 (A4)
 ADD      --------------->     Leave it open
 GND      --------------->     GND
 #######################################################
 
 MAX7219 based LED display connections
 -------------------------------------
 MAX7219                       Arduino
 VCC      --------------->     5V
 DIN      --------------->     Digital Pin 7
 LOAD     --------------->     Digital Pin 6
 CLK      --------------->     Digital Pin 5
 GND      --------------->     GND
 
 This software is licensed under a 
 Creative Commons Attribution-ShareAlike 3.0. 
 */
 
 
#include "Wire.h" 
#include "math.h"

 
 

int BH1750_Device = 0x23; // I2C address for light sensor
int iCheck = 0;  // iCheck = 0 for Lux, iCheck = 1 for Foot-Candles
unsigned int Lux, Scaled_FtCd;
float FtCd, Wattsm2;
int IntPin = 0;  // Pin 2
//variables to keep track of the timing of recent interrupts
unsigned long button_time = 0;  
unsigned long last_button_time = 0; 
 
 
void setup()
{
  Wire.begin();
  Serial.begin(9600);
 
  Configure_BH1750();
  //Attach the interrupt to the input pin and monitor for ANY Change
  attachInterrupt(IntPin, stateChange, FALLING);
  delay(300);
 
}
 
void loop()
{
  int i;
  Lux = BH1750_Read();
  FtCd = Lux/10.764;
  Wattsm2 = Lux/683.0;
  Serial.print(Lux,DEC);     
  Serial.println("[lx]"); 
  Serial.print(FtCd,2);     
  Serial.println("[FC]");
  Serial.print(Wattsm2,4);     
  Serial.println("[Watts/m^2]"); 
  delay(2000);
 
}
 
unsigned int BH1750_Read() //
{
  unsigned int i=0;
  Wire.beginTransmission(BH1750_Device);
  Wire.requestFrom(BH1750_Device, 2);
  while(Wire.available()) //
  {
    i <<=8;
    i|= Wire.read();  
  }
  Wire.endTransmission();  
  return i/1.2;  // Convert to Lux
}
 

 
 
void stateChange()
{
 button_time = millis();
 if (button_time - last_button_time > 250)
 {
   iCheck = !iCheck;

   last_button_time = button_time;
 } 
}
 
void Configure_BH1750() 
{
  Wire.beginTransmission(BH1750_Device);
  Wire.write(0x10);      // Set resolution to 1 Lux
  Wire.endTransmission();
}

