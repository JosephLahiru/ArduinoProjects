#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
Serial.begin(9600);

}

void loop() {

int i=105;
int j=155;

motor1.setSpeed(i);
motor1.run(FORWARD);
motor2.setSpeed(i);
motor2.run(FORWARD);
motor3.setSpeed(j);
motor3.run(FORWARD);
motor4.setSpeed(j);
motor4.run(FORWARD);
Serial.print("forward");

}
