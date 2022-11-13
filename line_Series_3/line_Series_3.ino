#include <AFMotor.h>

int a = 37;
int b = 38;
int c = 39;
int d = 40;
int e = 41;
int f = 42;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);
  pinMode(d, INPUT);
  pinMode(e, INPUT);
  pinMode(f, INPUT);

}

int maxpower = 140;// max bot speed
int robotspeed = 0;
int maxspeed = 100;// speed limit

void loop() {
  int L3 = digitalRead(a);//LEFT sensor 3
  int L2 = digitalRead(b);//LEFT sensor 2
  int L1 = digitalRead(c);//LEFT sensor 1
  int R1 = digitalRead(d);//RIGHT sensor 1
  int R2 = digitalRead(e);//RIGHT sensor 2
  int R3 = digitalRead(f);//RIGHT sensor 3

  int mL = 0;
  int mR = 0;

  if ((L1 + L2 + L3) > (R1 + R2 + R3)) {
    if (robotspeed > maxspeed) {
      stopbot();
    }
    motor1.setSpeed(maxspeed);
    motor1.run(BACKWARD);
    motor2.setSpeed(maxspeed);
    motor2.run(FORWARD);
    robotspeed = 0;
  } else if ((L1 + L2 + L3) < (R1 + R2 + R3)) {
    if (robotspeed > maxspeed) {
      stopbot();
    }
    motor1.setSpeed(maxspeed);
    motor1.run(FORWARD);
    motor2.setSpeed(maxspeed);
    motor2.run(BACKWARD);
    robotspeed = 0;
  } else {
    motor1.setSpeed(maxspeed);
    motor1.run(FORWARD);
    motor2.setSpeed(maxspeed);
    motor2.run(FORWARD);
    robotspeed++;
  }

}

void stopbot() {
  motor1.setSpeed(maxpower);
  motor1.run(BACKWARD);
  motor2.setSpeed(maxpower);
  motor2.run(BACKWARD);
}

