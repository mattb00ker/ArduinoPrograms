#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <Temboo.h>
#include "TembooAccount.h" // Contains Temboo account information
#include <SPI.h>
#include <Wire.h>




byte ethernetMACAddress[] = ETHERNET_SHIELD_MAC;
EthernetClient client;

// The number of times to trigger the action if the condition is met
// We limit this so you won't use all of your Temboo calls while testing
int maxCalls = 10;

// The number of times this Choreo has been run so far in this sketch
int calls = 0;






int clockInt = 0;            // digital pin 2 is now interrupt 0
int masterClock = 0;         // counts rising edge clock signals
int seconds = 0;             // variable
int minutes = 0;             // variable
int hours = 0;             // variable

int ledPin1G = 6;
int ledPin1R = 7;
int ledPin2G = 8;
int ledPin2R = 9;
int state = LOW;
int oldstate = HIGH;



boolean sentMail = false;




void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1G, OUTPUT);
  pinMode(ledPin1R, OUTPUT);
  pinMode(ledPin2G, OUTPUT);
  pinMode(ledPin2R, OUTPUT);


  
  pinMode(3, INPUT);

  attachInterrupt(clockInt, clockCounter, CHANGE);
      //  clockInt is our interrupt, clockCounter function is called when
      //  invoked on a RISING clock edge
  analogReference(DEFAULT);
  
  //Serial.begin(9600);
  analogWrite(5, 127);   // this starts our PWM 'clock' with a 50% duty cycle
  delay(4000);
  //while(!Serial);

  //Serial.print("DHCP:");
  if (Ethernet.begin(ethernetMACAddress) == 0) {
    //Serial.println("FAIL");
    while(true);
    digitalWrite(ledPin2R, HIGH);

  }
  //Serial.println("OK");
  digitalWrite(ledPin2R, LOW);
  delay(5000);



  //Serial.println("Setup complete.\n");
 
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
    //Serial.print("  Time = ");
    zeroit(hours);
    //Serial.print(hours);
    //Serial.print(":");
    zeroit(minutes);
    //Serial.print(minutes);
    //Serial.print(":");
    zeroit(seconds);
    //Serial.println(seconds);
    return;
}

void zeroit(int value)
{
  if (value < 10)
  //Serial.print("0");
  return;
}



void loop() {
  // put your main code here, to run repeatedly:
  

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
    //digitalWrite(12, state);
    oldstate = state;
    printtime();
  } 
  
  if (digitalRead(3) == HIGH){
    hours = 0;
    minutes = 0;
    seconds = 0;
    digitalWrite(ledPin1G, HIGH);
    digitalWrite(ledPin2G, HIGH);
    digitalWrite(ledPin1R, LOW);
    digitalWrite(ledPin2R, LOW);
    delay(100);
    digitalWrite(ledPin1G, LOW);
    digitalWrite(ledPin2G, LOW);
    delay(100);
    digitalWrite(ledPin1G, HIGH);
    
    }

  if (minutes > 0){
    digitalWrite(ledPin2R, HIGH);
    
    
    }
  if (hours > 1){
    digitalWrite(ledPin1G, LOW);
    digitalWrite(ledPin1R, HIGH);
    }

  if(hours > 16){
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
  
  if(hours > 17 && sentMail == false){
    sendEmail();
    digitalWrite(ledPin1R, HIGH);
    digitalWrite(ledPin2R, HIGH);
    delay(1000);
    sentMail = !sentMail; 
    
    
    }
  while (sentMail == true){
    digitalWrite(ledPin1R, LOW);
    digitalWrite(ledPin2R, LOW);
    digitalWrite(ledPin1G, LOW);
    digitalWrite(ledPin2G, LOW);
    delay(100);
    digitalWrite(ledPin1R, LOW);
    digitalWrite(ledPin2R, HIGH);
    digitalWrite(ledPin1G, HIGH);
    digitalWrite(ledPin2G, LOW);
    delay(100);
    digitalWrite(ledPin1R, HIGH);
    digitalWrite(ledPin2R, LOW);
    digitalWrite(ledPin1G, LOW);
    digitalWrite(ledPin2G, HIGH);
    delay(100);
    }
}

void sendEmail() {
  //Serial.println("starting email function");
  TembooChoreo SendEmailChoreo(client);

  SendEmailChoreo.begin();



  // Set Temboo account credentials
  SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
  SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
  SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);

  // Set profile to use for execution
  SendEmailChoreo.setProfile("GoogleBasicAuthAccount");

  // Set Choreo inputs
  String ToAddressValue = "jonherbie@gmail.com";
  SendEmailChoreo.addInput("ToAddress", ToAddressValue);
  String SubjectValue = "PIR Sensor At Philips";
  SendEmailChoreo.addInput("Subject", SubjectValue);
  String MessageBodyValue = "No movement has been detected for 18 hours. Please investigate";
  SendEmailChoreo.addInput("MessageBody", MessageBodyValue);

  // Identify the Choreo to run
  SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");

  // Run the Choreo; when results are available, print them to serial
  SendEmailChoreo.run();

  while(SendEmailChoreo.available()) {
    char c = SendEmailChoreo.read();
    //Serial.print(c);
  }
  
  SendEmailChoreo.close();
  delay(30000);
}


