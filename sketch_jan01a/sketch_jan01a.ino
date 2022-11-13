#include <Servo.h> // this adds the "Servo" library to the program
 
// the following creates two servo objects
Servo leftMotor;
Servo rightMotor;
 
void setup()
{
    leftMotor.attach(12); // if you accidentally switched up the pin numbers for your servos, you can swap the numbers here
    rightMotor.attach(13);
}
 
 
void loop()
{
    leftMotor.write(180); // with continuous rotation, 180 tells the servo to move at full speed "forward."
    rightMotor.write(0); // if both of these are at 180, the robot will go in a circle because the servos are flipped. "0" tells it to move full speed "backwards."
}
