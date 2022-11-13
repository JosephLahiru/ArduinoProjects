#include <Servo.h>

Servo str;

int pos = 0;

int enL = 6;
int enR = 5;

int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

int x = 0;

//65-180

void setup() {
  Serial.begin(9600);
  str.attach(3);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  str.write(137);
}

void forward()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 400);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 400);
}
void none()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 0);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 0);
}
void reverse()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 400);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 400);
}

void loop()
{
  while (1)
  {

    if (Serial.available() > 0)
    {
      x = Serial.read();
    }
    Serial.println(x);
    if (x == 'F') {
      forward();
      delay(10);
      if (pos != 137) {
        pos = 137;
        str.write(pos);
      }
      x = 0;
    }
    else if (x == 'B') {
      reverse();
      delay(10);
      if (pos != 137) {
        pos = 137;
        str.write(pos);
      }
      x = 0;
    }
    else if (x == 'L') {
      forward();
      delay(10);
      if (pos != 65) {
        pos = 65;
        str.write(pos);
      }
      x = 0;
    }
    else if (x == 'R') {
      forward();
      delay(10);
      if (pos != 180) {
        pos = 180;
        str.write(pos);
      }
      x = 0;
    }
    else {
      none();
    }
  }
}
