const int analogPin = A0;
const int analogOutPin = 9;

int sensorValue = 0;
int outputValue = 0;

float thickness;
int count, count1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  count1++;
  sensorValue = analogRead(analogPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);

  if(count==30){
    count1 = 0;
    Serial.print("sensor = ");
    Serial.println(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);

    thickness = 20000-(5000*(1023/(float)sensorValue)-1);
    Serial.print("thickness = ");
    Serial.println(thickness);
    }
    count++;
    if(count>=(255-outputValue)){
      count = 0;
      }
    if(count<(255-outputValue)/2){
      digitalWrite(7, HIGH);
      delay(20);
      }
    else{
      digitalWrite(7, LOW);
      delay(20);
      }
}
