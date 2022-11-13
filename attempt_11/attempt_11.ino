#include <Servo.h>

Servo myservo;
int k=0;
int num;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  myservo.attach(6);
}

void loop() {

  if (Serial.available()) {
    num = Serial.read();
    if (num == 1) {
      Serial.println(k);
      myservo.write(k);
      k=k+1;
      if(k==180){
        k=0;
      }
    }

  }
  delay(100);
}

