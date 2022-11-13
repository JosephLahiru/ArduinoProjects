#include <Servo.h>

int trigPin_l = 3;
int echoPin_l = 4;
float pingTime_l;
float cm_l = 0;
int trigPin_r = 5;
int echoPin_r = 6;
float pingTime_r;
float cm_r = 0;
int pos;

Servo myservo;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin_l, OUTPUT);
  pinMode(trigPin_r, OUTPUT);
  myservo.attach(9);
}

void ultrasonic_test()
{
  digitalWrite(trigPin_l, LOW);
  digitalWrite(trigPin_r, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_l, HIGH);
  digitalWrite(trigPin_r, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_r, LOW);
  digitalWrite(trigPin_l, LOW);
  pingTime_l = pulseIn(echoPin_l, HIGH);
  pingTime_r = pulseIn(echoPin_r, HIGH);
  pingTime_l = pingTime_l / 29;
  pingTime_r = pingTime_r / 29;
  cm_l = pingTime_l / 2;
  cm_r = pingTime_r / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(" cm_l : ");
  Serial.print(cm_l);
  Serial.print(" cm_r : ");
  Serial.println(cm_r);
  delay(10);
}

void loop()
{
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);
    ultrasonic_test();                                 
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);
    ultrasonic_test();                         
  }
}
