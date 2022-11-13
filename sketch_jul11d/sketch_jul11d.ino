#include <AFMotor.h> //import your motor shield library

#define trigPin 41 // define the pins of your sensor

#define echoPin 39

#define vcc 43

#define gnd 37

AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.

AF_DCMotor motor4(4, MOTOR34_8KHZ);

void setup() {

Serial.begin(9600); // begin serial communitication

Serial.println("Motor test!");

pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)

pinMode(echoPin, INPUT);

pinMode(vcc,OUTPUT);

pinMode(gnd,OUTPUT);

digitalWrite(vcc,HIGH);

digitalWrite(gnd,LOW);// set the echo pin to input (recieve sound waves)

motor1.setSpeed(255); //set the speed of the motors, between 0-255

motor4.setSpeed (255);

}

void loop() {

long duration, distance; // start the scan

digitalWrite(trigPin, LOW);

delayMicroseconds(2); // delays are required for a succesful sensor operation.

digitalWrite(trigPin, HIGH);

delayMicroseconds(10); //this delay is required as well!

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;// convert the distance to centimeters.

if (distance < 25)/*if there's an obstacle 25 centimers, ahead, do the following: */ {

Serial.println ("Close Obstacle detected!" );

Serial.println ("Obstacle Details:");

Serial.print ("Distance From Robot is " );

Serial.print ( distance);

Serial.print ( " CM!");// print out the distance in centimeters.

Serial.println (" The obstacle is declared a threat due to close distance. ");

Serial.println (" Turning !");

motor1.run(BACKWARD); // Turn as long as there's an obstacle ahead.

motor4.run (FORWARD);

}

else {

Serial.println ("No obstacle detected. going forward");

delay (15);

motor1.run(FORWARD); //if there's no obstacle ahead, Go Forward!

motor4.run(FORWARD);

}

}
