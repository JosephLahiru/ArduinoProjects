#include<AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


int trigPin=42;
int echoPin=43;
float pingTime;
float cm;
int p=100;

void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);

}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/29;
cm=pingTime/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm);
Serial.println(" cm");
delay(10);

if(cm==0.0)

{

motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("FORWARD");

}

else if(cm>30.0)

{

motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("FORWARD");

}

else if(cm<15.0 and cm>10.0)

{

motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
Serial.println("STOP");

}

else if(cm<10.0)

{

motor1.setSpeed(p);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(BACKWARD);
Serial.println("BACKWARD");

}

else if(cm<30.0)

{

motor1.setSpeed(0);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("LEFT TURN");

}
}
