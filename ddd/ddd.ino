#include <LiquidCrystal.h>
#include<AFMotor.h>

LiquidCrystal lcd(13, 11, A0, A1, A2, A3);
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
#define buzzer 3
#define HL 10
#define BL 9
#define RL 4
#define LS 6
#define RS A4
#define PL A5
#define trigPin 7
#define echoPin 8
float pingTime;
float targetDistance;

int i;
char j;

void setup() {
Serial.begin(9600);
lcd.begin(16,2);
lcd.setCursor(1,0);
lcd.print("WAITING_FOR_A");
lcd.setCursor(4,1);
lcd.print("DEVICE....!!");
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(3,buzzer);
pinMode(10,HL);
pinMode(9,BL);
pinMode(4,RL);
pinMode(6,LS);
pinMode(A4,RS);
pinMode(A5,PL);


while(!Serial.available());
lcd.clear();
lcd.setCursor(4,0);
lcd.print("CONNECTED!");
delay(3000);
j=Serial.read();
}

void loop(){

if(j=='m'||j=='M')

{
manual();
}

while(!Serial.available());
j=Serial.read();

}
void manual()
{
  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("MANUAL_CONTROL");
delay(3000);
  
if(Serial.available() > 0){ 
    j = Serial.read(); 
    Breaklight(); 
    switch(j){
    case 'F':  
      break;
      forward();
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'N':
      backleft();
      break;
    case 'P':
      backright();
      break;
    case 'H':
      horn();
      break;
    case'Q':
      headlight();
      break;
    case'W':
      Breaklight();
      break;
    case'E':
      roundmove();
      break;
    case'h':
      hazard();
      break;
    case'T':
      systemcheck();
      break;
    case'D':
      dance();
      break;
    case'Y':
      bpmode();
      break;
    case'p':
      parking();
      break;
    }
  } 
}

void forward()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
}

void back()
{
motor1.setSpeed(255); 
motor1.run(BACKWARD); 
motor2.setSpeed(255); 
motor2.run(BACKWARD);
digitalWrite(RL,HIGH);
}

void left()
{

motor1.setSpeed(255); 
motor1.run(FORWARD); 
motor2.setSpeed(0);
motor2.run(RELEASE);
digitalWrite(LS,HIGH);
delay(800);
digitalWrite(LS,LOW);
delay(800);
}

void right()
{

motor1.setSpeed(0);
motor1.run(RELEASE); 
motor2.setSpeed(255); 
motor2.run(FORWARD);
digitalWrite(RS,HIGH);
delay(800);
digitalWrite(RS,LOW);
delay(800);
}
void backleft()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
}
void backright()
{
 motor1.setSpeed(255);
 motor1.run(BACKWARD);
 motor2.setSpeed(0);
 motor2.run(RELEASE);
}
void horn()
{
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(200);
}
void headlight()
{
  digitalWrite(HL,HIGH);
}
void parking()
{
  digitalWrite(PL,HIGH);
}
void Breaklight()
{

  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  digitalWrite(BL,HIGH);
}
void roundmove()
{
  motor1.setSpeed(205);
  motor1.run(FORWARD);
  motor2.setSpeed(205);
  motor2.run(BACKWARD);
}
void hazard()
{

  digitalWrite(LS,HIGH);
  digitalWrite(RS,HIGH);
  delay(800);
  digitalWrite(LS,LOW);
  digitalWrite(RS,LOW);
  delay(800);
}
void systemcheck()
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
}
void dance()
{
 motor1.setSpeed(155);
 motor1.run(FORWARD);
 motor2.setSpeed(55);
 motor2.run(BACKWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(HL,HIGH);
 delay(500);
 motor1.setSpeed(155);
 motor1.run(FORWARD);
 motor2.setSpeed(55);
 motor2.run(BACKWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(PL,HIGH);
 delay(500);
 motor1.setSpeed(55);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(HL,HIGH);
 delay(500);
 motor1.setSpeed(55);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(PL,HIGH);
 delay(500);
 motor1.setSpeed(255);
 motor1.run(FORWARD);
 motor2.setSpeed(255);
 motor2.run(BACKWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(HL,HIGH);
 delay(1000);
 motor1.setSpeed(55);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(PL,HIGH);
 delay(500);
 motor1.setSpeed(55);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(HL,HIGH);
 delay(500);
 motor1.setSpeed(255);
 motor1.run(BACKWARD);
 motor2.setSpeed(255);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(PL,HIGH);
 delay(1000);
 motor1.setSpeed(155);
 motor1.run(BACKWARD);
 motor2.setSpeed(155);
 motor2.run(BACKWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(HL,HIGH);
 delay(500);
 motor1.setSpeed(155);
 motor1.run(FORWARD);
 motor2.setSpeed(155);
 motor2.run(FORWARD);
 digitalWrite(buzzer,HIGH);
 digitalWrite(PL,HIGH);
 delay(500);
}
void bpmode()
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
 digitalWrite(LS,HIGH);
 digitalWrite(RS,HIGH);
 delay(800);
 digitalWrite(LS,LOW);
 digitalWrite(RS,LOW);
 delay(800);
}






/*void automatic()

{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("AUTO_CONTROL");

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
lcd.setCursor(0,1);
lcd.print(targetDistance);
lcd.print( " CM!");

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
  digitalWrite(LS,HIGH);
  delay(800);
  digitalWrite(LS,LOW);
  delay(800);
  Serial.println("LEFT TURN");
  
 }

 }
int com=Serial.read();

if(com=='e'||com=='E')

{

  lcd.clear();
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  lcd.setCursor(1,0);
  lcd.print("WAITING_FOR_A");
  lcd.setCursor(4,1);
  lcd.print("COMMAND..!!");
  Serial.println("STOPPED");

}
}
*/
