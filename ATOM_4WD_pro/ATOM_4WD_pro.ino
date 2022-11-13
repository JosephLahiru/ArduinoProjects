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

void fp()

{
  
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

void puse()

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

void ymen()

{
  
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(s);
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

void shmal()

{
  
motor1.setSpeed(s);
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
digitalWrite(RL,HIGH);
Serial.println("BACKWARD");

}

void set () {
if(digitalRead(a)== 1){x=16;}else{x=0;} // if the light sensor a falls on black line it uses binary method
if(digitalRead(b)== 1){ y=8;}else{y=0;} // if the light sensor b falls on black line it uses binary method
if(digitalRead(c)== 1){ z=4;}else{z=0;} // if the light sensor c falls on black line it uses binary method
if(digitalRead(d)== 1){ l=2;}else{l=0;} // if the light sensor d falls on black line it uses binary method
if(digitalRead(e)== 1){ m=1;}else{m=0;} // if the light sensor e falls on black line it uses binary method
hoba =x+y+z+l+m; // save all values in one variabale of light sensors
           
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

motor1.setSpeed(s);
motor1.run(FORWARD);
motor2.setSpeed(s);
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

motor1.setSpeed(s);
motor1.run(FORWARD);
motor2.setSpeed(s);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
LCD_normal();
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
LCD_normal();
Serial.println("STOP");

}

else if(cm<10.0)

{

motor1.setSpeed(s);
motor1.run(BACKWARD);
motor2.setSpeed(s);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(BACKWARD);
LCD_normal();
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

//f1();   
 
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
e2ra();
    
e2ra(); // call function e2ra
if (cm<=4) 
{    // if the distance less than or equal 10    
servo.write(90); // change the servo to 90 degree angle.
do 
{
backward(); // Make the function Backward instantly
e2ra();         // Make the function e2ra instantly
} 
while (cm<=15);  // check the condition if true repeat the loop if not get out
e2ra(); // do e2ra function
servo.write(80);
do { f4(); // do f4 function instantly
e2ra(); // do e2ra function
servo.write(80);
} 
while (cm<=25); // check the condition if true repeat the loop if not get out
do 
{
f1(); // do f1 function instantly 
e2ra(); // do e2ra function instantly
servo.write(10); // change the servo to 180 degree angle.
} 
while(cm>=20); // check the condition if true repeat the loop if not get out 
puse(); // do e2ra function
delay(100); // wait for 100 millisec.
do 
{
f1(); // do f1 function instantly
e2ra(); // do e2ra function instantly
}
while(cm<30); // check the condition if true repeat the loop if not get out
do 
{
f5(); // do f5 function instantly
e2ra(); // do e2ra function instantly
}
while (cm>25); // check the condition if true repeat the loop if not get out
do 
{
f1 (); // do f1 function instantly
e2ra(); // do e2ra function instantly
} 
while (cm<30); // check the condition if true repeat the loop if not get out
do 
{ 
puse(); 
} 
while(cm>30);
}
 else if(cm>10){
  Serial.print("line following activated");
x:
  set(); // call function set
if     (hoba==1) {ymen();}        
else if(hoba==2) {f3();}
else if(hoba==3) {ymen();}
else if(hoba==6) {f3();}
else if(hoba==4) {n=0; f1();}
else if(hoba==12){f2();} 
else if(hoba==24){shmal();}
else if(hoba==8) {f2();}
else if(hoba==16){shmal();}
else if(hoba==7) {ymen();}
else if(hoba==28){shmal();}
else if(hoba==31){

while(hoba==31||hoba==7||hoba==15||hoba==28||hoba==30){  set();f1();}

while(digitalRead(e)==1){ymen();}
while(digitalRead(e)!=1){ymen();}
while(digitalRead(c)!=1){ymen();}
while(digitalRead(c)==1){goto x;}
}// for every condition of the past conditions  call a pre-defined function
 
}

}

else if(j=='m'||j=='M')

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

motor1.setSpeed(s);
motor1.run(FORWARD);
motor2.setSpeed(s);
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

motor1.setSpeed(s);
motor1.run(BACKWARD);
motor2.setSpeed(s);
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
motor2.setSpeed(s);
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

motor1.setSpeed(s);
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

motor1.setSpeed(s);
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
motor2.setSpeed(s);
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


