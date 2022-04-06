#include <Servo.h>
#include <Stepper.h>


Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created
 
int pos = 0;    // variable to store the servo position

//---( Number of steps per revolution of INTERNAL motor in 4-step mode )---
#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  

Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);

int  Steps2Take;

void setup(){
  myservo.attach(7);
  
}

void loop(){
  
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for(pos = 180; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees
  {
    myservo.write(pos);      // tell servo to go to position in variable 'pos'
    myservo.write(40);
    delay(15);  
  }    
  small_stepper.setSpeed(100);   // SLOWLY Show the 4 step sequence 
  Steps2Take  =  40;  // Rotate CW
  small_stepper.step(Steps2Take);
  
  
  
}
