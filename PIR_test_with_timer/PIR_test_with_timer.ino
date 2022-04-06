
int clockInt = 0;            // digital pin 2 is now interrupt 0
int masterClock = 0;         // counts rising edge clock signals
int seconds = 0;             // variable
int minutes = 0;             // variable
int hours = 0;             // variable

int ledPin = 12;
int state = LOW;
int oldstate = HIGH;

int alarmPin = 11;




void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(alarmPin, OUTPUT);


  attachInterrupt(clockInt, clockCounter, CHANGE);
      //  clockInt is our interrupt, clockCounter function is called when
      //  invoked on a RISING clock edge
  analogReference(DEFAULT);
  
  Serial.begin(9600);
  analogWrite(5, 127);   // this starts our PWM 'clock' with a 50% duty cycle

}

void clockCounter()      // called by interrupt
{
  masterClock ++;        // with each clock rise add 1 to masterclock count
  if(masterClock >= 979) // 490Hz reached    
//  if(masterClock >= 130) // 490Hz reached    
  {                        
    seconds ++;          // after one 490Hz cycle add 1 second ;)
    masterClock = 0;     // Reset after 1 second is reached
  state = !state;

//    tone(13, 100, 100);  // using tone to pulse LED without delay call ;)
   }
  return;
}

void printtime()
{
    Serial.print("  Time = ");
    zeroit(hours);
    Serial.print(hours);
    Serial.print(":");
    zeroit(minutes);
    Serial.print(minutes);
    Serial.print(":");
    zeroit(seconds);
    Serial.println(seconds);
    return;
}

void zeroit(int value)
{
  if (value < 10)
  Serial.print("0");
  return;
}



void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, digitalRead(3));

  if(seconds == 60){     
    if (minutes == 60){// set to 60
      hours++;
      minutes = 0;
      seconds = 0;
    }
    else{
      minutes ++;          // increment minutes by 1
      seconds = 0;         // reset the seconds variable
    }
  }

  if (state != oldstate){
    digitalWrite(12, state);
    oldstate = state;
    printtime();
  }
  
  if (digitalRead(3) == HIGH){
    Serial.print("PIR HIGH");
    hours = 0;
    minutes = 0;
    seconds = 0;
    }

  if (minutes > 1){
    digitalWrite(alarmPin, HIGH);
    delay(1000);
    digitalWrite(alarmPin, LOW);

    }
 

}


