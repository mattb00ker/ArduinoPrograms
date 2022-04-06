/*
############################################################################
Code by Joseph Rautenbach, full writeup at: http://devjoe.com/?p=265
############################################################################
*/

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 2, 3);

String text;
int textWidth;
float count = 1.0;
boolean toggle = false;

void setup()   {
  //Serial.begin(9600);

  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(55);
  display.setTextSize(1);
  display.setTextWrap(false); // this is very important!
  display.clearDisplay();
  text = "Test of Wobbly Text and simple animation!";
  textWidth = text.length()*6+85; // get the width of the text
}


void loop() {
  for(int i=0; i<textWidth; i+=1) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("Test..."); // just a title
    display.drawLine(0, 15, display.width(), 15, BLACK);
    count += 0.2;

    // routine to draw the actual wobbly text character by character, each with a sine wave.
    for(int j=0; j<text.length(); j++) {
      display.drawChar((j*6)+85-i, map(sin(count+(float)(j/1.5))*100, -100, 100, 17, 22), text[j], BLACK, WHITE, 1);
    }

    //draws a pattern at the bottom of the screen, also uses a sine wave.
    int sine = sin((float)count/4)*100;
    sine = map(sine, -100, 100, 0, display.width());
    display.drawLine(display.width()-sine, display.height(), sine, 31, BLACK);
    display.drawLine(sine, display.height(), display.width()-sine, 31, BLACK);
    display.drawLine(sine, 31, sine, display.height(), BLACK);
    display.drawLine(display.width()-sine, 31, display.width()-sine, display.height(), BLACK);

    display.display();
    //delay(10);
    
    
  }
}
