
#include <Servo.h>

Servo myservo;

int pos = 0;  

void setup() {
  myservo.attach(9); 
}

void loop() {
 myservo.write(pos);             
  }



