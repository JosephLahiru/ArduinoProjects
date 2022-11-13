#include <AFMotor.h>

AF_DCMotor leftmotors(2, MOTOR12_64KHZ);

AF_DCMotor rightmotors(1, MOTOR12_64KHZ);

AF_DCMotor armmotor(4, MOTOR34_64KHZ);

#define trigPin 12 // define the pins of the distance sensor

#define echoPin 13

void setup() {

leftmotors.setSpeed(255); // set the speed to full speed 255/255

rightmotors.setSpeed(255); //set the speed to full speed 255/255

armmotor.setSpeed(255); //set the speed for the arm

Serial.begin(9600); // begin serial communitication

Serial.println("Motor test!");

pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)

pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)

}

void loop() {

long duration, distance; // start the scan

digitalWrite(trigPin, LOW);

delayMicroseconds(2); // delays are required for a succesful sensor operation.

digitalWrite(trigPin, HIGH);

delayMicroseconds(10); //this delay is required as well!

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = ((duration/2) / (29.1));// convert the distance to centimeters.

if (distance < 10) /*if there's obstacle 10 centimers ahead, do the following: */ {

Serial.println ("Close Obstacle detected!" );

Serial.println ("Obstacle Details:");

Serial.print ("Distance From Robot is " );

Serial.print ( distance);

Serial.print ( " CM!");// print out the distance in centimeters.

Serial.println (" The obstacle is declared a threat due to close distance. ");

Serial.println (" Taking !");

STOP();

ARMF();

delay(2000);

ARMR();

BACKW();

delay(4000);

LEFT();

delay(2000);

FORW();

delay(3000);

RIGHT();

delay(2000);

FORW();

delay(8000);

STOP();

delay(4000);

ARMB();

delay(3000);

ARMR();

}

else {

Serial.println ("No obstacle detected. going forward");

delay (15);

FORW();

}

}

void FORW() {

leftmotors.run(FORWARD); // 2 left motors go in forward direction

rightmotors.run(FORWARD); // 2 right motors go in forward direction

}

void BACKW() {

leftmotors.run(BACKWARD); // 2 left motors go in backward direction

rightmotors.run(BACKWARD); // 2 right motors go in backward direction

}

void STOP() {

leftmotors.run(RELEASE); // stop 2 left motors

rightmotors.run(RELEASE); // stop 2 right motors

}

void LEFT(){

leftmotors.run(FORWARD); //2 left motors go in forward direction

rightmotors.run(BACKWARD); //2 right motors go in backward direction. This make the robot spin to the left 90 degree.

}

void RIGHT() {

leftmotors.run(BACKWARD); //the other way.

rightmotors.run(FORWARD);

}

void ARMF() {

armmotor.run(FORWARD);

}

void ARMB() {

armmotor.run(BACKWARD);

}

void ARMR() {

armmotor.run(RELEASE);

}

