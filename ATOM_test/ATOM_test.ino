#include<AFMotor.h>
#include <LiquidCrystal.h>
#include <Servo.h> 

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo servo ; 
LiquidCrystal LCD(A12, A13, A8, A9, A10, A11);

int a=37,b=38,c=39,d=40,e=41;
int buzzer=30;
int HL=31;
int BL=32;
int RL=33;
int LS=34;
int RS=35;
int PL=36;
int i;
char j;
int s=105;
int p=155;
int trigPin=42;
int echoPin=43;
float pingTime;
float cm;
int x;
int y;
int z;
int l;
int m;
int hoba;
int n=3;

void setup() {

Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(HL,OUTPUT);
pinMode(BL,OUTPUT);
pinMode(RL,OUTPUT);
pinMode(LS,OUTPUT);
pinMode(RS,OUTPUT);
pinMode(PL,OUTPUT);
pinMode(trigPin, OUTPUT);
servo.write(90); 
servo.attach(9);
LCD.begin(16,2);
LCD_start();
while(!Serial.available());
j=Serial.read();

}



void LCD_start()

{

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
LCD.print(cm);
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
LCD.print(cm);
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

void engineStart()

{

motor1.setSpeed(60);
motor1.run(FORWARD);
motor2.setSpeed(60);
motor2.run(FORWARD);
motor3.setSpeed(60);
motor3.run(FORWARD);
motor4.setSpeed(60);
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
void loop() {

if(j=='a'||j=='A')

{
  
j='Z';
LCD.clear();
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

else if(j=='i'||j=='I')

{
  
j='Z';
LCD.clear();
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

linefollowing();

}

if(j=='m'||j=='M')

{
  
j='Z';
LCD.clear();
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

}

else if(com=='b'||com=='B')

{

while(!Serial.available())

{

motor1.setSpeed(p);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(BACKWARD);
digitalWrite(RL,HIGH);
Serial.println("BACKWARD");

}

}

else if(com=='l'||com=='L')

{

while(!Serial.available())

{

motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(0);
motor4.run(RELEASE);
digitalWrite(LS,HIGH);
delay(800);
digitalWrite(LS,LOW);
delay(800);
Serial.println("LEFT TURN");

}

}

else if(com=='r'||com=='R')

{

while(!Serial.available())

{

motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(BACKWARD);
digitalWrite(RS,HIGH);
delay(800);
digitalWrite(RS,LOW);
delay(800);
Serial.println("RIGHT TURN");

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
digitalWrite(BL,HIGH);
delay(400);
digitalWrite(BL,LOW);
delay(400);
digitalWrite(HL,HIGH);
delay(400);
digitalWrite(HL,LOW);
delay(400);
digitalWrite(PL,HIGH);
delay(400);
digitalWrite(PL,LOW);
delay(400);
digitalWrite(LS,HIGH);
delay(400);
digitalWrite(LS,LOW);
delay(400);
digitalWrite(RS,HIGH);
delay(400);
digitalWrite(RS,LOW);
delay(400);  
motor1.setSpeed(55);
motor1.run(FORWARD);
motor2.setSpeed(55);
motor2.run(FORWARD);
motor3.setSpeed(55);
motor3.run(FORWARD);
motor4.setSpeed(55);
motor4.run(FORWARD);
delay(1000);
motor1.setSpeed(105);
motor1.run(FORWARD);
motor2.setSpeed(105);
motor2.run(FORWARD);
motor3.setSpeed(105);
motor3.run(FORWARD);
motor4.setSpeed(105);
motor4.run(FORWARD);
delay(1250);
motor1.setSpeed(155);
motor1.run(FORWARD);
motor2.setSpeed(155);
motor2.run(FORWARD);
motor3.setSpeed(155);
motor3.run(FORWARD);
motor4.setSpeed(155);
motor4.run(FORWARD);
delay(1500);
motor1.setSpeed(205);
motor1.run(FORWARD);
motor2.setSpeed(205);
motor2.run(FORWARD);
motor3.setSpeed(205);
motor3.run(FORWARD);
motor4.setSpeed(205);
motor4.run(FORWARD);
delay(1750);
motor1.setSpeed(255);
motor1.run(FORWARD);
motor2.setSpeed(255);
motor2.run(FORWARD);
motor3.setSpeed(255);
motor3.run(FORWARD);
motor4.setSpeed(255);
motor4.run(FORWARD);
delay(2000);
Serial.println("SYSTEM CHECK");

}

}

else if(com=='y'||com=='Y')

{

while(!Serial.available())
  
{

motor1.setSpeed(p);
motor1.run(FORWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor2.setSpeed(55);
motor2.run(FORWARD);
motor4.setSpeed(55);
motor4.run(FORWARD);
delay(700);
motor1.setSpeed(55);
motor1.run(FORWARD);
motor3.setSpeed(55);
motor3.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
digitalWrite(LS,HIGH);
digitalWrite(RS,HIGH);
delay(800);
digitalWrite(LS,LOW);
digitalWrite(RS,LOW);
delay(800);
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
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
digitalWrite(BL,HIGH);
Serial.println("BREAK");

}

}

else if(com=='7')

{
  
while(!Serial.available())
  
{
  
digitalWrite(buzzer,HIGH);
delay(200);
digitalWrite(buzzer,LOW);
delay(200);  
 
}

}

else if(com=='8')

{
  
while(!Serial.available())
  
{
  
digitalWrite(HL,HIGH); 
 
}

}

else if(com=='9')

{
  
while(!Serial.available())
  
{
  
digitalWrite(PL,HIGH); 
 
}

}


if(com=='f'||com=='F'||com=='b'||com=='B'||com=='l'||com=='L'||com=='r'||com=='R'||com=='u'||com=='U'||com=='y'||com=='Y'||com=='w'||com=='W'||com=='7'||com=='8'||com=='9')

goto g;

else if(com=='e'||com=='E')

{

motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
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
LCD_normal();
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
LCD_normal();
Serial.println("FORWARD");

}

else if(cm<16.0 & cm>13.0)

{

motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
LCD_normal();
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
LCD_normal();
Serial.println("BACKWARD");

}

else if(cm<20.0)

{

motor1.setSpeed(0);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
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
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
LCD_final();
Serial.println("STOPPED");

}

else goto g;

}

void linefollowing()

{

none();
delay(3000);
engineStart();
delay(2000);  

g:
while(!Serial.available())

{

e:

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

if (cm<=20)

{

servo.write(60);
motor1.setSpeed(60);
motor1.run(FORWARD);
motor2.setSpeed(60);
motor2.run(FORWARD);
motor3.setSpeed(60);
motor3.run(FORWARD);
motor4.setSpeed(60);
motor4.run(FORWARD);
Serial.println("FORWARD");  

} 

else if (cm<=15)

{
  
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(60);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(60);
motor4.run(FORWARD);
servo.write(0);
Serial.println("LEFT TURN");
} 

else if(cm<=20)

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

}

else if(cm<20 & cm>15)

{
  
motor1.setSpeed(60);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(60);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");

}

else if(cm<20)

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

} 

else if(cm<20 & cm>15)

{
  
motor1.setSpeed(60);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(60);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");
servo.write(60);

} 

else if(cm>15){
  
x:

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

if(digitalRead(a)== 1){x=16;}else{x=0;} 
if(digitalRead(b)== 1){ y=8;}else{y=0;} 
if(digitalRead(c)== 1){ z=4;}else{z=0;} 
if(digitalRead(d)== 1){ l=2;}else{l=0;}
if(digitalRead(e)== 1){ m=1;}else{m=0;} 
hoba =x+y+z+l+m; 

if(cm<=21){goto e;}

if     (hoba==1) {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("LEFT TURN");
}   

else if(cm<=21){goto e;}
     
else if(hoba==2) {
motor1.setSpeed(70);
motor1.run(FORWARD);
motor2.setSpeed(70);
motor2.run(FORWARD);
motor3.setSpeed(70);
motor3.run(FORWARD);
motor4.setSpeed(70);
motor4.run(FORWARD);
Serial.println("FORWARD");
}

else if(cm<=21){goto e;}

else if(hoba==3) {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("LEFT TURN");
}

else if(cm<=21){goto e;}

else if(hoba==6) {
motor1.setSpeed(70);
motor1.run(FORWARD);
motor2.setSpeed(70);
motor2.run(FORWARD);
motor3.setSpeed(70);
motor3.run(FORWARD);
motor4.setSpeed(70);
motor4.run(FORWARD);
Serial.println("FORWARD");
}

else if(cm<=21){goto e;}

else if(hoba==4) {
n=0; 
motor1.setSpeed(70);
motor1.run(FORWARD);
motor2.setSpeed(70);
motor2.run(FORWARD);
motor3.setSpeed(70);
motor3.run(FORWARD);
motor4.setSpeed(70);
motor4.run(FORWARD);
Serial.println("FORWARD");
}

else if(cm<=21){goto e;}

else if(hoba==12){
motor1.setSpeed(85);
motor1.run(FORWARD);
motor2.setSpeed(85);
motor2.run(FORWARD);
motor3.setSpeed(85);
motor3.run(FORWARD);
motor4.setSpeed(85);
motor4.run(FORWARD);
Serial.println("FORWARD"); 
} 

else if(cm<=21){goto e;}

else if(hoba==24){
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");
}

else if(cm<=21){goto e;}

else if(hoba==8) {
motor1.setSpeed(85);
motor1.run(FORWARD);
motor2.setSpeed(85);
motor2.run(FORWARD);
motor3.setSpeed(85);
motor3.run(FORWARD);
motor4.setSpeed(85);
motor4.run(FORWARD);
Serial.println("FORWARD"); 
}

else if(cm<=21){goto e;}

else if(hoba==16){
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");
}

else if(cm<=21){goto e;}

else if(hoba==7) {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("LEFT TURN");
}

else if(cm<=21){goto e;}

else if(hoba==28){
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");
}

else if(cm<=21){goto e;}

else if(hoba==31){

while(hoba==31||hoba==7||hoba==15||hoba==28||hoba==30)
{
if(digitalRead(a)== 1){x=16;}else{x=0;} 
if(digitalRead(b)== 1){ y=8;}else{y=0;} 
if(digitalRead(c)== 1){ z=4;}else{z=0;} 
if(digitalRead(d)== 1){ l=2;}else{l=0;}
if(digitalRead(e)== 1){ m=1;}else{m=0;} 
hoba =x+y+z+l+m;
/*
motor1.setSpeed(100);
motor1.run(FORWARD);
motor2.setSpeed(100);
motor2.run(FORWARD);
motor3.setSpeed(150);
motor3.run(FORWARD);
motor4.setSpeed(150);
motor4.run(FORWARD);
Serial.println("FORWARD");
*/
}

while(digitalRead(e)==1)
{
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("LEFT TURN");
}
while(digitalRead(e)!=1)
{
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("LEFT TURN");
}
while(digitalRead(c)!=1)
{
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(p);
motor4.run(FORWARD);
Serial.println("LEFT TURN");
}
while(digitalRead(c)==1){goto x;}
}
 
}

}

int com=Serial.read();

if(com=='e'||com=='E')

{

motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
LCD_final();
Serial.println("STOPPED");

}

else goto g;

}


