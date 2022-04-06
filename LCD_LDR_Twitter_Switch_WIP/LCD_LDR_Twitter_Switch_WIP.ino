//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>
/*******************************************************
 
This program will test the LCD panel and the buttons
Mark Bramwell, July 2010
 
********************************************************/
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x9C, 0x35 }; // create MAC address for ethernet shield
byte ip[] = {192,168,1,97}; // choose your own IP for ethernet shield
byte gateway[] = {192,168,1,254};
byte subnet[] = {255,255,255,0};
int currentState = 0;

Twitter twitter("1206231613-V84XMmRReLqxryXawO6KBmcQzUba4dFw0nZwDjj"); // replace aaaaaaa with your token

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;

const int ledPin = 2;
const int switchPin = 3;


#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
 
// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   
 return btnNONE;  // when all others fail, return this...
}


int val = 0;                     // varible for LDR data

void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("Press button to tweet"); // print a simple message
 pinMode(ledPin, OUTPUT);
 pinMode(switchPin, INPUT);
 delay(5000);
 Ethernet.begin(mac, ip, gateway, gateway, subnet);
 Serial.begin(9600);
 
 
 
 

 
}

void tweet(char msg[])
{
 Serial.println("connecting ...");
 if (twitter.post(msg))
 {
 // Specify &Serial to output received response to Serial.
 // If no output is required, you can just omit the argument, e.g.
 // int status = twitter.wait();
 int status = twitter.wait(&Serial);
 if (status == 200)
 {
 Serial.println("OK.");
 } 
 else
 {
 Serial.print("failed : code ");
 Serial.println(status);
 }
 } 
 else
 {
 Serial.println("connection failed.");
 }
}
 
void loop()
{
 
 val = analogRead(1);
 
 lcd.setCursor(9,1);            // move cursor to second line "1" and 9 spaces over
 lcd.print(millis()/1000);      // display seconds elapsed since power-up
 
 
 lcd.setCursor(0,1);            // move to the begining of the second line
 lcd.print(val);
 delay(500);
 
 currentState = digitalRead(switchPin);
 
 if (currentState == HIGH){
   digitalWrite(ledPin, HIGH);

   if(val > 600)
  {
 
  lcd.setCursor(0,0);
 lcd.print("Light On"); 
    
  
  
  delay(1000);
 tweet("Light On, and still winning");
 
  }
  if(val < 500)
  {
     lcd.setCursor(0,0);
 lcd.print("Light Off"); 

    
    delay(1000);
    tweet("Light Off, and still winning");
  }
   
 }else{
   digitalWrite(ledPin, LOW);
 }
 
 }
 

