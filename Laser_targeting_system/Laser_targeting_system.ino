#include <Servo.h>

Servo servoX;
Servo servoY;

int laser = 2;

int pos = 0;
int pulse;
int angle;
bool x;
bool y;

void setup() {
  Serial.begin(9600);
  servoX.attach(9);
  servoY.attach(11);
}

void loop() {
  pulse = Serial.read();
  if (pulse == "X") {
    x = true;
    y = false;
  }
  else if (pulse == "Y") {
    y = true;
    x = false;
  }
  else {
    angle = map(pulse, 0, 180, 180, 0);
    if (x == true) {
      servoX.write(angle);
    }
    else if (y == true) {
      servoY.write(angle);
    }
  }
}

