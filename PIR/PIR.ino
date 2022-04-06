#define pir A0
#define led 13
void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}


void loop() {
  int val = digitalRead(pir);
  if (val==HIGH){
    Serial.println("1 High");
    Serial.println(analogRead(pir));
    digitalWrite(led, HIGH);
  }else{
    Serial.println("0");
    Serial.println(analogRead(pir));
    digitalWrite(led, LOW);
  }
  delay(1000);
}
