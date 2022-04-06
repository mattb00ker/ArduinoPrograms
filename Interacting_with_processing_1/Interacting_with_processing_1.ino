int sensorPin = 1;     //input pin
int val = 0;

void setup(){
  Serial.begin(9600);  //open serial
}

void loop(){
  val = random(0, 10);
  //Serial.write(int(7)); //doesn't work
  Serial.println(val);
 
  delay(1000);
  
}
