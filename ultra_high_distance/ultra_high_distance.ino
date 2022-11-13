#include <Servo.h>

int trigPin = 42;
int echoPin = 43;
float pingTime;
float cm;

int enL = 6;
int enR = 5;

int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

Servo servo;
int pos;

int highDist = 0;
int highAng = 0;

void setup() {
  Serial.begin(9600);

}

void ultra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH);
  pingTime = pingTime / 29;
  cm = pingTime / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(10);
}

void loop() {

  for (pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    ultra();
    if (cm > highDist) {
      highDist = cm;
      highAng = pos;
    }
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    ultra();
    if (cm > highDist) {
      highDist = cm;
      highAng = pos;
    }
  }
  Serial.print(highAng);
  Serial.print("-");
  Serial.println(highDist);
}
