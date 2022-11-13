#include <Servo.h>
int k;
Servo myservo; 

void setup() {
  Serial.begin(9600);
  myservo.attach(D4);  
}

void loop() {
  k = Serial.read();
  k=int(k);
  l=map(k,0,255,255,0);
  myservo.write(l); 
}
