
#include<AFMotor.h>

AF_DCMotor motor1(3); 
AF_DCMotor motor2(4);
#define buzzer 5
#define HL 4
#define BL 2
#define RL 3
#define LS 6
#define RS 7
#define PL 8
#define trigPin 11
#define echoPin 12
float pingTime;
float targetDistance;

int i;
char j;


void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(5,buzzer);
pinMode(4,HL);
pinMode(2,BL);
pinMode(3,RL);
pinMode(6,LS);
pinMode(7,RS);
pinMode(8,PL);


while(!Serial.available());
j=Serial.read();
}

void loop(){ 
if(j=='a'||j=='A')

{
automatic();
}

else if(j=='m'||j=='M')

{
manual();
}

while(!Serial.available());
j=Serial.read();

}
void manual()
{

char com;
while(!Serial.available());

g:
com=Serial.read();

if(com=='f'||com=='F')

{

while(!Serial.available())

{

motor1.setSpeed(255); 
motor1.run(FORWARD); 
motor2.setSpeed(255); 
motor2.run(FORWARD);
Serial.println("FORWARD");

}

}

else if(com=='b'||com=='B')

{

while(!Serial.available())

{

motor1.setSpeed(255); 
motor1.run(BACKWARD); 
motor2.setSpeed(255); 
motor2.run(BACKWARD);
digitalWrite(3,HIGH);
Serial.println("BACKWARD");

}

}

else if(com=='l'||com=='L')

{

while(!Serial.available())

{

motor1.setSpeed(255); 
motor1.run(FORWARD); 
motor2.setSpeed(0);
motor2.run(RELEASE);
digitalWrite(6,HIGH);
delay(800);
digitalWrite(6,LOW);
delay(800);
Serial.println("LEFT TURN");

}

}

else if(com=='r'||com=='R')

{

while(!Serial.available())

{

motor1.setSpeed(0);
motor1.run(RELEASE); 
motor2.setSpeed(255); 
motor2.run(FORWARD);
digitalWrite(7,HIGH);
delay(800);
digitalWrite(7,LOW);
delay(800); 
Serial.println("RIGHT TURN");

}

}

else if(com=='n'||com=='N')

{
  while(!Serial.available())
{
  
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(255);
motor2.run(BACKWARD);
Serial.println("BACK LEFT");

}

}
else if(com=='p'||com=='P')

{
  while(!Serial.available())
{
  
 motor1.setSpeed(255);
 motor1.run(BACKWARD);
 motor2.setSpeed(0);
 motor2.run(RELEASE);
 Serial.println("BACK RIGHT");

}

}
else if(com=='h'||com=='H')

{
  while(!Serial.available())
{
  
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(200);
  Serial.println("HORN");

}

}
else if(com=='q'||com=='Q')

{
  while(!Serial.available())
{
  
  digitalWrite(4,HIGH);
  Serial.println("HEAD LIGHT");

}

}
else if(com=='c'||com=='C')

{
  while(!Serial.available())
{
  
  digitalWrite(8,HIGH);
  Serial.println("PARKING");

}

}
else if(com=='w'||com=='W')

{
  while(!Serial.available())
{
  
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  digitalWrite(2,HIGH);
  Serial.println("BREAK");

}

}
else if(com=='o'||com=='O')

{
  while(!Serial.available())
{
  
  motor1.setSpeed(205);
  motor1.run(FORWARD);
  motor2.setSpeed(205);
  motor2.run(BACKWARD);
  Serial.println("ROUND MOVE");

}

}
else if(com=='x'||com=='X')

{
  while(!Serial.available())
{
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  delay(800);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  delay(800);
  Serial.println("HAZARD");

}

}
else if(com=='u'||com=='U')

{
  while(!Serial.available())
{
  
  digitalWrite(buzzer,HIGH);
  delay(400);
  digitalWrite(buzzer,LOW);
  delay(400);
  digitalWrite(2,HIGH);
  delay(400);
  digitalWrite(2,LOW);
  delay(400);
  digitalWrite(3,HIGH);
  delay(400);
  digitalWrite(3,LOW);
  delay(400);
  digitalWrite(4,HIGH);
  delay(400);
  digitalWrite(4,LOW);
  delay(400);
  digitalWrite(6,HIGH);
  delay(400);
  digitalWrite(6,LOW);
  delay(400);
  digitalWrite(7,HIGH);
  delay(400);
  digitalWrite(7,LOW);
  delay(400);
  motor1.setSpeed(55);
  motor1.run(FORWARD);
  motor2.setSpeed(55);
  delay(1000);
  motor2.run(FORWARD);
  motor1.setSpeed(105);
  motor1.run(FORWARD);
  motor2.setSpeed(105);
  delay(1250);
  motor2.run(FORWARD);
  motor1.setSpeed(155);
  motor1.run(FORWARD);
  motor2.setSpeed(155);
  motor2.run(FORWARD);
  delay(1500);
  motor1.setSpeed(205);
  motor1.run(FORWARD);
  motor2.setSpeed(205);
  motor2.run(FORWARD);
  delay(1750);
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  delay(2000);
  Serial.println("SYSTEM CHECK");

}

}
else if(com=='d'||com=='D')

{
  while(!Serial.available())
{
  
 motor1.setSpeed(155);
 motor1.run(FORWARD);
 motor2.setSpeed(55);
 motor2.run(BACKWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(4,HIGH);
 delay(500);
 motor1.setSpeed(155);
 motor1.run(FORWARD);
 motor2.setSpeed(55);
 motor2.run(BACKWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(8,HIGH);
 delay(500);
 motor1.setSpeed(55);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(4,HIGH);
 delay(500);
 motor1.setSpeed(55);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(8,HIGH);
 delay(500);
 motor1.setSpeed(255);
 motor1.run(FORWARD);
 motor2.setSpeed(255);
 motor2.run(BACKWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(4,HIGH);
 delay(1000);
 motor1.setSpeed(55);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(8,HIGH);
 delay(500);
 motor1.setSpeed(55);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(4,HIGH);
 delay(500);
 motor1.setSpeed(255);
 motor1.run(BACKWARD);
 motor2.setSpeed(255);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(8,HIGH);
 delay(1000);
 motor1.setSpeed(155);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(BACKWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(4,HIGH);
 delay(500);
 motor1.setSpeed(155);
 motor1.run(FORWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(8,HIGH);
 delay(500);
 Serial.println("DANCE");

}

}

else if(com=='y'||com=='Y')

{
  while(!Serial.available())
{
  
 motor1.setSpeed(255);
 motor1.run(FORWARD);
 motor2.setSpeed(55);
 motor2.run(FORWARD);
 delay(1000);
 motor1.setSpeed(55);
 motor1.run(FORWARD);
 motor2.setSpeed(255);
 motor2.run(55);
 digitalWrite(6,HIGH);
 digitalWrite(7,HIGH);
 delay(800);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 delay(800);
 Serial.println("BULLETPROOF MODE");

}

}

if(com=='f'||com=='F'||com=='b'||com=='B'||com=='l'||com=='L'||com=='r'||com=='R'||com=='n'||com=='N'||com=='p'||com=='P'||com=='h'||com=='H'||com=='q'||com=='Q'||com=='c'||com=='C'||com=='w'||com=='W'||com=='o'||com=='O'||com=='x'||com=='X'||com=='u'||com=='U'||com=='d'||com=='D'||com=='y'||com=='Y')

goto g;

else if(com=='e'||com=='E')

{

  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  Serial.println("STOPPED");

}

}

void automatic()

{

g:

while(!Serial.available())

{

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/29;
targetDistance=pingTime/2;

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
  digitalWrite(3,HIGH);
  Serial.println("BACKWARD");

}

else if(targetDistance<30.0)

{

  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  digitalWrite(6,HIGH);
  delay(800);
  digitalWrite(6,LOW);
  delay(800);
  Serial.println("LEFT TURN");
  
}

}

int com=Serial.read();
if(com!='e'||com!='E')
goto g;

}

