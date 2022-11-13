#include<AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
Servo myservo;

int x=0;
int p=200;

void setup(){
Serial.begin(9600);
myservo.attach(9);
myservo.write(55);
}
void forward()
{
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
Serial.println("FORWARD");
myservo.write(55);
}
void none()
{
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
}
void reverse()
{
motor1.setSpeed(p);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(BACKWARD);
myservo.write(55);
}
void left()
{
myservo.write(25);
}
void forwardleft()
{
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
myservo.write(15);
}
void backwardleft()
{
motor1.setSpeed(p);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(BACKWARD);
myservo.write(15);
}
void right()
{
myservo.write(85);
}
void forwardright()
{
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
myservo.write(95);
}
void backwardright()
{
motor1.setSpeed(p);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(BACKWARD);
myservo.write(95);
}
void loop()
{ 
while(1)
{
  
if(Serial.available()>0)
{
x=Serial.read();
}
  Serial.println(x);
if(x=='F'){
    forward();
    delay(1);
    x=0;
  }
else if(x=='B'){
    reverse();
    delay(1);
    x=0;
  }
else if(x=='L'){
    left();
    delay(1);
    x=0;
  }
else if(x=='R'){
    right();
    delay(1);
    x=0;
  }
  else if(x=='G'){
    forwardleft();
    delay(1);
    x=0;
  }
else if(x=='I'){
    forwardright();
    delay(1);
    x=0;
  }
else if(x=='H'){
    backwardleft();
    delay(1);
    x=0;
  }
else if(x=='J'){
    backwardright();
    delay(1);
    x=0;
  }
else{
    none();
  }
}
}
