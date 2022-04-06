#include <TwitterApi.h>

/*******************************************************************
 *  An Example of getting data back from the TwitterAPI            *
 *  https://github.com/witnessmenow/arduino-twitter-api            * 
 *                                                                 *
 *  Written by Brian Lough                                         *
 *******************************************************************/


#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>


//------- Replace the following! ------
char ssid[] = "BTHub6-RXGP";       // your network SSID (name)
char password[] = "Uf4ewkQ7cgvt";  // your network key

// Normally we would use these to generate the bearer token but its not working yet :/
// Use steps on the readme to generate the Bearer Token

#define BEARER_TOKEN "AAAAAAAAAAAAAAAAAAAAAEsQ4wAAAAAAoFj92CfK6tB72%2BCdO3ncQssCbOk%3Dn1REoIH8HMG4dSvjaAguLvdHX3SpxeknkVKx2biMlmwaGaAtiV"

//Using curl to get bearer token
// curl -u "$CONSUMER_KEY:$CONSUMER_SECRET" \
//    --data 'grant_type=client_credentials' \
//    'https://api.twitter.com/oauth2/token'

WiFiClientSecure client;
TwitterApi api(client);

unsigned long api_mtbs = 80000; //mean time between api requests
unsigned long api_lasttime = 0;   //last time api request has been done
bool firstTime = true;

//Inputs

String screenName = "apathetic_geek";
bool haveBearerToken = false;

void setup() {

  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  api.setBearerToken(BEARER_TOKEN);
  haveBearerToken = true;
  getTwitterStats(screenName);

}

void getTwitterStats(String name) {
  Serial.println("Getting twitter stats for " + name);
    String responseString = api.getUserStatistics(name);
    Serial.println(responseString);
    DynamicJsonBuffer jsonBuffer;
    JsonObject& response = jsonBuffer.parseObject(responseString);
    
  
      
      
      
    if (response.success()) {
      Serial.println("parsed Json");
      // Use Arduino Json to parse the data
    } else {
      Serial.println("Failed to parse Json");
    }
    api.sendGetToTwitter("hello from a nodemcu!");
}

void loop() {
  if(haveBearerToken){
    if ((millis() > api_lasttime + api_mtbs))  {
      getTwitterStats(screenName);
      api_lasttime = millis();
    }
  }
}
