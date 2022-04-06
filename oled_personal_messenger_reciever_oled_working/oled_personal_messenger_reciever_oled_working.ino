
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "nRF24L01.h"
#include "RF24.h"


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(9,10);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

String message [2];


void setup() {
  // put your setup code here, to run once
  radio.begin();
  radio.setRetries(15,15);
  radio.startListening();
  
  Serial.begin(9600);

  radio.printDetails();
  // ;by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  
  testscrolltext();
  delay(2000);
  display.clearDisplay();

  radio.openReadingPipe(1,pipe);
  radio.startListening();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( radio.available() )
  {
    // Read the data payload until we've received everything
    bool done = false;
    while (!done)
    {
      // Fetch the data payload
      done = radio.read(message, sizeof(message));
      Serial.print(message[1]);
      Serial.print('Hi');
    }
  }

}

void testscrolltext(void) {
  String text;
  text = "hi Sam, the rest should be easy!";
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println(text);
  display.display();
 
  //display.startscrollleft(0x00, 0x0F);
  //delay(2000);
  
}
