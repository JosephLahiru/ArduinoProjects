int LMC = 9;
int RMC = 10;
int X = 0;
int Y = 0;
int LC = 0;
int RC = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LMC, INPUT);
  pinMode(RMC, INPUT);
}

void encoder_reading() {

  int LM = digitalRead(LMC);
  int RM = digitalRead(RMC);

  if (LM == 0) {
    if (X == 0) {
      LC = LC + 1;
      Serial.print("LC=");
      Serial.println(LC);
      X = 1;
    }
  }
  else {
    X = 0;

  }

  if (RM == 0) {
    if (Y == 0) {
      RC = RC + 1;
      Serial.print("RC=");
      Serial.println(RC);
      Y = 1;
    }
  }
  else {
    Y = 0;

  }
}

void loop()
{
  encoder_reading ();
 /* if (LC == RC) {
    analogWrite(10, 50);
    analogWrite(11, 50);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else if (LC > RC) {

    analogWrite(10, 0);
    analogWrite(11, 50);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else if (RC > LC) {

    analogWrite(10, 50);
    analogWrite(11, 0);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }*/
}


