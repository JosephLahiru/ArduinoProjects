#include<AFMotor.h>
#include <Servo.h> 

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo servo ; 


int a=2,b=3,c=4,d=5,e=6;
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
int co=1;

void setup(){
pinMode(trigPin, OUTPUT);
pinMode(a, INPUT);
pinMode(b, INPUT);
pinMode(c, INPUT);
pinMode(d, INPUT);
pinMode(e, INPUT);
Serial.begin(4800); 
servo.write(90); 
servo.attach(9); 
f1();

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
void f1(){
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


void fc(){
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
void f3(){ 
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
void f4(){
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
void f9(){
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


void f5(){  
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
 
void f6(){
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE);
//digitalWrite(BL,HIGH);
Serial.println("BREAK");
}

void ymen(){
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

void shmal(){
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

void backward(){
motor1.setSpeed(s);
motor1.run(BACKWARD);
motor2.setSpeed(s);
motor2.run(BACKWARD);
motor3.setSpeed(p);
motor3.run(BACKWARD);
motor4.setSpeed(p);
motor4.run(BACKWARD);
//digitalWrite(RL,HIGH);
Serial.println("BACKWARD");
}
 void set () {
 if(digitalRead(a)== co){x=16;}else{x=0;} 
 if(digitalRead(b)== co){ y=8;}else{y=0;}
 if(digitalRead(c)== co){ z=4;}else{z=0;}
 if(digitalRead(d)== co){ l=2;}else{l=0;}
 if(digitalRead(e)== co){ m=1;}else{m=0;}
 hoba =x+y+z+l+m;
           
 }
void e2ra () {

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


void loop(){ 
  e2ra();
    
 e2ra();
 if (cm<=4) {      
   servo.write(95);
do {
  
  backward(); 
  e2ra();        
  
} while (cm<=15);  // check the condition if true repeat the loop if not get out
e2ra(); // do e2ra function
servo.write(85);
do { f4(); // do f4 function instantly
e2ra(); // do e2ra function
servo.write(80);

 } while (cm<=25); // check the condition if true repeat the loop if not get out
do {
  f1(); // do f1 function instantly 
e2ra(); // do e2ra function instantly
servo.write(15); // change the servo to 180 degree angle.
 
 } while(cm>=20); // check the condition if true repeat the loop if not get out 
 
 f6(); // do e2ra function
 delay(100); // wait for 100 millisec.
 do {
   f1(); // do f1 function instantly
   e2ra(); // do e2ra function instantly
 } while(cm<30); // check the condition if true repeat the loop if not get out
 
 do {
   f5(); // do f5 function instantly
   e2ra(); // do e2ra function instantly
 } while (cm>25); // check the condition if true repeat the loop if not get out
 
 do {
   f1 (); // do f1 function instantly
   e2ra(); // do e2ra function instantly
 } while (cm<30); // check the condition if true repeat the loop if not get out
 
do { f6(); } while(cm>30);

 }
 


  
  else if(cm>10){
x:
  set(); 
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

while(digitalRead(e)==co){ymen();}
while(digitalRead(e)!=co){ymen();}
while(digitalRead(c)!=co){ymen();}
while(digitalRead(c)==co){goto x;}
}
 


}
}
