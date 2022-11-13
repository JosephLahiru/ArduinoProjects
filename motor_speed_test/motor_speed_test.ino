#include<AFMotor.h>
int left_motorP=50;
int left_motorS=0;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {

Serial.begin(9600);
pinMode(left_motorP,INPUT);
}

void loop() {
  motor3.setSpeed(155);
  motor3.run(FORWARD);
  left_motorS = digitalRead(left_motorP);
  Serial.println(left_motorS);

}
