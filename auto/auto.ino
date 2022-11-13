#include<AFMotor.h>
#include <Servo.h> 

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo servo ; 

int a=37,b=38,c=39,d=40,e=41;
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
pinMode(trigPin, OUTPUT);
servo.write(90); 
servo.attach(9);

}

void loop() {

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

if     (hoba==1) 

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

else if(cm<=21){goto e;}
     
else if(hoba==2) 

{
  
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

else if(hoba==3) 

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

else if(cm<=21){goto e;}

else if(hoba==6) 

{
  
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

else if(hoba==4) 

{
  
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

else if(hoba==12)

{
  
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

else if(hoba==24)

{
  
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

else if(hoba==8) 

{
  
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

else if(hoba==16)

{
  
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

else if(hoba==7)

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

else if(cm<=21){goto e;}

else if(hoba==28)

{
  
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
Serial.println("STOPPED");

}

else goto g;

}



