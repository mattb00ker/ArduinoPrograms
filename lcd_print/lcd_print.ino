#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("hello world");

}

void loop() {
  // put your main code here, to run repeatedly:

}
