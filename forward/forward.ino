int enL = 6;
int enR = 5;

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

  forward();
  delay(1000);
  backward();
  delay(1000);
}

void forward() {
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 200);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 200);
}

void backward() {
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 200);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 200);
}
void rel() {
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 0);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 0);
}
