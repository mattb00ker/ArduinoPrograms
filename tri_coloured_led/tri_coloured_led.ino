const int ledRed = 5;
const int ledGreen = 3;
const int ledBlue = 1;


void setup()
{
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);

}

void loop()
{
  digitalWrite(ledGreen, HIGH);
  
  delay(2000);
  
  digitalWrite(ledBlue, HIGH);
  
  delay(2000);
  
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  
  delay(1000);
  
  digitalWrite(ledRed, HIGH);
  
}
