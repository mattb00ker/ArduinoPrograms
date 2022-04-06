
//////////////////////////////////////////////////////////////////////////////////////////////////////

/////////    ////////   /////////    ////////     //      //  //////////   ////     //     ///////
   //       //     //   //      //   //      //   //      //      //       // //    //    //     \\
   //       /////////   ////////     //      //   //      //      //       //   //  //   //       \\
   //       //     //   //      //   //      //   //      //      //       //    // //   \\       //
/////////   //     //   //      //   ////////      ///////    //////////   //     ////     ///////

//////////////////////////////////////////////////////////////////////////////////////////////////////

/* Code by Dhiraj Jadhao

for more details on how to setup arduino board to control it wirelessly with iArduino App
and how to get started visit Official Website:

http://i-arduino.blogspot.com

This code is for use with iArduino App.

all rights reserved please contact on following mail id for details:

dhirajjadhao@gmail.com

*/


#include <SPI.h>             // for Arduino later than ver 0018
//#include <EthernetUdp.h>   
#include <Ethernet.h>


//////////  NETWORK INFO  ////////////////

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xE0 };  //Set your Ethernet Shield's MAC address here - make sure you replace the MAC Address with your shield's values!
byte ip[] = { 192,168,1,102 };                        // Set your shield's desired IP address here - check your network for configuration details
//byte gateway[] = { 192,168,1,1 };                   //if you need to set a gateway (Optional)
//byte subnet[] = { 255,255,255,0 };                  // Change this to your subnet address (Optional)
  
unsigned int localPort = 7777;                        // local port to listen on (set this the same as Port # on iArduino Port Field)


IPAddress iPhoneIP(192, 168, 1, 101);               //Leave it as its is  //Set the iPhone/iPod/iPad's IP address to send messages back to iArduino...
unsigned int iPhonePort = 7777;                     //Leave it as its is  //Set the Port # of the message table you configured in iArduino 


///////////////////////////////////////////

///////// Pin Assignments /////////////////

//Do not change anything unless you understand what this part of the code do.

int relay2 = 2;
int relay3 = 3;
int relay4 = 4;
int relay5 = 5;
int relay6 = 6;
int relay7 = 7;
int relay8 = 8;
int relay9 = 9;

///////////////////////////////////////////


///////////////// UDP Variables  ////////////////// 

// the next two variables are set when a packet is received
//byte remoteIp[4];          // holds received packet's originating IP
//unsigned int  remotePort;   // holds received packet's originating port

