#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int pos = 0;    

int k=90;

void setup() {
  Serial.begin(9600);
  myservo.attach(6);  
  myservo2.attach(5);
  myservo.write(k);
}

void loop() {

  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo2.write(pos);              
    delay(100);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo2.write(pos);              
    delay(100);                       
  }
  
k=k+1;
myservo.write(k);
Serial.println(k);

}

