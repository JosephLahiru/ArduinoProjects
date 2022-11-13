#include<AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int x=0;
int p=100;
int trigPin=42;
int echoPin=43;
float pingTime;
float cm;

void setup(){
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
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
    delay(20);
    x=0;
  }
else if(x=='B'){
    reverse();
    delay(20);
    x=0;
  }
else if(x=='L'){
    left();
    delay(20);
    x=0;
  }
else if(x=='R'){
    right();
    delay(20);
    x=0;
  }
  else if(x=='G'){
    forwardleft();
    delay(20);
    x=0;
  }
else if(x=='I'){
    forwardright();
    delay(20);
    x=0;
  }
else if(x=='H'){
    backwardleft();
    delay(20);
    x=0;
  }
else if(x=='J'){
    backwardright();
    delay(20);
    x=0;
  }
  else if(x=='W'){
    automatic();
    delay(900000);
    x=0;
  }
else if(x=='w'){
    none();
    delay(20);
    x=0;
  }
else{
    none();
  }
}
}

void forward()
{
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
}
void none()
{
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
}
void reverse()
{
motor1.setSpeed(p);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(BACKWARD);
}
void left()
{
motor1.setSpeed(0);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
}
void forwardleft()
{
motor1.setSpeed(10);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(10);
motor3.run(FORWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
}
void backwardleft()
{
motor1.setSpeed(p);
motor1.run(BACKWARD);
motor2.setSpeed(10);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(10);
motor4.run(BACKWARD);
}
void right()
{
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor4.setSpeed(0);
motor4.run(BACKWARD);
}
void forwardright()
{
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(10);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor4.setSpeed(10);
motor4.run(FORWARD);
}
void backwardright()
{
motor1.setSpeed(10);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(BACKWARD);
motor3.setSpeed(10);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(BACKWARD);
}
void automatic()
{

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
//LCD_normal();
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
//LCD_normal();
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
//LCD_normal();
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
//LCD_normal();
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
//LCD_obstacle();
Serial.println("LEFT TURN");

}

}
