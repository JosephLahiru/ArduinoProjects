#include<AFMotor.h>
#include <LiquidCrystal.h>

int a=31;
int b=32;
int c=33;
int d=34;
int e=35;
int buzzer=50;
int q=0;
int w=1;
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
char x=0;
int p=170;
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
  while(!Serial.available());
  x=Serial.read();
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

void forward()
{
motor1.setSpeed(p);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor4.setSpeed(200);
motor4.run(FORWARD);
Serial.println("FORWARD");
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
motor4.setSpeed(200);
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
motor4.setSpeed(200);
motor4.run(FORWARD);
}
void forwardleft()
{
motor1.setSpeed(50);
motor1.run(FORWARD);
motor2.setSpeed(p);
motor2.run(FORWARD);
motor3.setSpeed(50);
motor3.run(FORWARD);
motor4.setSpeed(p);
motor4.run(FORWARD);
}
void backwardleft()
{
motor1.setSpeed(p);
motor1.run(BACKWARD);
motor2.setSpeed(50);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(50);
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
motor2.setSpeed(50);
motor2.run(FORWARD);
motor3.setSpeed(p);
motor3.run(FORWARD);
motor4.setSpeed(50);
motor4.run(FORWARD);
}
void backwardright()
{
motor1.setSpeed(50);
motor1.run(BACKWARD);
motor2.setSpeed(p);
motor2.run(BACKWARD);
motor3.setSpeed(50);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(BACKWARD);
}

void BT()
{ 
while(1)
{
  
if(Serial.available()>0)
{
x=Serial.read();
}
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
else if(cm_f<10){
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

void line_follow(){

   if((digitalRead(a)==q)&&(digitalRead(b)==q)&&(digitalRead(c)==w)&&(digitalRead(d)==q)&&(digitalRead(e)==q))

  {
motor1.setSpeed(60);
motor1.run(FORWARD);
motor2.setSpeed(60);
motor2.run(FORWARD);
motor3.setSpeed(60);
motor3.run(FORWARD);
motor4.setSpeed(60);
motor4.run(FORWARD);
delay(1);
  }
    else if((digitalRead(a)==q)&&(digitalRead(b)==w)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==q))
  {
motor1.setSpeed(100);
motor1.run(FORWARD);
motor2.setSpeed(5);
motor2.run(FORWARD);
motor3.setSpeed(100);
motor3.run(FORWARD);
motor4.setSpeed(5);
motor4.run(FORWARD);
delay(1);
  }
    else if((digitalRead(a)==w)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==q))
  {
motor1.setSpeed(150);
motor1.run(FORWARD);
motor2.setSpeed(5);
motor2.run(FORWARD);
motor3.setSpeed(150);
motor3.run(FORWARD);
motor4.setSpeed(5);
motor4.run(FORWARD);
delay(1);
  }
    else if((digitalRead(a)==q)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==w)&&(digitalRead(e)==q))
  {
motor1.setSpeed(5);
motor1.run(FORWARD);
motor2.setSpeed(100);
motor2.run(FORWARD);
motor3.setSpeed(5);
motor3.run(FORWARD);
motor4.setSpeed(100);
motor4.run(FORWARD);
delay(1);  
  }
    else if((digitalRead(a)==q)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==w))
  {
motor1.setSpeed(5);
motor1.run(FORWARD);
motor2.setSpeed(150);
motor2.run(FORWARD);
motor3.setSpeed(5);
motor3.run(FORWARD);
motor4.setSpeed(150);
motor4.run(FORWARD);
delay(1);
  }
    /* else if((digitalRead(a)==w)&&(digitalRead(b)==w)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==q))
  {
motor1.setSpeed(0);
motor1.run(FORWARD);
motor2.setSpeed(130);
motor2.run(RELEASE);
motor3.setSpeed(130);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(BACKWARD);
Serial.println("CUBE:LEFT TURN");
delay(10);
  } 
     else if((digitalRead(a)==q)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==w)&&(digitalRead(e)==w))
  {
motor1.setSpeed(130);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(130);
motor4.run(BACKWARD);
Serial.println("CUBE:RIGHT TURN");
delay(10);
  }
    else if((digitalRead(a)==w)&&(digitalRead(b)==q)&&(digitalRead(c)==0)&&(digitalRead(d)==q)&&(digitalRead(e)==0))
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
  }*/
    else if((digitalRead(a)==q)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==q))
  {
motor1.setSpeed(0);
motor1.run(BACKWARD);
motor2.setSpeed(0);
motor2.run(BACKWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(0);
motor4.run(BACKWARD);
digitalWrite(buzzer,HIGH);
Serial.println("ALL WHITE");
LCD.setCursor(1,1);
LCD.print("ALL WHITE");
LCD.clear();
delay(10);
digitalWrite(buzzer,LOW);
 }
   while((digitalRead(a)==w)&&(digitalRead(b)==w)&&(digitalRead(c)==w)&&(digitalRead(d)==w)&&(digitalRead(e)==w))
 {
ultrasonic();
 }

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

void MM() {
  
while(!Serial.available());
x=Serial.read(); 
if(x=='1'){
  LCD.clear();
}
else{
LCD.print(x);
delay(100);
}
}

void loop(){
   
   if(x=='a'||x=='A')
{
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
h:
//ultrasonic_test();
line_follow();
goto h;
}

else if(x=='m'||x=='M')
{
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
BT();
}

else if(x=='e'||x=='E')
l:
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
else if(x=='c'||x=='C')
{
LCD.clear();
for(i=0;i<2;i++)
{
LCD.setCursor(0,i);
LCD.print(" ");
}
char displayitem5[]={'M','O','B','I','L','E'};
char displayitem6[]={'C','O','N','N','E','C','T','E','D'};
for(i=0;i<6;i++)
{
LCD.setCursor(i,0);
LCD.print(displayitem5[i]);
LCD.print("_");
delay(50);
}
for(i=0;i<9;i++)
{
LCD.setCursor(i,1);
LCD.print(displayitem6[i]);
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
}

//else if(x=='T')
//{
//MM();
//}
while(!Serial.available());
x=Serial.read();
}

