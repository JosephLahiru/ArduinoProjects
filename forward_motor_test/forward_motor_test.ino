#include<AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
motor1.setSpeed(160);
motor1.run(FORWARD);
motor2.setSpeed(160);
motor2.run(FORWARD);
motor3.setSpeed(170);
motor3.run(FORWARD);
motor4.setSpeed(170);
motor4.run(FORWARD);
Serial.println("FORWARD");// put your main code here, to run repeatedly:

}
