#include<AFMotor.h>
#include <LiquidCrystal.h>

int a=2,b=3,c=4,d=5,e=6;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
LiquidCrystal LCD(A5, A4, A0, A1, A2, A3);

int i;

char j;

int trigPin=12;

int echoPin=13;

float pingTime;

float targetDistance;

int echoPin2=9;

int trigPin2=10;

float pingTime2;

float targetDistance2;

void setup() {

Serial.begin(9600);

pinMode(trigPin, OUTPUT);

LCD.begin(16,2);

LCD_start();

while(!Serial.available());

j=Serial.read();

}

void loop() {

if(j=='a'||j=='A')

{ j='Z';

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem1[]={'A','U','T','O','M','A','T','I','C',' ','C','T','R','L'};

char displayitem2[]={'A','C','T','I','V','A','T','E','D'};

for(i=0;i<14;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem1[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<9;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem2[i]);

LCD.print("_");

Serial.println("auto_controlling_activated");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(9,1);

LCD.print(" ");

delay(500);

LCD.setCursor(9,1);

LCD.print("_");

}

automatic();

}

if(j=='i'||j=='I')

{ j='Z';

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem1[]={'L','I','N','E','F','O','L','L','O','W','I','N','G'};

char displayitem2[]={'A','C','T','I','V','A','T','E','D'};

for(i=0;i<14;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem1[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<9;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem2[i]);

LCD.print("_");

Serial.println("line following activated");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(9,1);

LCD.print(" ");

delay(500);

LCD.setCursor(9,1);

LCD.print("_");

}

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/29;
targetDistance=pingTime/2;

  if(targetDistance<20 && targetDistance>1) 
  {
    obstacleAvoidance();      
  } else {
    lineFollow();  
  } 

}

else if(j=='m'||j=='M')

{

j='Z';

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem3[]={'M','A','N','U','A','L',' ','C','O','N','T','R','O','L'};

char displayitem4[]={'A','C','T','I','V','A','T','E','D'};

for(i=0;i<14;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem3[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<9;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem4[i]);

LCD.print("_");

Serial.println("manual_controlling_activated");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(9,1);

LCD.print(" ");

delay(500);

LCD.setCursor(9,1);

LCD.print("_");

}

manual();

}

else

{

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem5[]={'W','A','I','T','I','N','G',' ',' ','F','O','R'};

char displayitem6[]={'I','N','S','T','R','U','C','T','I','O','N'};

for(i=0;i<12;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem5[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<11;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem6[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(11,1);

LCD.print(" ");

delay(500);

LCD.setCursor(11,1);

LCD.print("_");

}

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

motor1.setSpeed(200);

motor1.run(FORWARD);

motor2.setSpeed(200);

motor2.run(FORWARD);

Serial.println("FORWARD");

}

}

else if(com=='b'||com=='B')

{

while(!Serial.available())

{

motor1.setSpeed(200);

motor1.run(BACKWARD);

motor2.setSpeed(200);

motor2.run(BACKWARD);

Serial.println("BACKWARD");

}

}

else if(com=='l'||com=='L')

{

while(!Serial.available())

{

motor1.setSpeed(0);

motor1.run(RELEASE);

motor2.setSpeed(200);

motor2.run(FORWARD);

Serial.println("LEFT TURN");

}

}

else if(com=='r'||com=='R')

{

while(!Serial.available())

{

motor1.setSpeed(200);

motor1.run(FORWARD);

motor2.setSpeed(0);

motor2.run(RELEASE);

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

else if(com=='u'||com=='U')

{
  
  while(!Serial.available())
{
  
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

 Serial.println("BULLETPROOF MODE");

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

  Serial.println("BREAK");

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

 delay(500);
 
 motor1.setSpeed(155);
 
 motor1.run(FORWARD);
 
 motor2.setSpeed(55);
 
 motor2.run(BACKWARD);

 delay(500);
 
 motor1.setSpeed(55);
 
 motor1.run(BACKWARD);
 
 motor2.setSpeed(155);
 
 motor2.run(FORWARD);

 delay(500);
 
 motor1.setSpeed(55);
 
 motor1.run(BACKWARD);
 
 motor2.setSpeed(155);
 
 motor2.run(FORWARD);

 delay(500);
 
 motor1.setSpeed(255);
 
 motor1.run(FORWARD);
 
 motor2.setSpeed(255);
 
 motor2.run(BACKWARD);

 delay(1000);
 
 motor1.setSpeed(55);
 
 motor1.run(BACKWARD);
 
 motor2.setSpeed(155);
 
 motor2.run(FORWARD);

 delay(500);
 
 motor1.setSpeed(55);
 
 motor1.run(BACKWARD);
 
 motor2.setSpeed(155);
 
 motor2.run(FORWARD);

 delay(500);
 
 motor1.setSpeed(255);
 
 motor1.run(BACKWARD);
 
 motor2.setSpeed(255);
 
 motor2.run(FORWARD);

 delay(1000);
 
 motor1.setSpeed(155);
 
 motor1.run(BACKWARD);
 
 motor2.setSpeed(155);
 
 motor2.run(BACKWARD);

 delay(500);
 
 motor1.setSpeed(155);
 
 motor1.run(FORWARD);
 
 motor2.setSpeed(155);
 
 motor2.run(FORWARD);

 delay(500);

 Serial.println("DANCE");

}

}

if(com=='f'||com=='F'||com=='b'||com=='B'||com=='l'||com=='L'||com=='r'||com=='R'||com=='n'||com=='N'||com=='p'||com=='P'||com=='o'||com=='O'||com=='u'||com=='U'||com=='y'||com=='Y'||com=='w'||com=='W'||com=='d'||com=='D')

goto g;

else if(com=='e'||com=='E')

{

motor1.setSpeed(0);

motor1.run(RELEASE);

motor2.setSpeed(0);

motor2.run(RELEASE);

LCD_final();

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

Serial.print("The Distance to Target is: ");

Serial.print(targetDistance);

Serial.println(" cm");

delay(10);

if(targetDistance==0.0)

{

motor1.setSpeed(200);

motor1.run(FORWARD);

motor2.setSpeed(200);

motor2.run(FORWARD);

LCD_normal();

Serial.println("FORWARD");

}

else if(targetDistance>30.0)

{

motor1.setSpeed(200);

motor1.run(FORWARD);

motor2.setSpeed(200);

motor2.run(FORWARD);

LCD_normal();

Serial.println("FORWARD");

}

else if(targetDistance<15.0 and targetDistance>10.0)

{

motor1.setSpeed(200);

motor1.run(RELEASE);

motor2.setSpeed(200);

motor2.run(RELEASE);

LCD_normal();

Serial.println("STOP");

}

else if(targetDistance<10.0)

{

motor1.setSpeed(200);

motor1.run(BACKWARD);

motor2.setSpeed(200);

motor2.run(BACKWARD);

LCD_normal();

Serial.println("BACKWARD");

}

else if(targetDistance<30.0)

{

motor1.setSpeed(0);

motor1.run(RELEASE);

motor2.setSpeed(200);

motor2.run(FORWARD);

LCD_obstacle();

Serial.println("LEFT TURN");

}

}

int com=Serial.read();

if(com=='e'||com=='E')

{

motor1.setSpeed(0);

motor1.run(RELEASE);

motor2.setSpeed(0);

motor2.run(RELEASE);

LCD_final();

Serial.println("STOPPED");

}
else goto g;
}

void LCD_start()

{

//int i;

LCD.setCursor(0,0);

LCD.print("* WELCOME SIR *");

delay(1000);

LCD.setCursor(0,1);

LCD.print(" PROJECT : ATOM ");

delay(2000);
LCD.clear();
for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem7[]={'C','H','E','C','K','I','N','G',' ','M','O','T','O','R','S'};

char displayitem8[]={'C','O','M','P','L','E','T','E','D'};

for(i=0;i<15;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem7[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(200);

LCD.setCursor(15,0);

LCD.print("_");

delay(200);

LCD.setCursor(15,0);

LCD.print(" ");

}

for(i=0;i<9;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem8[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(9,1);

LCD.print(" ");

delay(500);

LCD.setCursor(9,1);

LCD.print("_");

}

for(i=0;i<2;i++)

{
LCD.clear();
LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem9[]={'B','A','S','E','C','O','D','E'};

char displayitem10[]={'U','P','D','A','T','E','D'};

for(i=0;i<8;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem9[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(200);

LCD.setCursor(8,0);

LCD.print("_");

delay(200);

LCD.setCursor(8,0);

LCD.print(" ");

}

for(i=0;i<7;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem10[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(7,1);

LCD.print(" ");

delay(500);

LCD.setCursor(7,1);

LCD.print("_");

}

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem11[]={'I','N','T','I','A','L','I','S','I','N','G'};

char displayitem12[]={'S','E','Q','U','E','N','C','E'};

for(i=0;i<11;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem11[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<8;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem12[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(8,1);

LCD.print(" ");

delay(500);

LCD.setCursor(8,1);

LCD.print("_");

}

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem5[]={'W','A','I','T','I','N','G',' ',' ','F','O','R'};

char displayitem6[]={'I','N','S','T','R','U','C','T','I','O','N'};

for(i=0;i<12;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem5[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<11;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem6[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(11,1);

LCD.print(" ");

delay(500);

LCD.setCursor(11,1);

LCD.print("_");

}

}

void LCD_normal()

{

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

LCD.setCursor(0,0);

LCD.print("ULTRASONIC");

LCD.setCursor(0,1);

LCD.print("INITIATED");

LCD.setCursor(11,0);

LCD.print(targetDistance);

delay(50);

}

void LCD_obstacle()

{

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

LCD.setCursor(0,0);

LCD.print("OBSTACLE");

LCD.setCursor(0,1);

LCD.print("DETECTED");

LCD.setCursor(11,0);

LCD.print(targetDistance);

delay(100);

}

void LCD_final()

{

LCD.setCursor(0,0);

LCD.print("** THANK YOU **");

delay(1000);

LCD.setCursor(0,1);

LCD.print(" PROJECT : ATOM ");

delay(2000);

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

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

digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
pingTime2 = pulseIn(echoPin2, HIGH);
pingTime2=pingTime2/29;
targetDistance2=pingTime2/2;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/29;
targetDistance=pingTime/2;


if(targetDistance>20.0)

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

else if(targetDistance<20.0)

{

  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  Serial.println("LEFT TURN");
  
}
else if(targetDistance2<20.0)

{
  
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  Serial.println("FORWARD");

}

else if(targetDistance2>20.0)

{
  
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  Serial.println("LEFT TURN");

}

else if(targetDistance2<20.0)

{
  
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  Serial.println("FORWARD");

}

else if(targetDistance2>20.0)

{
  
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  Serial.println("LEFT TURN");

}
}
