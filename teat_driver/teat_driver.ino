int enL = 6; // Motor Driver PWM
int enR = 5;

int inR1 = 7;// Motor Driver Direction
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;


void setup() {
  Serial.begin(9600);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);

  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);

  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);

}

void loop() {

digitalWrite(inR1,HIGH);
digitalWrite(inR2,LOW);
analogWrite(enR,255);
digitalWrite(inL1,HIGH);
digitalWrite(inL2,LOW);
analogWrite(enL,255);

}
