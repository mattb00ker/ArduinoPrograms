const int flipSwitch_pin = 2;
const int LEDpin = 13;
int currentState = 0;
  

void setup(){
  pinMode(flipSwitch_pin, INPUT);
  pinMode(LEDpin, OUTPUT);
}

void loop(){
  currentState = digitalRead(flipSwitch_pin);
  
  if (currentState == HIGH){
    digitalWrite(LEDpin, HIGH);
  }
  else{
    digitalWrite(LEDpin, LOW);
  }
} 
