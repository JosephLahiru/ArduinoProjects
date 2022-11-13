const int pingPin =8 ;
int motorpin1 = 3;                  //define digital output pin no.

int motorpin2 = 4;                  //define digital output pin no.

int motorpin3 = 5;

int motorpin4 = 6;
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
               // a maximum of eight servo objects can be created

int pos = 0; 



void setup()    // function which runs once
{ 
 Serial.begin(9600);   // initialize the data rate in bits per second
myservo.attach(9);


} 
void loop()         // function which will run continuously
{ 
 long duration, inches, cm;  //  function from datasheet of ping sensor
 pinMode(pingPin,OUTPUT);    //  
 digitalWrite(pingPin,LOW); 
 delayMicroseconds(2);       // delay recomended from datasheet
 digitalWrite(pingPin,HIGH); 
 delayMicroseconds(5);       // delay recomended from datasheet
 digitalWrite(pingPin,LOW); 
 pinMode(pingPin,INPUT); 
 duration =pulseIn(pingPin,HIGH); 
 
 inches = microsecondsToInches(duration); // converting time into distance
 cm = microsecondsToCentimeters(duration); 
 
 Serial.print(inches); 
 Serial.print("in, "); 
 Serial.print(cm); 
 Serial.print("cm"); 
 Serial.println(); 
 
 delay(100); 
{ 

  if (inches <= 2) // if there is an obstacle at 15 inches or below
{

  digitalWrite(motorpin1,LOW);

 digitalWrite(motorpin2,LOW);

 digitalWrite(motorpin3, LOW);

 digitalWrite(motorpin4, LOW);



  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
 {                                  // in steps of 1 degree
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15);                       // waits 15ms for the servo to reach the position
 }
 for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
 {                                
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15);  
 }
}

 else                       
{ 
 
 digitalWrite(motorpin1,LOW);

 digitalWrite(motorpin2,HIGH);

 digitalWrite(motorpin3,HIGH);

 digitalWrite(motorpin4,LOW);   
   }
 }
} 

long microsecondsToInches(long microseconds) 

{ 

 return microseconds / 74 / 2;  

}

long microsecondsToCentimeters(long microseconds)
{
 return microseconds / 29 / 2;
}

