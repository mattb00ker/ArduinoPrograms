
#define sensorPin A1
unsigned int steve = 0;

void setup(){
  Serial.begin(9600);

}

void loop(){
  steve = analogRead(sensorPin);
  
  
  Serial.println(int(10));
  delay(100);
  

   
   
}
