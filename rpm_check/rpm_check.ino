#include <timerOne.h>
unsigned int counter=0;


void document(){

  counter++;
  
}

void timerIst
{

  Timer1.detachInterrupt();
  Serial.print("Motor Speed: ");
  int rotation = (counter / 20);
  Serial.print(rotation,DEC);
  Serial.println(" Rotation per Second");
  counter=0;
  Timer1.attachInterrupt(timerIst);
  
}
void setup() {
  Serial.begin(9600);

 pinMode(bla,OUTPUT);
 pinMode(blb,OUTPUT);

Timer1.initialize(1000000);
attachInterrupt(0,document,RISING);
timer1.attachInterrupt( timerIst);
}

void loop() {
 

}
