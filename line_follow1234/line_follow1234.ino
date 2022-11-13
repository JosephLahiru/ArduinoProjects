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
  LCD.begin(16,2);
  LCD_start();
}

void LCD_start()

{
LCD.setCursor(0,0);
LCD.print("* WELCOME SIR *");
delay(1000);
LCD.clear();
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
//delay(1);
  }
   if((digitalRead(a)==q)&&(digitalRead(b)==w)&&(digitalRead(c)==w)&&(digitalRead(d)==w)&&(digitalRead(e)==q))

  {
motor1.setSpeed(65);
motor1.run(FORWARD);
motor2.setSpeed(65);
motor2.run(FORWARD);
motor3.setSpeed(65);
motor3.run(FORWARD);
motor4.setSpeed(65);
motor4.run(FORWARD);
//delay(1);
  }
    else if((digitalRead(a)==q)&&(digitalRead(b)==w)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==q))
  {
motor1.setSpeed(100);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(BACKWARD);
motor3.setSpeed(100);
motor3.run(FORWARD);
motor4.setSpeed(0);
motor4.run(BACKWARD);
//delay(10);
  }
    else if((digitalRead(a)==w)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==q))
  {
motor1.setSpeed(120);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(BACKWARD);
motor3.setSpeed(120);
motor3.run(FORWARD);
motor4.setSpeed(0);
motor4.run(BACKWARD);
//delay(10);
  }
    else if((digitalRead(a)==w)&&(digitalRead(b)==w)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==q))
  {
motor1.setSpeed(120);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(BACKWARD);
motor3.setSpeed(120);
motor3.run(FORWARD);
motor4.setSpeed(0);
motor4.run(BACKWARD);
//delay(10);
  }
    else if((digitalRead(a)==q)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==w)&&(digitalRead(e)==q))
  {
motor1.setSpeed(0);
motor1.run(BACKWARD);
motor2.setSpeed(100);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(100);
motor4.run(FORWARD);
//delay(10);  
  }
    else if((digitalRead(a)==q)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==q)&&(digitalRead(e)==w))
  {
motor1.setSpeed(0);
motor1.run(BACKWARD);
motor2.setSpeed(120);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(120);
motor4.run(FORWARD);
//delay(10);
  }
    else if((digitalRead(a)==q)&&(digitalRead(b)==q)&&(digitalRead(c)==q)&&(digitalRead(d)==w)&&(digitalRead(e)==w))
  {
motor1.setSpeed(0);
motor1.run(BACKWARD);
motor2.setSpeed(130);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(130);
motor4.run(FORWARD);
//delay(10);
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
delay(1);
digitalWrite(buzzer,LOW);
 }
   else if((digitalRead(a)==w)&&(digitalRead(b)==w)&&(digitalRead(c)==w)&&(digitalRead(d)==w)&&(digitalRead(e)==w))
 {
motor1.setSpeed(0);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(FORWARD);
motor4.setSpeed(0);
motor4.run(FORWARD);
digitalWrite(22,HIGH);
delay(1);
digitalWrite(22,LOW);
LCD.setCursor(1,1);
LCD.print("ALL BLACK");
LCD.clear();
 }

}

void loop(){
  
line_follow();

}
