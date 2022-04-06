#include <LiquidCrystal.h>
#include <SPI.h>
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <Temboo.h>
#include "TembooAccount.h" // Contains Temboo account information

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


int state = LOW;
int oldstate = HIGH;

LiquidCrystal lcd(12, 11, 9, 8, 7, 6);




void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
  lcd.begin(16, 2);
  lcd.print("hello world");


  attachInterrupt(clockInt, clockCounter, CHANGE);
      //  clockInt is our interrupt, clockCounter function is called when
      //  invoked on a RISING clock edge
  analogReference(DEFAULT);
  
  Serial.begin(9600);
  analogWrite(5, 127);   // this starts our PWM 'clock' with a 50% duty cycle
  delay(4000);
  while(!Serial);

  Serial.print("DHCP:");
  if (Ethernet.begin(ethernetMACAddress) == 0) {
    Serial.println("FAIL");
    while(true);
  }
  Serial.println("OK");
  delay(5000);



  Serial.println("Setup complete.\n");
 
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
    hours = 0;
    minutes = 0;
    seconds = 0;
    }

  if (minutes > 1){
    sendEmail();
    }
 

}

void sendEmail() {
  TembooChoreo SendEmailChoreo(client);

  // Set Temboo account credentials
  SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
  SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
  SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);

  // Set Choreo inputs
  String UsernameValue = "mattbooker401@gmail.com";
  SendEmailChoreo.addInput("Username", UsernameValue);
  String SubjectValue = "PIR sensor";
  SendEmailChoreo.addInput("Subject", SubjectValue);
  String ToAddressValue = "mattbooker@hotmail.com";
  SendEmailChoreo.addInput("ToAddress", ToAddressValue);
  String PasswordValue = "ybukgiqlbhqgnzvr";
  SendEmailChoreo.addInput("Password", PasswordValue);
  String MessageBodyValue = "Hi, no movement detected, please investigate ";
  SendEmailChoreo.addInput("MessageBody", MessageBodyValue);

  // Identify the Choreo to run
  SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");

  // Run the Choreo
  unsigned int returnCode = SendEmailChoreo.run();

  // Read and print the error message
  while (SendEmailChoreo.available()) {
    char c = SendEmailChoreo.read();
    Serial.print(c);
  }
  Serial.println();
  SendEmailChoreo.close();
}


