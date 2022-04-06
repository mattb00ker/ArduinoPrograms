
int IRledPin =  13;    // IR-LED connected to digital pin 13
int ButtonOn = 5;
int ButtonHide = 6;
int ButtonInput = 7;


int valOn = 0;
int valHide = 0;
int valInput = 0;

 
void setup()   {                
  
  pinMode(IRledPin, OUTPUT); 
  pinMode(ButtonOn, INPUT);
  pinMode(ButtonHide, INPUT);    
  pinMode(ButtonInput, INPUT);  
  
  
  Serial.begin(9600);
}

void loop()                     
{
  Serial.println("Sending IR signal");
  valOn = digitalRead(ButtonOn);
  valHide = digitalRead(ButtonHide);
  valInput = digitalRead(ButtonInput);
  
  
  
  if(valOn==HIGH){
    SendOnCode();
    Serial.println("On!!!");
    
  }else{
    
    digitalWrite(IRledPin, LOW);
  }
  
  if(valHide==HIGH){
    SendHideCode();
    Serial.println("Hide!!!");
  }else{
    
    digitalWrite(IRledPin, LOW);
  }
  
   if(valInput==HIGH){
    SendInputCode();
    Serial.println("Input");
  }else{
    
    digitalWrite(IRledPin, LOW);
  }
  
 
  //delay(2000);  // wait twenty seconds (2 seconds * 1000 milliseconds)
}










void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}

void SendOnCode() {

delayMicroseconds(32444);
pulseIR(8920);
delayMicroseconds(4160);
pulseIR(760);
delayMicroseconds(1420);
pulseIR(720);
delayMicroseconds(1440);
pulseIR(700);
delayMicroseconds(420);
pulseIR(620);
delayMicroseconds(1560);
pulseIR(600);
delayMicroseconds(460);
pulseIR(620);
delayMicroseconds(460);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(560);
delayMicroseconds(500);
pulseIR(540);
delayMicroseconds(1640);
pulseIR(560);
delayMicroseconds(500);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(500);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(560);
delayMicroseconds(500);
pulseIR(580);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(1580);
pulseIR(580);
delayMicroseconds(1580);
pulseIR(600);
delayMicroseconds(38740);
pulseIR(8700);
delayMicroseconds(2240);
pulseIR(560);
delayMicroseconds(27604);
pulseIR(8720);
delayMicroseconds(2220);
pulseIR(560);
delayMicroseconds(27624);
pulseIR(8720);
delayMicroseconds(2200);
pulseIR(540);
}

void SendHideCode() {

delayMicroseconds(10016);
pulseIR(8940);
delayMicroseconds(4160);
pulseIR(740);
delayMicroseconds(1420);
pulseIR(720);
delayMicroseconds(1480);
pulseIR(620);
delayMicroseconds(460);
pulseIR(600);
delayMicroseconds(1580);
pulseIR(580);
delayMicroseconds(500);
pulseIR(560);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(520);
pulseIR(540);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(520);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(560);
pulseIR(520);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(1620);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(38260);
pulseIR(8740);
delayMicroseconds(2180);
pulseIR(560);
delayMicroseconds(27124);
pulseIR(8760);
delayMicroseconds(2180);
pulseIR(580);
delayMicroseconds(27064);
pulseIR(8760);
delayMicroseconds(2180);
pulseIR(580);
delayMicroseconds(27104);
pulseIR(8740);
delayMicroseconds(2200);
pulseIR(560);
}


void SendInputCode() {

delayMicroseconds(5880);
pulseIR(8960);
delayMicroseconds(4140);
pulseIR(780);
delayMicroseconds(1400);
pulseIR(720);
delayMicroseconds(1440);
pulseIR(680);
delayMicroseconds(440);
pulseIR(620);
delayMicroseconds(1540);
pulseIR(620);
delayMicroseconds(460);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(500);
pulseIR(580);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(560);
delayMicroseconds(500);
pulseIR(560);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(500);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(520);
pulseIR(540);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(580);
delayMicroseconds(500);
pulseIR(580);
delayMicroseconds(1580);
pulseIR(580);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(1600);
pulseIR(560);
delayMicroseconds(38780);
pulseIR(8720);
delayMicroseconds(2180);
pulseIR(560);
delayMicroseconds(27624);
pulseIR(8720);
delayMicroseconds(2220);
pulseIR(540);
}


