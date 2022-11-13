#include <Servo.h>

Servo Xservo;
Servo Yservo;

int num;
int x = 90;
int y = 90;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  Xservo.attach(6);
  Yservo.attach(5);
  Xservo.write(x);
  Yservo.write(y);
}

void loop() {

  if (Serial.available()) {
    num = Serial.read();
    Serial.println(num);
    
    if (num == 1) {
      Xservo.write(x);
      Serial.println("Arduino : Left");
      x=x+1;
    }
    else if (num == 2) {
      Xservo.write(x);
      Serial.println("Arduino : Right");
      x=x-1;
    }
    else if (num == 3) {
      Yservo.write(y);
      Serial.println("Arduino : Down");
      y=y+1;
    }
    else if (num == 4) {
      Yservo.write(y);
      Serial.println("Arduino : Up");
      y=y-1;
    }
  }
  delay(10);
}
