#include <Wire.h>#include <Adafruit_MotorShield.h>

#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Select which 'port' M1, M2, M3 or M4. In my case, M3 & M4

Adafruit_DCMotor *motorr = AFMS.getMotor(3);//my rightside motor

Adafruit_DCMotor *motorl = AFMS.getMotor(4);//my leftside motor

In void Setup()

Put :

Serial.begin(9600); // begin serial communitication

AFMS.begin();

motorl->setSpeed(x); //set the speed of the motors, between 0-255

motorr->setSpeed (x);// I used a variable x to alter speed on demand but you can put any number between 0...stopped--255 full speed

motorl->run(RELEASE);

// NOTICE there is no dot after motorl. Most dots are replaced by typing minus sign and greater than sign thus... " ->". this is because that sign is a pointer in the code. Don't know why they changed this as its not intuitive at all.

motorr->run(RELEASE);

Now Void loop()

Here is a couple of examples how I drive the thing.

I used switch case statements to use my IR keypad but you can just as easy use sensor inputs to control the thing.

switch (results.value) {

case but1:

motorl->setSpeed (x / 2);// see the -> again...he he

motorl->run(FORWARD); // Turn right

motorr->run (RELEASE);

but1 == 0;

break;

case but2:

motorl->run(RELEASE); // Turn left

motorr->setSpeed (x / 2);

motorr->run (FORWARD);

but2 == 0;

break;

case but3:

motorl->setSpeed (x);

motorr->setSpeed (x);

motorl->run(FORWARD); // Foreward.

motorr->run (FORWARD);

but3 == 0;

break;
