#include <nRF24L01.h>
#include <RF24.h>
//#include <RF24_config.h>
#include <SPI.h>
#include <avr/wdt.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 


#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int lastmsg = 1;
String theMessage;
//String theMessage1 = "";

void setup(void){
  
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  display.clearDisplay();
  
  //testscrolltext(theMessage);
  //delay(2000);
  //display.clearDisplay();
}
void loop(void){
  
  if (radio.available()){
    bool done = false;  
      done = radio.read(msg, 1); 
      char theChar = msg[0];
      if (msg[0] != 2){
        theMessage.concat(theChar);
        }
      else {
       int messageSize = theMessage.length();
       Serial.println(messageSize);
       Serial.println(theMessage);
       //testscrolltext(theMessage);
       //delay(5000);
       display.display();
       display.clearDisplay();
       //theMessage= ""; 
       //watchdogSetup();
       String theMessage1 = theMessage.substring(0, (messageSize/4));
       display.setTextSize(2);
       display.setTextColor(WHITE);
       display.setCursor(0,0);
       display.println(theMessage1);
       display.display();
       delay(5000);
       String theMessage2 = theMessage.substring((messageSize/4), (messageSize/2));
       display.clearDisplay();
       display.setCursor(0,0);
       display.println(theMessage2);
       display.display();
       delay(5000);
       String theMessage3 = theMessage.substring((messageSize/2), ((messageSize/4)*3));
       display.clearDisplay();
       display.setCursor(0,0);
       display.println(theMessage3);
       display.display();
       delay(5000);
       String theMessage4 = theMessage.substring(((messageSize/4)*3), messageSize);
       display.clearDisplay();
       display.setCursor(0,0);
       display.println(theMessage4);
       display.display();
       delay(5000);
       Serial.println(theMessage1);
       Serial.println(theMessage2);
       Serial.println(theMessage3);
       Serial.println(theMessage4);
       display.clearDisplay();
       theMessage = "";
       
      }
   }
}

