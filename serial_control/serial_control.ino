void setup(){
  Serial.begin(9600);
  
  // Set pins used
  pinMode(13, OUTPUT);
}

void loop(){
  if (Serial.available()){
    char ser = Serial.read();
    
    switch (ser) {
      case '13':
      triggerPin(13);
      break;
   
   
    }  
  }
}

void triggerPin(int pin){
  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
}
