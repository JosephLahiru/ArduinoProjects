#include<AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int a=2,b=3,c=4,d=5,e=6;
int i;
char j;
int s=105;
int p=155;
int trigPin=42;
int echoPin=43;
int trigPin1=44;
int echoPin1=45;
int trigPin2=46;
int echoPin2=47;
float pingTime;
float cm;
float pingTime1;
float cm1;
float pingTime2;
float cm2;
int x;
int y;
int z;
int l;
int m;
int equal;
int n=3;
int co=1;

void setup(){
pinMode(trigPin, OUTPUT);
pinMode(a, INPUT);
pinMode(b, INPUT);
pinMode(c, INPUT);
pinMode(d, INPUT);
pinMode(e, INPUT);
Serial.begin(9600); 

}

void fp(){
motor1.setSpeed(160);
motor1.run(FORWARD);
motor2.setSpeed(160);
motor2.run(FORWARD);
motor3.setSpeed(170);
motor3.run(FORWARD);
motor4.setSpeed(170);
motor4.run(FORWARD);
Serial.println("FORWARD");
}

void f1()
{
motor1.setSpeed(100);
motor1.run(FORWARD);
motor2.setSpeed(100);
motor2.run(FORWARD);
motor3.setSpeed(150);
motor3.run(FORWARD);
motor4.setSpeed(150);
motor4.run(FORWARD);
Serial.println("FORWARD");
}

void f2()
{
motor1.setSpeed(85);
motor1.run(FORWARD);
motor2.setSpeed(85);
motor2.run(FORWARD);
motor3.setSpeed(135);
motor3.run(FORWARD);
motor4.setSpeed(135);
motor4.run(FORWARD);
Serial.println("FORWARD");  
}

void fc()
{
motor1.setSpeed(105);
motor1.run(FORWARD);
motor2.setSpeed(105);
motor2.run(FORWARD);
motor3.setSpeed(155);
motor3.run(FORWARD);
motor4.setSpeed(155);
motor4.run(FORWARD);
Serial.println("FORWARD");
}

void f3()
{ 
motor1.setSpeed(100);
motor1.run(FORWARD);
motor2.setSpeed(100);
motor2.run(FORWARD);
motor3.setSpeed(150);
motor3.run(FORWARD);
motor4.setSpeed(150);
motor4.run(FORWARD);
Serial.println("FORWARD");
}

void f4()
{
motor1.setSpeed(85);
motor1.run(FORWARD);
motor2.setSpeed(85);
motor2.run(FORWARD);
motor3.setSpeed(135);
motor3.run(FORWARD);
motor4.setSpeed(135);
motor4.run(FORWARD);
Serial.println("FORWARD"); 
}

void f9()
{
motor1.setSpeed(45);
motor1.run(FORWARD);
motor2.setSpeed(45);
motor2.run(FORWARD);
motor3.setSpeed(95);
motor3.run(FORWARD);
motor4.setSpeed(95);
motor4.run(FORWARD);
Serial.println("FORWARD"); 

}
void f5()
{  
motor1.setSpeed(50);
motor1.run(FORWARD);
motor2.setSpeed(50);
motor2.run(FORWARD);
motor3.setSpeed(100);
motor3.run(FORWARD);
motor4.setSpeed(100);
motor4.run(FORWARD);
Serial.println("FORWARD");
}  
 
void f6()
{
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
Serial.println("BREAK");
}

void left()
{
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(s);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(0);
motor4.run(RELEASE);
Serial.println("LEFT TURN");
}

void right()
{
motor1.setSpeed(s);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");
}

void backward()
{
motor1.setSpeed(s);
motor1.run(BACKWARD);
motor2.setSpeed(s);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(BACKWARD);
Serial.println("BACKWARD");
}
 
void set () 
{
 if(digitalRead(a)== co){x=16;}else{x=0;} 
 if(digitalRead(b)== co){ y=8;}else{y=0;}
 if(digitalRead(c)== co){ z=4;}else{z=0;}
 if(digitalRead(d)== co){ l=2;}else{l=0;}
 if(digitalRead(e)== co){ m=1;}else{m=0;}
 equal =x+y+z+l+m;
}

void e2ra () 
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
}

void e3ra () 
{
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
pingTime1 = pulseIn(echoPin1, HIGH);
pingTime1=pingTime1/29;
cm1=pingTime1/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm1);
Serial.println(" cm1");
delay(10);
}

void e4ra () 
{
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
pingTime2 = pulseIn(echoPin2, HIGH);
pingTime2=pingTime2/29;
cm2=pingTime2/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm2);
Serial.println(" cm2");
delay(10);
}

void loop(){
x:
  set(); 
if     (equal==1) {left();}        
else if(equal==2) {f3();}
else if(equal==3) {left();}
else if(equal==6) {f3();}
else if(equal==4) {n=0; f1();}
else if(equal==12){f2();} 
else if(equal==24){right();}
else if(equal==8) {f2();}
else if(equal==16){right();}
else if(equal==7) {left();}
else if(equal==28){right();}

while(equal==31){
f1();
e2ra();
e3ra();
e4ra();
if(cm<10)
{
  if(cm1>8){left();}
  else if(cm2>8){right();}
  else if(cm>15){goto x;}
}
}
 


}

