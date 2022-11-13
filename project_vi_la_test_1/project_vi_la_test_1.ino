//Project VI-LA
//Coded by AMRES
//19-03-2018

//INputs and OUTputs
int s1 = A0; //moisture sensor
int s2 = A1; //LDR
int m1_1 = 2; //water pump
int m1_2 = 4;
int ledR = 3; //red LED
int ledG = 5; //green LED
int ledB = 6; //blue LED
int v1 = 4; //valve 1
int v2 = 7; //valve 2

//Variables
long tim = 0;
int LDR = 0;
long dely = 0;
int Level = 0;
bool timRun = true;
bool loopRun = true;

void setup() {
  Serial.begin(9600);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(m1_1, OUTPUT);
  pinMode(m1_2, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);
  digitalWrite(m1_1,HIGH);
  digitalWrite(m1_2,LOW);
  delay(100000);

}

void timeCon() {
  if (timRun == true) {
    tim = tim + 1000;
    delay(1000);
    Serial.println(tim);
  }
}

void dayLightCon() {
  LDR = analogRead(s2);
  if (LDR < 500) {
    Serial.println("Changing light condition");
    digitalWrite(ledR, 255);
    digitalWrite(ledG, 255);
    digitalWrite(ledB, 255);
  }
  else {
    Serial.println("Changing light condition");
    digitalWrite(ledR, 0);
    digitalWrite(ledG, 0);
    digitalWrite(ledB, 0);
  }
}

void autoWaterCha() {
  if (tim > 10000) {
    Serial.println("Changing water level");
    digitalWrite(m1_1, HIGH);
    digitalWrite(m1_2, HIGH);
    digitalWrite(v1, HIGH);
    digitalWrite(v2, HIGH);
    loopRun = true;
    while (dely < 60000 && loopRun == true) {
      dely = dely + 1000;
      delay(1000);
      Serial.println(dely);
      if (dely == 60000) {
        digitalWrite(v1, LOW);
        digitalWrite(v2, LOW);
        tim = 0;
        dely = 0;
        loopRun = false;
        Serial.println("time Reseted");
      }
    }
  }
}

void waterLevelChe() {
  Level = digitalRead(s1);
  Level = HIGH; //REMOVE BEFORE USE
  while (Level == LOW) {
    digitalWrite(v2, HIGH);
    Serial.println("Water filling engaged");
  }
  if (Level == HIGH) {
    digitalWrite(v2, LOW);
    Serial.println("Water filling disengaged");
  }
}

void loop() {
  timeCon();
  dayLightCon();
  autoWaterCha();
  waterLevelChe();
}
