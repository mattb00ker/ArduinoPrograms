#include <SPI.h>
#include <Client.h>
#include <Ethernet.h>
#include <Server.h>
#include <Udp.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x9C, 0x35 };  
byte ip[] = { 192, 168, 1, 97 };    
byte gateway[] = { 192, 168, 1, 254 };
byte subnet[] = { 255, 255, 255, 0 };
// www.google.com ip
byte server[] = { 74, 125, 226, 242 };

EthernetClient client;

int loopCount = 0;

void setup()
{
  
  Ethernet.begin(mac, ip, gateway, gateway, subnet); 
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  
  if (client.connect(server, 80)) {
    Serial.println("connected");
  } else {
    Serial.println("connection failed");
  }
}

void loop()
{
  int thisByte;
  int newCount = 0;    

  if(client.connected())
  {
    newCount = client.available();

//    if(newCount > 0) thisByte = client.read();    

    Serial.print("Available ");
    Serial.println(newCount, DEC);
  }
  else if(loopCount == 0)
  {
    // if not connected, attempt to reconnect
    client.stop();

    Serial.print("Connecting...");
    delay(10);
    
    if (client.connect(server, 80)) {
      Serial.println("ok");
    } else {
      Serial.println("failed.");
      delay(10);
    }
  }

  // heartbeat
  if(loopCount > 8)
  {
    digitalWrite(13,HIGH); 
    loopCount = 0;
  }
  else
  {
    loopCount = loopCount++;
  }

  if(loopCount == 4)
  {
    digitalWrite(13,LOW); 
  }

  delay(100);
}
