
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include "RF24_config.h";

//int msg[1]

const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(9, 10);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(pipe);
  
}

void loop() {
  
  String hello = "hello!";
  int messageSize = hello.length();
  // put your main code here, to run repeatedly:
  for (int i =0; i < messageSize; i++){
    int charToSend[1];
    charToSend[0]= hello.charAt(i);
    radio.write(charToSend, 1);
    Serial.write(hello.charAt(i));
  
  }
  //msg[0] = 2;
  //radio.write(msg, 1);
  
  //radio.powerDown();
  //delay(1000);
  //radio.powerUp();

}
