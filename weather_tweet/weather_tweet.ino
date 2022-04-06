//Celsius to Fahrenheit conversion
double Fahrenheit(double celsius)
{
	return 1.8 * celsius + 32;
}

//Celsius to Kelvin conversion
double Kelvin(double celsius)
{
	return celsius + 273.15;
}

// dewPoint function NOAA
// reference: http://wahiduddin.net/calc/density_algorithms.htm 
double dewPoint(double celsius, double humidity)
{
	double RATIO = 373.15 / (273.15 + celsius);  // RATIO was originally named A0, possibly confusing in Arduino context
	double SUM = -7.90298 * (RATIO - 1);
	SUM += 5.02808 * log10(RATIO);
	SUM += -1.3816e-7 * (pow(10, (11.344 * (1 - 1/RATIO ))) - 1) ;
	SUM += 8.1328e-3 * (pow(10, (-3.49149 * (RATIO - 1))) - 1) ;
	SUM += log10(1013.246);
	double VP = pow(10, SUM - 3) * humidity;
	double T = log(VP/0.61078);   // temp var
	return (241.88 * T) / (17.558 - T);
}

// delta max = 0.6544 wrt dewPoint()
// 5x faster than dewPoint()
// reference: http://en.wikipedia.org/wiki/Dew_point
double dewPointFast(double celsius, double humidity)
{
	double a = 17.271;
	double b = 237.7;
	double temp = (a * celsius) / (b + celsius) + log(humidity/100);
	double Td = (b * temp) / (a - temp);
	return Td;
}


#include <dht11.h>
#include "Wire.h" 
#include "math.h"
#include <Adafruit_BMP085.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x9C, 0x35 }; // create MAC address for ethernet shield
byte ip[] = {192,168,1,97}; // choose your own IP for ethernet shield
byte gateway[] = {192,168,1,254};
byte subnet[] = {255,255,255,0};

Twitter twitter("1206231613-V84XMmRReLqxryXawO6KBmcQzUba4dFw0nZwDjj");


dht11 DHT11;

#define DHT11PIN 2

int BH1750_Device = 0x23; // I2C address for light sensor
int iCheck = 0;  // iCheck = 0 for Lux, iCheck = 1 for Foot-Candles
unsigned int Lux, Scaled_FtCd;
float FtCd, Wattsm2;
int IntPin = 0;  // Pin 2
//variables to keep track of the timing of recent interrupts
unsigned long button_time = 0;  
unsigned long last_button_time = 0; 

Adafruit_BMP085 bmp;

void setup()
{
  Wire.begin();
  Ethernet.begin(mac, ip, gateway, gateway, subnet);
  Serial.begin(115200);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  Ethernet.begin(mac, ip, gateway, gateway, subnet);
  Configure_BH1750();
  //Attach the interrupt to the input pin and monitor for ANY Change
  attachInterrupt(IntPin, stateChange, FALLING);
  
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
   
  delay(300);
}

char buffer[12];
char charBuf[141];


void loop()
{
  Serial.println("\n");

  int chk = DHT11.read(DHT11PIN);



  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature (oC): ");
  Serial.println((float)DHT11.temperature, 2);

  Serial.print("Temperature (oF): ");
  Serial.println(Fahrenheit(DHT11.temperature), 2);

  Serial.print("Temperature (K): ");
  Serial.println(Kelvin(DHT11.temperature), 2);

  Serial.print("Dew Point (oC): ");
  Serial.println(dewPoint(DHT11.temperature, DHT11.humidity));

  Serial.print("Dew PointFast (oC): ");
  Serial.println(dewPointFast(DHT11.temperature, DHT11.humidity));



    int i;
  Lux = BH1750_Read();
  FtCd = Lux/10.764;
  Wattsm2 = Lux/683.0;
  Serial.print(Lux,DEC);     
  Serial.println("[lx]"); 
  Serial.print(FtCd,2);     
  Serial.println("[FC]");
  Serial.print(Wattsm2,4);     
  Serial.println("[Watts/m^2]"); 
  Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");
    Serial.println();
 
  
  
  //tweet, first to compose the message
  String final = "Humidity: ";
  long hum = 0;
  hum = DHT11.humidity, 2;
  ltoa(hum, buffer, 12);
  
  final.concat(hum);
  
  String next1 = "%, temp: ";
  long temp = 0.0;
  temp = DHT11.temperature, 2;
  ltoa(temp, buffer, 12);
  
  final.concat(next1);
  final.concat(temp);
  
  String next2 = "C, due point: ";
  long due = 0.0;
  due = dewPoint(DHT11.temperature, DHT11.humidity);
  ltoa(due, buffer, 12);
  
  final.concat(next2);
  final.concat(due);
  
  String next3 = "C, light intensity: ";
  long lux = 0.0;
  lux = Lux;
  ltoa(lux, buffer, 12);
  
  final.concat(next3);
  final.concat(lux);
  
  String next4 = "Lux, pressure: ";
  long pres = 0.0;
  pres = bmp.readPressure();
  ltoa(pres, buffer, 12);
  
  final.concat(next4);
  final.concat(pres);
  
  String next5 = "Pa. Southend On Sea live weather!";
  
  final.concat(next5);
  
  Serial.print(final);
  
  final.toCharArray(charBuf, 141);
  tweet(charBuf);
  
  delay(900000);      //15mins
  
  
  
  
  
  
  
}
unsigned int BH1750_Read() //
{
  unsigned int i=0;
  Wire.beginTransmission(BH1750_Device);
  Wire.requestFrom(BH1750_Device, 2);
  while(Wire.available()) //
  {
    i <<=8;
    i|= Wire.read();  
  }
  Wire.endTransmission();  
  return i/1.2;  // Convert to Lux
}

void stateChange()
{
 button_time = millis();
 if (button_time - last_button_time > 250)
 {
   iCheck = !iCheck;

   last_button_time = button_time;
 } 
}
 
void Configure_BH1750() 
{
  Wire.beginTransmission(BH1750_Device);
  Wire.write(0x10);      // Set resolution to 1 Lux
  Wire.endTransmission();
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

