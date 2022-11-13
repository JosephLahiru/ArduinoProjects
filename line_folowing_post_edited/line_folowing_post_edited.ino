#include<AFMotor.h>
#include <LiquidCrystal.h>

int a=31;
int b=32;
int c=33;
int d=34;
int e=35;
int buzzer=A8;
int trigPin_f=A10;
int echoPin_f=A11;
float pingTime_f;
float cm_f=0;
int trigPin_l=A12;
int echoPin_l=A13;
float pingTime_l;
float cm_l=0;
int trigPin_r=A15;
int echoPin_r=A14;
float pingTime_r;
float cm_r=0;
int i;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
LiquidCrystal LCD(45, 44, 43, 42, 41, 40);

void setup(){
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(a,INPUT);
  pinMode(b,INPUT);
  pinMode(c,INPUT);
  pinMode(d,INPUT);
  pinMode(e,INPUT);
  pinMode(trigPin_f, OUTPUT);
  pinMode(trigPin_l, OUTPUT);
  pinMode(trigPin_r, OUTPUT);
  LCD.begin(16,2);
  LCD_start();
}

void ultrasonic_test(){

digitalWrite(trigPin_f, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_f, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_f, LOW);
pingTime_f = pulseIn(echoPin_f, HIGH);
pingTime_f=pingTime_f/29;
cm_f=pingTime_f/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm_f);
Serial.println(" cm_f");
delay(10);

digitalWrite(trigPin_l, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_l, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_l, LOW);
pingTime_l = pulseIn(echoPin_l, HIGH);
pingTime_l=pingTime_l/29;
cm_l=pingTime_l/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm_l);
Serial.println(" cm_l");
delay(10);

digitalWrite(trigPin_r, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_r, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_r, LOW);
pingTime_r = pulseIn(echoPin_r, HIGH);
pingTime_r=pingTime_r/29;
cm_r=pingTime_r/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm_r);
Serial.println(" cm_r");
delay(10);
  
}

void ultrasonic(){

if(cm_f>10){
motor1.setSpeed(170);
motor1.run(FORWARD);
motor2.setSpeed(170);
motor2.run(FORWARD);
motor3.setSpeed(170);
motor3.run(FORWARD);
motor4.setSpeed(170);
motor4.run(FORWARD);
Serial.println("FORWARD");
delay(10);  
}
while(cm_f<10){
  if(cm_l>15){
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(170);
motor2.run(FORWARD);
motor3.setSpeed(170);
motor3.run(BACKWARD);
motor4.setSpeed(0);
motor4.run(RELEASE);
Serial.println("LEFT TURN");
delay(10);
    }
  else if(cm_r>15){
motor1.setSpeed(170);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(170);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");
delay(10);    
  }
 }
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

void loop(){
  
if((digitalRead(a)==1)&&(digitalRead(b)==1)&&(digitalRead(c)==0)&&(digitalRead(d)==1)&&(digitalRead(e)==1))

  {
motor1.setSpeed(170);
motor1.run(FORWARD);
motor2.setSpeed(170);
motor2.run(FORWARD);
motor3.setSpeed(170);
motor3.run(FORWARD);
motor4.setSpeed(170);
motor4.run(FORWARD);
Serial.println("FORWARD");
delay(10);
  }
    else if((digitalRead(a)==1)&&(digitalRead(b)==0)&&(digitalRead(c)==1)&&(digitalRead(d)==1)&&(digitalRead(e)==1))
  {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(70);
motor2.run(FORWARD);
motor3.setSpeed(70);
motor3.run(BACKWARD);
motor4.setSpeed(0);
motor4.run(RELEASE);
Serial.println("LEFT TURN");
delay(10);
  }
    else if((digitalRead(a)==0)&&(digitalRead(b)==1)&&(digitalRead(c)==1)&&(digitalRead(d)==1)&&(digitalRead(e)==1))
  {
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(100);
motor2.run(FORWARD);
motor3.setSpeed(100);
motor3.run(BACKWARD);
motor4.setSpeed(0);
motor4.run(RELEASE);
Serial.println("LEFT TURN");
delay(10);
  }
    else if((digitalRead(a)==1)&&(digitalRead(b)==1)&&(digitalRead(c)==1)&&(digitalRead(d)==0)&&(digitalRead(e)==1))
  {
motor1.setSpeed(70);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(70);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");
delay(10);
  
  }
    else if((digitalRead(a)==1)&&(digitalRead(b)==1)&&(digitalRead(c)==1)&&(digitalRead(d)==1)&&(digitalRead(e)==0))
  {
motor1.setSpeed(100);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(100);
motor4.run(BACKWARD);
Serial.println("RIGHT TURN");
delay(10);
  }
     else if((digitalRead(a)==0)&&(digitalRead(b)==0)&&(digitalRead(c)==1)&&(digitalRead(d)==1)&&(digitalRead(e)==1))
  {
motor1.setSpeed(0);
motor1.run(FORWARD);
motor2.setSpeed(170);
motor2.run(RELEASE);
motor3.setSpeed(170);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(BACKWARD);
Serial.println("CUBE:LEFT TURN");
delay(10);
  } 
     else if((digitalRead(a)==0)&&(digitalRead(b)==0)&&(digitalRead(c)==1)&&(digitalRead(d)==1)&&(digitalRead(e)==1))
  {
motor1.setSpeed(170);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(170);
motor4.run(BACKWARD);
Serial.println("CUBE:RIGHT TURN");
delay(10);
  }
    else if((digitalRead(a)==0)&&(digitalRead(b)==1)&&(digitalRead(c)==1)&&(digitalRead(d)==1)&&(digitalRead(e)==0))
  {
motor1.setSpeed(70);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(70);
motor4.run(BACKWARD);
Serial.println("string:RIGHT TURN");
delay(10);
  }
    else if((digitalRead(a)==1)&&(digitalRead(b)==1)&&(digitalRead(c)==1)&&(digitalRead(d)==1)&&(digitalRead(e)==1))
  {
motor1.setSpeed(0);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(BACKWARD);
digitalWrite(buzzer,HIGH);
Serial.println("ALL WHITE");
delay(10);
 }
   while((digitalRead(a)==0)&&(digitalRead(b)==0)&&(digitalRead(c)==0)&&(digitalRead(d)==0)&&(digitalRead(e)==0))
 {
ultrasonic_test();
ultrasonic();
 }

}
