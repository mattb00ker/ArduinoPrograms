// Arduino Phone

// Setup 1.8" TFT
#define sclk 2
#define mosi 3
#define cs   4
#define dc   5
#define rst  6

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);

//Setup buttons
const int but1 = 9;      //first button
const int but2 = 10;     //second button
int val1 = 0;
int val2 = 0;

//Setup phone
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);


void setup(){
  //buttons
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  
  //Splash Screen
  tft.initR(INITR_BLACKTAB); 
  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);
  
  tft.fillScreen(ST7735_BLACK);
  //testdrawtext("Phone made by Matt Booker, show respect!!", ST7735_WHITE);
  tft.setCursor(0, 30);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(2);
  tft.println("Mat-Phone");
  delay(1000);
  
  //Phone startup
    SIM900.begin(19200);
  delay(2000);
}


//Function to call my number
void callSomeone()
{
  SIM900.println("ATD + +447814739070;");
  delay(100);
  SIM900.println();
  delay(10000);
  SIM900.println("ATH");
 
}


void sendSMS()
{
  SIM900.print("AT+CMGF=1\r");                       // AT command to send SMS message
  delay(100);
  SIM900.println("AT + CMGS = \"+447814739070\"");   // recipient's mobile number, in international format
  delay(100);
  SIM900.println("Matt, you are amazing");           // message to send
  delay(100);
  SIM900.println((char)26);                         // End AT command with a ^Z, ASCII code 26
  delay(100);
  SIM900.println();
  delay(5000);                                     // give module time to send SMS

}

void loop(){
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.println("Dial-a-Matt");
  tft.setCursor(0, 60);
  tft.println("Txt-a-Matt");
  
  delay(2000);
  
  val1 = digitalRead(but1);
  val2 = digitalRead(but2);
  
  if (val1 == HIGH){
    tft.fillScreen(ST7735_BLACK);
    tft.setCursor(0, 30);
    tft.setTextColor(ST7735_RED);
    tft.setTextSize(2);
    tft.println("Calling");
    tft.setCursor(0, 60);
    tft.println("Matt");
    callSomeone();
    
  }
  
  if (val2 == HIGH){
    tft.fillScreen(ST7735_BLACK);
    tft.setCursor(0, 30);
    tft.setTextColor(ST7735_RED);
    tft.setTextSize(2);
    tft.println("Txting");
    tft.setCursor(0, 60);
    tft.println("Matt");
    sendSMS();
  }  
    
  
}


