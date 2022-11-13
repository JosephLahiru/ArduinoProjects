/*Coded by AMRES*/

#include <Servo.h>

int trigPin_f = 3;
int echoPin_f = 4;
float pingTime_f;
float cm_f = 0;
int trigPin_b = 13;
int echoPin_b = 12;
float pingTime_b;
float cm_b = 0;

int enL = 6;
int enR = 5;

int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

Servo myservo;
int pos;
int x = 0;
bool Dtook;
int buzzer = A0;
int rando;

void setup()
{
  Serial.begin(9600);
  Serial.println("started")
  pinMode(trigPin_f, OUTPUT);
  pinMode(trigPin_b, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(enL,OUTPUT);
  pinMode(enR,OUTPUT);
  pinMode(inR1,OUTPUT);
  pinMode(inR2,OUTPUT);
  pinMode(inL1,OUTPUT);
  pinMode(inL2,OUTPUT);
  myservo.attach(11);
  myservo.write(90);
  delay(5000);
}

void forward()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
}
void forward_slow()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 125);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 125);
}
void none()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 0);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 0);
}
void reverse()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);
}
void left()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 125);
}
void forwardleft()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 125);
}
void backwardleft()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 125);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);
}
void right()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 125);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
}
void forwardright()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 125);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
}
void backwardright()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 125);
}
void horn()
{
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(50);
}
void em_break()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);
}

void ultrasonic_test_front()
{
  digitalWrite(trigPin_f, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_f, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_b, LOW);
  pingTime_f = pulseIn(echoPin_f, HIGH);
  pingTime_f = pingTime_f / 29;
  cm_f = pingTime_f / 2;
  delay(10);
}

void ultrasonic_test_back()
{
  digitalWrite(trigPin_b, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_b, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_b, LOW);
  pingTime_b = pulseIn(echoPin_b, HIGH);
  pingTime_b = pingTime_b / 29;
  cm_b = pingTime_b / 2;
  delay(10);
}

void action() {
  if (cm_f < 10 || cm_b < 10) {

    Serial.println("alert");

    if (cm_f < 10) {

      if (pos > 45 && pos < 135)
      {
        Dtook = false;
        Serial.println("alert : Object detected in front");
        while (Dtook == false) {
          for (pos = 0; pos <= 180; pos += 1) {
            myservo.write(pos);
            ultrasonic_test_front();
          }
          for (pos = 180; pos >= 0; pos -= 1) {
            myservo.write(pos);
            ultrasonic_test_front();
          }
          if (cm_f < 10 || cm_b < 10) {
            if (pos >= 0 && pos <= 45) {
              Serial.println("object detected in frontleft turning right");
              forwardright();
              Dtook = true;
            }
            else if (pos >= 135 && pos <= 180) {
              Serial.println("object detected in frontright turning left");
              forwardleft();
              Dtook = true;
            }
            else {
              Serial.println("nothing detected in frontleft or frontright going random and choosing direction");
              myservo.write(90);
              ultrasonic_test_back();
              reverse();
              delay(cm_b);
              rando = random(2);
              if (rando == 0) {
                backwardleft();
                delay(1000);
              }
              else if (rando == 1) {
                backwardright();
                delay(1000);
              }
              Dtook = true;
            }
          }
        }
      }
      else if (pos >= 0 && pos <= 45)
      {
        Serial.println("alert : Object detected in frontleft turning right");
        forwardright();
      }
      else if (pos >= 135 && pos <= 180)
      {
        Serial.println("alert : Object detected in frontright turning left");
        forwardleft();
      }
    }

    else if (cm_b < 10) {

      if (pos > 45 && pos < 135)
      {
        Serial.println("alert : Object detected in back");
        forward();
        delay(1000);
      }
      else if (pos >= 0 && pos <= 45)
      {
        Serial.println("alert : Object detected in backright");
      }
      else if (pos >= 135 && pos <= 180)
      {
        Serial.println("alert : Object detected in backleft");
      }
    }
    else {
      forward_slow();
    }
  }
}

void loop()
{
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(10);
    ultrasonic_test_front();
    Serial.print("cm_f...");
    Serial.print(cm_f);
    Serial.print("cm_b...");
    Serial.println(cm_b);
    action();
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(10);
    ultrasonic_test_front();
    Serial.print("cm_f...");
    Serial.print(cm_f);
    Serial.print("...cm_b...");
    Serial.println(cm_b);
    action();
  }
}
