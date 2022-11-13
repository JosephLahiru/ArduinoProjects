// Motor Driver PWM
int enL = 6;
int enR = 5;

// Motor Driver Direction
int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

void setup() {
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);  
 

}

void loop() {

  digitalWrite(inL1,HIGH);
  digitalWrite(inL2,LOW);
  analogWrite(enL,120);
  digitalWrite(inR1,HIGH);
  digitalWrite(inR2,LOW);
  analogWrite(enR,120);

}
