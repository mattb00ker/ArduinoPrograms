#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>
// Alter IP address to suit your own network!
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x9C, 0x35 }; // create MAC address for ethernet shield
byte ip[] = {192,168,1,97}; // choose your own IP for ethernet shield
byte gateway[] = {192,168,1,254};
byte subnet[] = {255,255,255,0};

Twitter twitter("1206231613-V84XMmRReLqxryXawO6KBmcQzUba4dFw0nZwDjj"); // replace aaaaaaa with your token
void setup()
{
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
void loop()
{
 delay(1000);
 tweet("bazinga!");
 do{
 } 
 while(1>0); // endless loop
}
