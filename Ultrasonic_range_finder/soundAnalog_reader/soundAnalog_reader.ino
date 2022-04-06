void setup(){
  Serial.begin(9600);
  
}


void loop(){
  
  
int sensor = analogRead(0);
Serial.print(sensor);
Serial.println();

delay(200);

}

