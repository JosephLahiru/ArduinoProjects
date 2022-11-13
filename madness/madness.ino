#include <AFMotor.h> 
#define trigPin 12
#define echoPin 13
AF_DCMotor motor1(3); 
AF_DCMotor motor2(4);
 


char command; 
 
void setup() {
  Serial.begin(9600); 
  Serial.println("Motor test!");
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

 
void loop() {
  
 long duration, distance; 
   digitalWrite(trigPin, LOW);  
  
   digitalWrite(trigPin, HIGH);

  
   digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((duration/2)/29.1);
if(distance < 25)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
  Serial.println ("No obstacle detected. going forward");
   delay (15);
   motor1.run(FORWARD); //if there's no obstacle ahead, Go Forward! 
    motor2.run(FORWARD);

}

   
  else if 
  (Serial.available() > 0){ 
    command = Serial.read(); 
    delay (15);
    Stop(); 
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'N':
      backleft();
      break;
    case 'P':
      backright();
      break;
    }
  } 


}
  else{
    
        Serial.println ("Close Obstacle detected!" );
Serial.println ("Obstacle Details:");
Serial.print ("Distance From Robot is " );
Serial.print (distance);
Serial.print ( " CM!");// print out the distance in centimeters.

Serial.println (" The obstacle is declared a threat due to close distance. ");
Serial.println (" Turning !");
    motor1.run(FORWARD);  // Turn as long as there's an obstacle ahead.
    motor2.run (BACKWARD);
  }  

void forward()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD); 
}

void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
}

void right()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
}
void backleft()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
}
void backright()
{
 motor1.setSpeed(255);
 motor1.run(BACKWARD);
 motor2.setSpeed(0);
 motor2.run(RELEASE);
}
void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); 
  motor2.setSpeed(0);
  motor2.run(RELEASE); 
}
   

  


  
  
  
 

