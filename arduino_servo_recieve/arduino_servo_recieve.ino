#include <Servo.h>

Servo myservo; 

int num; 

void setup() {
  Serial.begin(9600);
  Serial.println("Ready"); 
  myservo.attach(6); 
}

void loop() {
  
  if (Serial.available()) { 
    num = Serial.read(); 
    Serial.println(num); 
    myservo.write(num);

  }
  delay(100); 
}

