int ledPin1G = 12;
int ledPin1R = 13;
int ledPin2G = 8;
int ledPin2R = 9;

void setup() {
  // put your setup code here, to run once:


  pinMode(ledPin1G, OUTPUT);
  pinMode(ledPin1R, OUTPUT);
  pinMode(ledPin2G, OUTPUT);
  pinMode(ledPin2R, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin1R, LOW);
  digitalWrite(ledPin2R, LOW);
  digitalWrite(ledPin1G, LOW);
  digitalWrite(ledPin2G, LOW);
  delay(100);
  digitalWrite(ledPin1R, HIGH);
  digitalWrite(ledPin2R, HIGH);
  delay(100);
  digitalWrite(ledPin1R, LOW);
  digitalWrite(ledPin2R, LOW);
  

}
