#include<AFMotor.h>
#define trigPin 11
#define echoPin 12

int a=2,b=3,c=4,d=5,e=6;

  float pingTime;
  float dist;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  Serial.begin(9600); 
}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/29;
dist=pingTime/2;

  if(dist<20 && dist>1) 
  {
    obstacleAvoidance();      
  } else {
    lineFollow();  
  } 
}

void lineFollow(){
  
  if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==LOW)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))

  {
    motor1.setSpeed(255); 
    motor1.run(FORWARD); 
    motor2.setSpeed(255); 
    motor2.run(FORWARD);
    Serial.println("FORWARD");delay(1);
  }
  else if((digitalRead(a)==HIGH)&&(digitalRead(b)==LOW)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))
  {
    motor1.setSpeed(255); 
    motor1.run(FORWARD); 
    motor2.setSpeed(64);
    motor2.run(FORWARD);
    Serial.println("LEFT");delay(1);
  }
  else if((digitalRead(a)==LOW)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))
  {
    motor1.setSpeed(255);
    motor1.run(FORWARD); 
    motor2.setSpeed(128); 
    motor2.run(FORWARD);
    Serial.println("LEFT STRONG");delay(1);
  }
  else if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==LOW)&&(digitalRead(e)==HIGH))
  {
    motor1.setSpeed(64);
    motor1.run(FORWARD);
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    Serial.println("RIGHT");delay(1);
  
  }
  else if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==LOW))
  {
    motor1.setSpeed(128);
    motor1.run(FORWARD);
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    Serial.println("RIGHT STRONG");delay(1);
  
  }
  else if((digitalRead(a)==LOW)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==LOW))
  {
    motor1.setSpeed(192);
    motor1.run(FORWARD);
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    Serial.println("CUBE RIGHT");delay(1);
  
  }
  else if((digitalRead(a)==LOW)&&(digitalRead(b)==LOW)&&(digitalRead(c)==LOW)&&(digitalRead(d)==LOW)&&(digitalRead(e)==LOW))
  {
    motor1.setSpeed(0);
    motor1.run(RELEASE);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
    Serial.println("ALL_BLACK");delay(1);
  }
  else if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH)&&(digitalRead(c)==HIGH)&&(digitalRead(d)==HIGH)&&(digitalRead(e)==HIGH))
  {
    motor1.setSpeed(0);
    motor1.run(RELEASE);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
    Serial.println("ALL_WHITE");delay(1);
 }
 }


void obstacleAvoidance() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/29;
dist=pingTime/2;


if(dist>20.0)

{

  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  Serial.println("FORWARD");

}

else if(dist<10.0)

{

  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  Serial.println("BACKWARD");

}

else if(dist<20.0)

{

  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  Serial.println("LEFT TURN");
  
}

}

