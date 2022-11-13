#include<AFMotor.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

void setup() {
Serial.begin(9600);
}

void loop(){
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
}

