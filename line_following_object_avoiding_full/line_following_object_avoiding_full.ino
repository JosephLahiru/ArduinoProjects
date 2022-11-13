#include<AFMotor.h>

int a=2,b=3,c=4,d=5,e=6;
int trigPin=A0;
int echoPin=A1;
float pingTime;
float targetDistance;
int led=10;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led,OUTPUT);
}

void loop(){ 
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/29;
targetDistance=pingTime/2;


if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==LOW)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))
  {
motor1.setSpeed(160);
motor1.run(FORWARD);
motor2.setSpeed(160);
motor2.run(FORWARD);
motor3.setSpeed(160);
motor3.run(FORWARD);
motor4.setSpeed(160);
motor4.run(FORWARD);
Serial.println("FORWARD");
delay(1);
  }
else if((digitalRead(a)==HIGH)&&(digitalRead(b)==LOW)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))
  {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(80);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(80);
motor4.run(RELEASE);
Serial.println("S1LTURN");
delay(1);
  }
else if((digitalRead(a)==LOW)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))
  {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(160);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(160);
motor4.run(RELEASE);
Serial.println("S2LTURN");
delay(1);
  }
else if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==LOW)&&(digitalRead(e)==HIGH))
  {
motor1.setSpeed(80);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(80);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(BACKWARD);
Serial.println("S2RTURN");
delay(1); 
  }
else if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==LOW))
  {
motor1.setSpeed(160);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(160);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(BACKWARD);
Serial.println("S1RTURN");
delay(1);
  }
else if((digitalRead(a)==LOW)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==LOW))
  {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(100);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(100);
motor4.run(RELEASE);
Serial.println("S2#S2LTURN");
delay(1);
  }
else if((digitalRead(a)==LOW)&&(digitalRead(b)==LOW)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))
  {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(90);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(90);
motor4.run(RELEASE);
Serial.println("S1S2LTURN");
delay(5);

  }
else if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==LOW)&&(digitalRead(e)==LOW))
  {
motor1.setSpeed(90);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(90);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(BACKWARD);
Serial.println("S1S2RTURN");
delay(5);
  }
else if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))
  {
motor1.setSpeed(60);
motor1.run(FORWARD);
motor2.setSpeed(60);
motor2.run(FORWARD);
motor3.setSpeed(60);
motor3.run(FORWARD);
motor4.setSpeed(60);
motor4.run(FORWARD);
Serial.println("FORWARD");
delay(1);
  }
while((digitalRead(a)==LOW)&&(digitalRead(b)==LOW)&&(digitalRead(c)==LOW)&&(digitalRead(d)==LOW)&&(digitalRead(e)==LOW))
  {
digitalWrite(13,HIGH);

if(targetDistance==0.0)

{

  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  Serial.println("FORWARD");

}

else if(targetDistance>30.0)

{

  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  Serial.println("FORWARD");

}

else if(targetDistance<10.0)

{

  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  Serial.println("BACKWARD");

}

else if(targetDistance<30.0)

{

  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  Serial.println("LEFT TURN");
  
}

  }

         }



