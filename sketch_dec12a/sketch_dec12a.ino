#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);
  Serial.println("Ready"); 
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  char inByte = ' ';
  if (Serial.available()) { // only send data back if data has been sent
    char inByte = Serial.read(); // read the incoming data
    Serial.println(inByte); // send the data back in a new line so that it is not all one long line
    myservo.write(inByte);
    //Serial.println("Servo");

  }
  delay(100); // delay for 1/10 of a second
}

