char text[40];
char inChar=-1;
byte index =0;

void setup(){
 Serial.begin(9600);

  
}

void loop(){
}

void serialEvent(){
 while (Serial.available() > 0){
  inChar = Serial.read();
  text[index] = inChar;
  index++;
  text[index] = '\0';
 }
 Serial.print(text); 
Serial.print(sizeof(text));
delay(2000);
  
for (int i = 0; i < sizeof(text); i++){
 Serial.println(text[i-1]);
 
 
 
} 
delay(2000);

}
