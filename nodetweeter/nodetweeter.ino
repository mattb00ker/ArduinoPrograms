#include <TwitterWebAPI.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define TWI_TIMEOUT 2000  // in msec
unsigned long twi_update_interval = 20;
const char *ntp_server = "pool.ntp.org";  // time1.google.com, time.nist.gov, pool.ntp.org
int timezone = 0;                        // US Eastern timezone -05:00 HRS

static char const consumer_key[]    = "A7CBXkVQot3heMKvKOKRz6Uqy";
static char const consumer_sec[]    = "J3ZlKpRWaZMQ4fvkDROwsOLyf0P0635SuaWfUMCSmvVA9PTofx";
static char const accesstoken[]     = "831194262033276928-BpVEAWMhcnI7CtBDiMDPgy8w3eLFCer";
static char const accesstoken_sec[] = "FkE7u9uz71320lDfM54LjIcvoRcj4tnMwBw9ZeBzJftoR";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntp_server, timezone*3600, 60000);  // NTP server pool, offset (in seconds), update interval (in milliseconds)
TwitterClient tcr(timeClient, consumer_key, consumer_sec, accesstoken, accesstoken_sec);

#ifndef WIFICONFIG
const char* ssid = "BTHub6-RXGP";           // WiFi SSID
const char* password = "Uf4ewkQ7cgvt";   // WiFi Password
#endif
unsigned long api_mtbs = twi_update_interval * 1000; //mean time between api requests
unsigned long api_lasttime = 0;




void setup(void){
  if (twi_update_interval < 5) api_mtbs = 5000; // Cant update faster than 5s.
  //Begin Serial
  Serial.begin(115200);
  // WiFi Connection
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to ");
  Serial.print(ssid);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected. yay!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(100);
  // Connect to NTP and force-update time
  tcr.startNTP();
  Serial.println("NTP Synced");
  delay(100);
  // Setup internal LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop(void){
  
 tcr.tweet("Hi from a nodemcu");
 delay(16000);
}
