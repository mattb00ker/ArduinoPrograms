


#include <Servo.h>
#include <Stepper.h>

char text[40];
char inChar=-1;
byte index =0;
const int stepsPerRevolution = 200 ;


 
Stepper myStepper(stepsPerRevolution, 8,9,10,11);  

Servo myservo; 
int pos = 5; 


int  Steps2Take;

void setup(){
   myservo.attach(7);
   Serial.begin(9600);
   myStepper.setSpeed(60);
  
}



void loop(){
  
  
  myservo.write(20);
  delay(10);
  myStepper.step(-200);
  delay(1000000000);



  

}


