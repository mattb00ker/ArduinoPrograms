// blink an led depending on light in suroundings
// rate set by analogue input

const int LED = 13;                 //LED pin

int val = 0;                        //varible for data from sensor

void setup(){
  pinMode(LED, OUTPUT);             //LED pin set as output
  
                                    //analouge pins are automatically set as input
  Serial.begin(9600);               // Start and open serial port
}

void loop(){
  
  val = analogRead(0);              //read sensor value
  Serial.println(val);              //print value to serial
  digitalWrite(LED, HIGH);          //LED on
  
  delay(val);                       //stop the program for some time
  
  digitalWrite(LED, LOW);           //turn off the LED
  
  delay(val);                       //stop the program for some time
  
}
