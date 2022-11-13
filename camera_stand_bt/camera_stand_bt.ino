#include <Servo.h>

Servo servoY;
Servo servoX;

int x;
int X=90;
int Y=90;

void setup() {
  Serial.begin(9600);
  servoY.attach(6);
  servoX.attach(5);
  servoY.write(Y);
  servoX.write(X);
}

void loop() {
  x = Serial.read();
  Serial.println(x);
  if (x == 49) {
    servoY.write(Y);
    Y = Y + 1;
    delay(20);
  }
  else if (x == 50) {
    servoY.write(Y);
    Y = Y - 1;
    delay(20);
  }
  else if (x == 51) {
    servoX.write(X);
    X = X + 1;
    delay(20);
  }
  else if (x == 52) {
    servoX.write(X);
    X = X - 1;
    delay(20);
    }
}