// buffers for receiving and sending data
char packBuff[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,

/////////////////////////////////////////////////

EthernetUDP Udp;


void setup() {
  
  // More info on Ethernet on Arduino's website:  http://arduino.cc/en/Reference/EthernetBegin
  // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);   // If you don't need to set your default gateway or subnet manually, use this

//  Ethernet.begin(mac,ip,gateway,subnet);  // Use this line instead if you've manually set all the parameters
  
  
  Udp.begin(localPort);    //Setup UDP socket on port defined earlier

  Serial.begin(9600);    //Start Serial Communications with PC
  
     
  pinMode(relay2,OUTPUT);    //Designate pin 67as Output Pin
  pinMode(relay3,OUTPUT);    //Designate pin 67as Output Pin
  pinMode(relay4,OUTPUT);    //Designate pin 67as Output Pin
  pinMode(relay5,OUTPUT);    //Designate pin 67as Output Pin
  pinMode(relay6,OUTPUT);
  pinMode(relay7,OUTPUT);
  pinMode(relay8,OUTPUT);
  pinMode(relay9,OUTPUT);
 
  
  

}

void loop()
{
 // Integer that will hold our PWM values for later use // 
 
  int relay2pwmVal;    
  int relay3pwmVal;    
  int relay4pwmVal;    
  int relay5pwmVal;    
  int relay6pwmVal;    
  int relay7pwmVal; 
  int relay8pwmVal; 
  int relay9pwmVal; 

///////////////////////////////////////////////////////////  
  
  
   // if there's data available, read a packet
  int packetSize = Udp.parsePacket(); // note that this includes the UDP header
  if(packetSize)
  {
    packetSize = packetSize - 8;      // subtract the 8 byte header
    Serial.print("Packet size: ");
    Serial.println(packetSize);

    // read the packet into packetBuffer and get the senders IP addr and port number
    Udp.read(packBuff,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Message: ");
    Serial.println(packBuff);
    
    relay2pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay3pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay4pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay5pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay6pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay7pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay8pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay9pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    
   
   
   
   
   //////////////////////// Pin 2 (relay2) /////////////////////////////////////       
       if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='M')  // Wait for "PWMXXX" and use XXX as value for PWM 
    {

      
      analogWrite(relay2,relay2pwmVal);    //Set relay1 to PWM Value
      
      Serial.println(relay2pwmVal);    //Write notification  
    

    }
    
    
    else if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay2,HIGH);    //Turn on relay1
  
      Serial.println("Pin 2 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 2 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay2,LOW);    //Turn off relay1
  
      Serial.println("Pin 2 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 2 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
     //////////////////////// Pin 3 (relay3) /////////////////////////////////////       
      
       if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='M')  // Wait for "PWMXXX" and use XXX as value for PWM 
    {

      
      analogWrite(relay3,relay3pwmVal);    //Set relay1 to PWM Value
      
      Serial.println(relay3pwmVal);    //Write notification  
    

    }
    
    
    
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay3,HIGH);    //Turn on relay1
  
      Serial.println("Pin 3 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 3 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay3,LOW);    //Turn off relay1
  
      Serial.println("Pin 3 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 3 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
    
    
     //////////////////////// Pin 4 (relay4) /////////////////////////////////////       
        
       if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='M')  // Wait for "PWMXXX" and use XXX as value for PWM 
    {

      
      analogWrite(relay4,relay4pwmVal);    //Set relay1 to PWM Value
      
      Serial.println(relay4pwmVal);    //Write notification  
    

    }

    
    if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay4,HIGH);    //Turn on relay1
  
      Serial.println("Pin 4 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 4 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay4,LOW);    //Turn off relay1
  
      Serial.println("Pin 4 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 4 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 5 (relay5) /////////////////////////////////////       
        
       if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='M')  // Wait for "PWMXXX" and use XXX as value for PWM 
    {

      
      analogWrite(relay5,relay5pwmVal);    //Set relay1 to PWM Value
      
      Serial.println(relay5pwmVal);    //Write notification  
    

    }

    
    
    if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay5,HIGH);    //Turn on relay1
  
      Serial.println("Pin 5 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 5 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay5,LOW);    //Turn off relay1
  
      Serial.println("Pin 5 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 5 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
    
    
     //////////////////////// Pin 6 (relay6) /////////////////////////////////////       
        
       if (packBuff[0] = 'P' && packBuff[1]=='6' && packBuff[2]=='M')  // Wait for "PWMXXX" and use XXX as value for PWM 
    {

      
      analogWrite(relay6,relay6pwmVal);    //Set relay1 to PWM Value
      
      Serial.println(relay6pwmVal);    //Write notification  
    

    }

    
    
    if (packBuff[0] = 'P' && packBuff[1]=='6' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay6,HIGH);    //Turn on relay1
  
      Serial.println("Pin 6 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 6 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='6' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay6,LOW);    //Turn off relay1
  
      Serial.println("Pin 6 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 6 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 7 (relay7) /////////////////////////////////////       
    
       if (packBuff[0] = 'P' && packBuff[1]=='7' && packBuff[2]=='M')  // Wait for "PWMXXX" and use XXX as value for PWM 
    {

      
      analogWrite(relay7,relay7pwmVal);    //Set relay1 to PWM Value
      
      Serial.println(relay7pwmVal);    //Write notification  
    

    }
    
    
    if (packBuff[0] = 'P' && packBuff[1]=='7' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay7,HIGH);    //Turn on relay1
  
      Serial.println("Pin 7 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 7 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='7' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay7,LOW);    //Turn off relay1
  
      Serial.println("Pin 7 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 7 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 8 (relay8) /////////////////////////////////////       
        
       if (packBuff[0] = 'P' && packBuff[1]=='8' && packBuff[2]=='M')  // Wait for "PWMXXX" and use XXX as value for PWM 
    {

      
      analogWrite(relay8,relay8pwmVal);    //Set relay1 to PWM Value
      
      Serial.println(relay8pwmVal);    //Write notification  
    

    }

    
    if (packBuff[0] = 'P' && packBuff[1]=='8' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay8,HIGH);    //Turn on relay1
  
      Serial.println("Pin 8 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 8 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='8' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay8,LOW);    //Turn off relay1
  
      Serial.println("Pin 8 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 8 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
     //////////////////////// Pin 9 (relay9) /////////////////////////////////////       
        
      if (packBuff[0] = 'P' && packBuff[1]=='9' && packBuff[2]=='M')  // Wait for "PWMXXX" and use XXX as value for PWM 
    {

      
      analogWrite(relay9,relay9pwmVal);    //Set relay1 to PWM Value
      
      Serial.println(relay9pwmVal);    //Write notification  
    

    }

   
   
    if (packBuff[0] = 'P' && packBuff[1]=='9' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay9,HIGH);    //Turn on relay1
  
      Serial.println("Pin 9 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 9 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='9' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay9,LOW);    //Turn off relay1
  
      Serial.println("Pin 9 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 9 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
 }
 
 delay(20);
 
}  




