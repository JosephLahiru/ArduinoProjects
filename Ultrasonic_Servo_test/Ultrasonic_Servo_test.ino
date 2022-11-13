/*Debugging*/

#include <Servo.h>

int trigPin_f = 3;
int echoPin_f = 4;
float pingTime_f;
float cm_f = 0;
int trigPin_b = 13;
int echoPin_b = 12;
float pingTime_b;
float cm_b = 0;



Servo myservo;
int pos;

void setup()
{
  Serial.begin(9600);
  Serial.println("started");
  pinMode(trigPin_f, OUTPUT);
  pinMode(trigPin_b, OUTPUT);
  myservo.attach(11);
  myservo.write(90);
  Serial.println("Servo 90");
  delay(5000);
}



void ultrasonic_test_front()
{
  digitalWrite(trigPin_f, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_f, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_f, LOW);
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


void loop()
{
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(10);
    ultrasonic_test_front();
    ultrasonic_test_back();
    Serial.print("Angle : ");
    Serial.print(pos);
    Serial.print(" : cm_f...");
    Serial.print(cm_f);
    Serial.print("cm_b...");
    Serial.println(cm_b);
    if (cm_f < 10) {
      Serial.println(pos);
      delay(1000);
    }
    else if (cm_b < 10) {
      Serial.println(pos);
      delay(1000);
    }
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(10);
    ultrasonic_test_front();
    ultrasonic_test_back();
    Serial.print("Angle : ");
    Serial.print(pos);
    Serial.print(" : cm_f...");
    Serial.print(cm_f);
    Serial.print("...cm_b...");
    Serial.println(cm_b);
    if (cm_f < 10) {
      Serial.println(pos);
      delay(1000);
    }
    else if (cm_b < 10) {
      Serial.println(pos);
      delay(1000);
    }
  }
}
