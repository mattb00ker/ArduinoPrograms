#include <Servo.h>
#include <Stepper.h>

char text[40];
char inChar=-1;
byte index =0;



Servo myservo; 
int pos = 0; 

#define STEPS_PER_MOTOR_REVOLUTION 32  
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64 

Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);

int  Steps2Take;

void setup(){
   myservo.attach(7);
   Serial.begin(9600);
   small_stepper.setSpeed(100);
  
}



void loop(){}

void serialEvent(){
 while (Serial.available() > 0){
  inChar = Serial.read();
  text[index] = inChar;
  index++;
  text[index] = '\0';
 }
 Serial.print(text); 
Serial.print(sizeof(text));
delay(2000);
  
for (int i = 0; i < sizeof(text); i++){
 Serial.println(text[i-1]);
 if (text[i-1] == 'a'){
  Serial.print("hhhshshshs"); 
  myservo.write(50);
  myservo.write(60);
  small_stepper.step(8);
  myservo.write(56);
  small_stepper.step(-8);
  small_stepper.step(8);
  myservo.write(50);
  
  

 }
 
 
 
} 
delay(2000);

}

