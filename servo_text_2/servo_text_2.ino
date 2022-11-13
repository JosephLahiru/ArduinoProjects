/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo; 
Servo myservo1;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);
  myservo1.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
myservo.write(50);
myservo1.write(40); //o up-110 down  40-middle
}

