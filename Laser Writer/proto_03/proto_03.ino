#include <Servo.h>
#include <Stepper.h>


char text[40];
char inChar=-1;
byte index =0;


Servo myServo; 
int pos = 10; 

const int stepsPerRevolution = 200;
const int stableBreak = 300;

Stepper myStepper(stepsPerRevolution, 8,9,10,11); 

void setup(){
   myServo.attach(7);
   myServo.write(20);
   Serial.begin(9600);
   myStepper.setSpeed(60);
  
}

void loop(){}


void serialEvent(){
 while (Serial.available() > 0){
  inChar = Serial.read();
  text[index] = inChar;
  index++;
  text[index] = '\0';
 }

  
for(int i = 0; i < sizeof(text); i++){

  
  if (text[i-1] == 'a'){
    Serial.println("laser a");
    myServo.write(20);
    delay(stableBreak);
    myServo.write(10);
    delay(stableBreak);
    myStepper.step(20);
    delay(stableBreak);
    myServo.write(16);
    delay(stableBreak);
    myStepper.step(-20);
    delay(stableBreak);
    myStepper.step(20);
    delay(stableBreak);
    myServo.write(20);
    delay(stableBreak);
    myStepper.step(10);
  
  

 }
 
 if (text[i-1] == 'b'){
  Serial.println("laser b"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(16);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
  if (text[i-1] == 'c'){
  Serial.println("laser c"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 'd'){
  Serial.println("laser d"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(3);
  delay(stableBreak);
  myServo.write(11);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(17);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 
 if (text[i-1] == 'e'){
  Serial.println("laser e"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 
 if (text[i-1] == 'f'){
  Serial.println("laser f"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(15);
  delay(stableBreak);
  myStepper.step(-15);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 
 if (text[i-1] == 'g'){
  Serial.println("laser g"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(12);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(17);
  delay(stableBreak);
  myStepper.step(-4);
  delay(stableBreak);
  myStepper.step(4);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  
  
  
  
  
  
  myStepper.step(10);
  
  

 }
 
 if (text[i-1] == 'h'){
  Serial.println("laser h"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  
  myServo.write(10);
  delay(stableBreak);
  myServo.write(20);
 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 'i'){
  Serial.println("laser i"); 
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 
  if (text[i-1] == 'j'){
  Serial.println("laser j"); 
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(5);
  delay(stableBreak);
  myServo.write(18);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(5);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(-10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(-10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 
 
 if (text[i-1] == 'k'){
  Serial.println("laser k"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(5);
  delay(stableBreak);
  
  
  myServo.write(13);
  delay(stableBreak);
  myStepper.step(5);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(13);
  delay(stableBreak);
  myStepper.step(-5);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  
  myStepper.step(3);
  delay(stableBreak);
  myServo.write(17);
  delay(stableBreak);
  myStepper.step(2);
  delay(stableBreak);
  myServo.write(20);
  
  
  
  
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 
 if (text[i-1] == 'l'){
  Serial.println("laser l"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(19);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 'm'){
  Serial.println("laser m"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(14);
  delay(stableBreak);
  
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);

  myServo.write(20);
  delay(stableBreak);
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 'n'){
  Serial.println("laser n"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  
  
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);

  myServo.write(20);
  delay(stableBreak);
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
  if (text[i-1] == 'o'){
  Serial.println("laser o"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  
  
  myStepper.step(-20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 'p'){
  Serial.println("laser p"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 'q'){
  Serial.println("laser q"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myStepper.step(15);
  delay(stableBreak);
  myServo.write(18);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(5);
  delay(stableBreak);
  myServo.write(22);
  delay(stableBreak);
  myStepper.step(5);
  delay(stableBreak);
  myStepper.step(-5);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
  if (text[i-1] == 'r'){
  Serial.println("laser r"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myStepper.step(15);
  
  delay(stableBreak);
  myServo.write(17);
  delay(stableBreak);
  myStepper.step(5);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 's'){
  Serial.println("laser s"); 
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  
  

  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 't'){
  Serial.println("laser t"); 
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(-10);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myStepper.step(-10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
 
  

 
  delay(stableBreak);
  myStepper.step(10);
 
 
 
 
} 
 if (text[i-1] == 'u'){
  Serial.println("laser u"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);

 
  

 
  delay(stableBreak);
  myStepper.step(10);
 
 
 
 
} 
 if (text[i-1] == 'v'){
  Serial.println("laser v"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(7);
  delay(stableBreak);
  myServo.write(18);
  delay(stableBreak);
  myStepper.step(3);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myServo.write(18);
  delay(stableBreak);
  myStepper.step(3);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(7);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);

 
  

 
  delay(stableBreak);
  myStepper.step(10);
 
 
 
 
} 

 if (text[i-1] == 'w'){
  Serial.println("laser w"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(16);
  delay(stableBreak);
  
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);

  myServo.write(20);
  delay(stableBreak);
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 if (text[i-1] == 'x'){
  Serial.println("laser x"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(16);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(14);
  delay(stableBreak);
  myStepper.step(-10);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(14);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(14);
  delay(stableBreak);
  myStepper.step(-10);
  delay(stableBreak);
  myServo.write(16);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }
  if (text[i-1] == 'y'){
  Serial.println("laser y"); 
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);
  myServo.write(16);
  delay(stableBreak);
  myStepper.step(-10);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myServo.write(16);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  
  myServo.write(16);
  delay(stableBreak);
  myStepper.step(-10);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(10);
  delay(stableBreak);

 
  

 
  delay(stableBreak);
  myStepper.step(10);
  
  

 }

 if (text[i-1] == 'z'){
  Serial.println("laser z"); 
  myServo.write(20);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(10);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  myServo.write(15);
  delay(stableBreak);
  myStepper.step(-20);
  delay(stableBreak);
  myServo.write(20);
  delay(stableBreak);
  myStepper.step(20);
  delay(stableBreak);
  
  
  

  delay(stableBreak);
  myStepper.step(10);
  
  

 }
 
  if (text[i-1] == ' '){
  Serial.println("laser space"); 
  myServo.write(20);
  
  myStepper.step(20);
  delay(stableBreak);
  
  
  

  delay(stableBreak);
  myStepper.step(10);
  
  

 }









}
}
