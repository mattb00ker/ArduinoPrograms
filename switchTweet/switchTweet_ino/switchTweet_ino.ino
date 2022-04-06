#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x9C, 0x35 }; 
byte ip[] = {192,168,1,97}; 
byte gateway[] = {192,168,1,254};
byte subnet[] = {255,255,255,0};

const int flipSwitch_pin = 2;
const int LEDpin = 3;
int currentState = 0;

Twitter twitter("163570093-K3FgaDru5Ty1KPXpyb4N1LXW49LX0dg0glTrzEbW"); //Twitter token

void setup(){
  pinMode(flipSwitch_pin, INPUT);
  pinMode(LEDpin, OUTPUT);
  delay(5000);
  Ethernet.begin(mac, ip, gateway, gateway, subnet);
  Serial.begin(9600);
}


void tweet(char msg[])
{
 Serial.println("connecting ...");
 if (twitter.post(msg))
 {
 // Specify &Serial to output received response to Serial.
 // If no output is required, you can just omit the argument, e.g.
 // int status = twitter.wait();
 int status = twitter.wait(&Serial);
 if (status == 200)
 {
 Serial.println("OK.");
 } 
 else
 {
 Serial.print("failed : code ");
 Serial.println(status);
 }
 } 
 else
 {
 Serial.println("connection failed.");
 }
}

void loop(){
  currentState = digitalRead(flipSwitch_pin);
  
  if (currentState == HIGH){
    digitalWrite(LEDpin, HIGH);
    tweet("Launch the missiles commander! - Tweet sent with #arduino");
  }
  else{
    digitalWrite(LEDpin, LOW);
  }
} 
