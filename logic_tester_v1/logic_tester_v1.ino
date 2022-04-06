
int led1 = 10;
int led2 = 11;
int led3 = 12;

int sw1 = 2;
int sw2 = 3;
int sw3 = 4;
int sw4 = 5;
int sw5 = 6;
int sw6 = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(sw6, INPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led3, HIGH);
  int answer1 = digitalRead(sw1);
  int answer2 = digitalRead(sw2);
  int answer3 = digitalRead(sw3);
  int answer4 = digitalRead(sw4);
  int answer5 = digitalRead(sw5);
  int answer6 = digitalRead(sw6);
  //Serial.println(answer3);  
  
  
  if((answer1 == 1)&&(answer2 == 1)){
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    
    }
  if(answer3 == 1){
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
    
    
    }
  if(answer4 == 1){
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
    
    
    }
  if(answer5 == 1){
    digitalWrite(led3, LOW);
    delay(1000);
    digitalWrite(led3, HIGH);
    
    
    }
  if(answer6 == 1){
    digitalWrite(led3, LOW);
    delay(1000);
    digitalWrite(led3, HIGH);
    
    
    }
  
  delay(1);
}
