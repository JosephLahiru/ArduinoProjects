//not working node mcu can't handle such a thing
int com = 0;

int enL = 3;
int enR = 4;

// Motor Driver Direction
int inR1 = 5;
int inR2 = 6;
int inL1 = 7;
int inL2 = 8;

void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.println("begin");
  delay(5000);

  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);

  //pinMode(2, OUTPUT);

}

void loop() {

  com = Serial.read();
  Serial.println(com);

  if (com == 97) {
    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    digitalWrite(enR, HIGH);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    digitalWrite(enL, HIGH);
    com = 0;
  }
  if (com == 98) {
    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    digitalWrite(enR, 1);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    digitalWrite(enL, 1);
    com = 0;
  }
  if (com == 99) {
    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    digitalWrite(enR, 1);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    digitalWrite(enL, 1);
    com = 0;
  }
  if (com == 100) {
    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, 1);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 1);
    com = 0;
  }
}
