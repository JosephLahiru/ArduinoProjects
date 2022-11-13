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

int a;
int b;

Servo myservo;
int pos;
int x = 0;
bool Dtook;
int buzzer = A0;
int rando;

void setup()
{
  Serial.begin(9600);
  Serial.println("started");
  pinMode(trigPin_f, OUTPUT);
  pinMode(trigPin_b, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
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
  analogWrite(enR, a);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, b);
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
  analogWrite(enR, a);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, b);
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
  if (cm_f < 50 || cm_b < 50) {

    Serial.println("alert");

    if (cm_f < 50)
    {
      if (pos > 0 && pos < 22)
      {
        a = 100;
        b = 50;
        forwardright();
      }
      else if (pos > 22 && pos < 45)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 45 && pos < 67)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 67 && pos < 90)
      {
        a = 0;
        b = 0;
        forwardright ();
      }
      else if (pos > 90 && pos < 112)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 112 && pos < 135)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 135 && pos < 157)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 157 && pos < 180)
      {
        a = 50;
        b = 100;
        forwardleft();
      }
    }

    else if (cm_f < 40)

    {
      if (pos > 0 && pos < 22)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 22 && pos < 45)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 45 && pos < 67)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 67 && pos < 90)
      {
        a = 0;
        b = 0;
        forwardright ();
      }
      else if (pos > 90 && pos < 112)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 112 && pos < 135)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 135 && pos < 157)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 157 && pos < 180)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
    }

    else if (cm_f < 30)

    {
      if (pos > 0 && pos < 22)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 22 && pos < 45)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 45 && pos < 67)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 67 && pos < 90)
      {
        a = 0;
        b = 0;
        forwardright ();
      }
      else if (pos > 90 && pos < 112)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 112 && pos < 135)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 135 && pos < 157)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 157 && pos < 180)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
    }

    else if (cm_f < 20)
    {

      if (pos > 0 && pos < 22)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 22 && pos < 45)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 45 && pos < 67)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 67 && pos < 90)
      {
        a = 0;
        b = 0;
        forwardright ();
      }
      else if (pos > 90 && pos < 112)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 112 && pos < 135)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 135 && pos < 157)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 157 && pos < 180)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
    }


    else if (cm_f < 10)
    {
      if (pos > 0 && pos < 22)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 22 && pos < 45)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 45 && pos < 67)
      {
        a = 0;
        b = 0;
        forwardright();
      }
      else if (pos > 67 && pos < 90)
      {
        a = 0;
        b = 0;
        forwardright ();
      }
      else if (pos > 90 && pos < 112)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 112 && pos < 135)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 135 && pos < 157)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
      else if (pos > 157 && pos < 180)
      {
        a = 0;
        b = 0;
        forwardleft();
      }
    }
  }
}
void loop()
{
  forward();
  delay(1000);
  none();
  delay(500);
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
