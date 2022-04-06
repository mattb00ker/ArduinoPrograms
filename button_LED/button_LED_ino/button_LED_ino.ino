const int LED = 7;
const int button = 2;

int val = 0;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop(){
  val = digitalRead(button);
  
  if (val == HIGH){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
