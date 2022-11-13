//  Created by Josef Holmner, Sweden, Uppsala 2013. 


/*
INSTRUCTIONS FOR ROBOT
Potentiometer to the far left = slow moving robot
Potentiometer to the far right = fast moving robot
Potentiometer in middle = programing mode
Potentiometer to the far right + pushbutton pressed during green light blinking = turbo speed
*/



//Sonar 1
#include <NewPing.h>
#define  TRIGGER_PIN  8
#define  ECHO_PIN     12
#define MAX_DISTANCE 300 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

//Sonar 2
#define  TRIGGER_PIN2  10
#define  ECHO_PIN2     9
#define MAX_DISTANCE2 100 
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE2); 

#include <Servo.h> 
Servo myServo; 


//Engines
int rightEngF = 5;
int leftEngF = 3;
int rightEngB = 11;
int leftEngB = 6;

//Pins
int greenLed = 13;
int redLed = 4;
int servopin = 7;                  

int potenti = 0;
int turboPin = 1;

int speakerPin = 2;


///VARIABLES
float speedFactor = 1;  //Determains motor speed...
int mode;   // mode 0 = calm      mode 1 = medium    mode 2 = fast       mode 666 = programming        
int distanceHead_0; //Upper sonar sensor distance
int distanceHead_m45;
int distanceHead_m90;
int distanceHead_p45;
int distanceHead_p90;
int distanceBreak; //Lower sonar sensor distance
boolean justLookedRight = true;
int speedMode; //1 slow, 2 faster, 3 fastest

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(rightEngF, OUTPUT);
  pinMode(leftEngF, OUTPUT);
  pinMode(rightEngB, OUTPUT);
  pinMode(leftEngB, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  
  Serial.begin(9600);
  myServo.attach(servopin);    
 launchRobot();  
}



void loop(){      
  brain();  
}




void brain(){
  updateDistances();  
  setCorrectSpeed();
  goForwards();
  if(panicBreak(20)){}
  
 else if(distanceHead_0<25 && distanceHead_0>=20){
    justLookAround(35);
  }
 else if(distanceHead_0<40 && distanceHead_0>=25){
    moveRead45(1.1);
  }
  
 else if(distanceHead_0>=40){
    justLookAround(35);
  }     
  
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void launchRobot(){
  
    
  Serial.println("");
   Serial.println("");
  Serial.println("I was made in the year 2013 by Josef Holmner, Sweden.");
   Serial.println("");
    Serial.println("");
    delay(100);
  wakeUpMusic();  
  delay(100);
  lookForwards();  
  delay(700);
  wakeUpMusic2();
  ledBlink(greenLed,greenLed,5,600);
  
  
  //         Mode   ////////////////////////////
  float pot_temp = analogRead(potenti);
  int turbo_temp = analogRead(turboPin);  
  int partyMode = analogRead(turboPin);
  
    settingsRegMusic();
  
  if(pot_temp < 850){
  mode = 0;
  }
  else{
    mode = 666;
  }  
  if(mode == 0 && partyMode <10){
   mode = 1; 
  }
  
  if(mode == 666 && partyMode <10){
   mode = 2; 
  }
  
  delay(1000);  
  //     ProgramingMode   ///////////////////////////
  if(mode == 666){
    mode666Music();
    programingMode();
  } 
  
  ledBlink(greenLed,redLed,10,200);
  delay(200);    
  if(mode==0){
    mode0Music();
  }  
  
  if(mode==1){
    partyMode_func();
  }  
  
   if(mode==2){
    songMode();
  }  
  
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////



void programingMode(){
 while(true){
  ledBlink(redLed,redLed,5,2000);
  Serial.println("codingMode...");
 }  
}



void ledBlink(int led1, int led2,int num, int del){    
  for(int i = 0; i< num; i++){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay((int)(del/2));
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay((int)(del/2));  
  }
}

void setCorrectSpeed(){
if(distanceHead_0<50 || distanceBreak<40){
  speedMode = 1;
  }
  else if(distanceHead_0<130 && distanceBreak>40 && distanceHead_m45>24 && distanceHead_p45>24){
    speedMode = 2;
  }
  else if(distanceHead_0>=130 && distanceBreak>70 && distanceHead_m45>40 && distanceHead_p45>40){
   speedMode = 3; 
  }
  else{speedMode = 1;}
}


void updateDistances(){
  distanceHead_0 = currentDistanceHead();
  delay(12);
  distanceBreak = currentDistanceBreak();
}


boolean panicBreak(int tol){
  if(distanceHead_0 < tol || distanceBreak < tol){
  stopAll();  
  panicStopMusic();
  backUp();
  lookLeft90();
 delay(250);
  distanceHead_m90 = currentDistanceHead();
  lookRight90();
  delay(400);
  distanceHead_p90 = currentDistanceHead();    
  lookForwards();
  if(distanceHead_p90>distanceHead_m90){    
    turnRight90();
  }  
  else{    
    turnLeft90();
  }    return true;
  }  return false;
}


void moveRead45(int diffFactor){
  digitalWrite(greenLed, HIGH);
  lookRight45();
  if(delayWhileRead(170)){
    lookForwards();
    delay(210);
    panicBreak(20);
    digitalWrite(greenLed, LOW);
    return;
  } 
  distanceHead_p45 = currentDistanceHead();
  lookLeft45();
  if(delayWhileRead(250)){
    lookForwards();
    delay(210);
    panicBreak(20);
    digitalWrite(greenLed, LOW);
    return;
  } 
  distanceHead_m45 = currentDistanceHead();
  
   if(distanceHead_p45>diffFactor*distanceHead_m45){
     lookForwards();
     turnRight45();
   }
   else{
     lookForwards();
     turnLeft45();
   }
   digitalWrite(greenLed, LOW);   
}

void justLookAround(int tol){  
  if(justLookedRight){
  lookLeft75();
  if(delayWhileRead(210)){
    lookForwards();
    delay(210);
    panicBreak(20);
    return;
  }  
  distanceHead_m45 = currentDistanceHead();  
  lookForwards();  
    if(distanceHead_m45<tol){      
    turnRight20();       
    }else{delay(150);}
  }
  else{
  lookRight75();
  if(delayWhileRead(210)){
    lookForwards();
    delay(210);
    panicBreak(20);
    return;
  }  
  distanceHead_p45 = currentDistanceHead();
  lookForwards();
      if(distanceHead_p45<tol){    
    turnLeft20();    
      }else{delay(150);}
    }
  justLookedRight = !justLookedRight;
}



boolean delayWhileRead(int millisec){
 delay((int)((millisec/2)-25));
 distanceBreak = currentDistanceBreak();
  if(distanceBreak<20){    
 stopAll();
 return true;
 }
  delay((int)((millisec/2)-25));  
  return false;
}




int currentDistanceHead(){
  float remember = 0;
  int goodReads = 0;
  int tempReading = 0;
  
  for(int i = 0; i<3  ; i++){  
  delay(17);
  tempReading = sonar.ping_cm();  
    if(tempReading != 0){
      goodReads++;
      remember += tempReading;
      }
   }  delay(10);
  if(goodReads == 0){
   return 300;    
  } 
  return (int)(remember/goodReads);  
}


int currentDistanceBreak(){
  float remember = 0;
  int goodReads = 0;
  int tempReading = 0;
  
  for(int i = 0; i<3  ; i++){  
  delay(10);
  tempReading = sonar2.ping_cm();  
    if(tempReading != 0){
      goodReads++;
      remember += tempReading;
      }
   }  delay(17);
  if(goodReads == 0){
   return 300;    
  } 
  return (int)(remember/goodReads);  
}



void lookLeft90(){  
   myServo.write(0); 
 } 




void lookRight90(){      
    myServo.write(160);   
} 


void lookLeft45(){  
   myServo.write(40);   
} 

void lookRight45(){      
    myServo.write(130);   
}


void lookLeft75(){  
   myServo.write(20);   
} 

void lookRight75(){      
    myServo.write(140);   
}



void lookForwards(){
   myServo.write(80);      
}






void turnLeft90(){  
  stopAll();
   distanceHead_m45 = 10;
  distanceHead_p45 = 10;
  analogWrite(rightEngF,135);
  analogWrite(leftEngB,135);
  delay(980);
  stopAll();
}


void turnRight90(){  
  stopAll();
   distanceHead_m45 = 10;
  distanceHead_p45 = 10;
  analogWrite(rightEngB,130);
  analogWrite(leftEngF,130);
  delay(820);
  stopAll();
}

void turnRight45(){    
  stopAll();
   distanceHead_m45 = 10;
  distanceHead_p45 = 10;
  analogWrite(rightEngB,130);
  analogWrite(leftEngF,130);
  delay(580);  
  stopAll();
}

void turnLeft45(){  
  stopAll();
   distanceHead_m45 = 10;
  distanceHead_p45 = 10;
  analogWrite(rightEngF,135);
  analogWrite(leftEngB,135);  
  delay(720);
  stopAll();
}

void turnRight20(){  
  stopAll();
  analogWrite(rightEngB,130);
  analogWrite(leftEngF,130);  
  delay(240);  
  stopAll();
  goForwards();
}

void turnLeft20(){  
  stopAll();
  analogWrite(rightEngF,130);
  analogWrite(leftEngB,130);  
  delay(240);  
  stopAll();
  goForwards();
}



void goForwards(){  
  stopAll();
    if(speedMode==1){
       analogWrite(rightEngF,100);
       analogWrite(leftEngF,78);
    }
    
     if(speedMode==2){
         analogWrite(rightEngF,127);
          analogWrite(leftEngF,95); 
    }
    
     if(speedMode==3){
  analogWrite(rightEngF,255);
  analogWrite(leftEngF,220);
    }
   
}


void backUp(){
  stopAll();
  analogWrite(rightEngB,(int)(255*0.5));
  analogWrite(leftEngB,(int)(190*0.5));
  delay(400);
  stopAll();
}

void stopAll(){
   analogWrite(rightEngF,0);
  analogWrite(leftEngF,0);
  analogWrite(rightEngB,0);
  analogWrite(leftEngB,0);
}






// MUSIC SPEAKER

void wakeUpMusic(){  
  for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(1000-3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(1000-3*i);    
  }  
  delay(100);  
   for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(1000-3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(1000-3*i);    
  }     
}

void wakeUpMusic2(){
   for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(300+3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(300+3*i);    
  }  
    for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(300+3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(300+3*i);    
  }  
}


void settingsRegMusic(){
    for(int i = 0; i<50;i++){
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(300);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(300);    
    }    
    delay(300);    
     for(int i = 0; i<50;i++){
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(600);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(600);    
    }  
}



void mode666Music(){    
   for(int i = 0; i<300;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(1000+i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(1000+i);    
  }     
} 

void mode0Music(){  
    for(int i = 0; i<240;i++){
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(1500);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(1500);    
    }    
    for(int i = 0; i<240;i++){
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(500);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(500);    
    } 
}

void panicStopMusic(){    
  digitalWrite(redLed, HIGH);
   for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(1800);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(1800);    
  }
digitalWrite(redLed, LOW);  
} 








// PARTY_MODE ///////////
void partyMode_func(){
  lookForwards();
  delay(800);
    for(int i = 0; i<400;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(800+2*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(900+2*i);    
  }     
  lookLeft90();
  delay(800);
   stopAll();
  analogWrite(rightEngB,(int)(255));
  analogWrite(leftEngB,(int)(190));
  delay(260);
  stopAll();
   analogWrite(rightEngF,(int)(255));
  analogWrite(leftEngF,(int)(190));
  delay(260);
   stopAll();
   
   ledBlink(greenLed,greenLed,2,300);
   delay(900);
   musicBox(100,300);
   delay(100);
   musicBox(60,800);
   delay(900);
   turnRight45();
   delay(600);
   
   lookRight90();
   delay(600);
     
   musicBox(80,600);
   delay(100);
   musicBox(160,200);
   delay(300);
   ledBlink(greenLed,greenLed,2,200);
   delay(300);
   lookLeft90();
   delay(800);
    for(int i = 0; i<300;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(800-i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(900-i);    
  }   
 for(int i = 0; i<300;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(1600+i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(1700+i);    
  }   
   
   delay(1200);
     wakeUpMusic(); 
  delay(300);
  wakeUpMusic2(); 
  wakeUpMusic2(); 
  delay(1000);
  
  basicRythm(false);
  basicRythm(false); 
  basicRythm(false);      
  
  delay(400);
  musicBox(75,400);
  for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(400+3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(400+3*i);    
  }
   delay(100);
  musicBox(60,500);
  for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(500+3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(500+3*i);    
  }
    delay(100);
  musicBox(50,600);
  for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(600+3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(600+3*i);    
  }
  
  delay(900);
  
    musicBox(100,500);
  delay(250);
   musicBox(100,500);
  delay(250);
   musicBox(100,500);
  delay(110);
   musicBox(100,500);
  delay(110);
   musicBox(100,500);
  delay(250);
  
   musicBox(100,500);
  delay(110);
   musicBox(100,500);
   delay(110);
   musicBox(100,500);
  delay(110);
   musicBox(100,500);
   delay(250);
   digitalWrite(redLed, HIGH);
    musicBox(100,700);
    digitalWrite(redLed, LOW);
  delay(110);  
  digitalWrite(redLed, HIGH);
   musicBox(110,700);   
   digitalWrite(redLed, LOW);
   delay(800);
   
   musicBox(75,400);
    for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(400+3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(400+3*i);    
  }
   delay(100);
  musicBox(60,500);
  for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(500+3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(500+3*i);    
  }
    delay(100);
  musicBox(50,600);
  for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(600+3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(600+3*i);    
  }
   
   delay(600);
         
    basicRythm(true); 
    basicRythm(true); 
    basicRythm(true); 
    delay(400);
    lookForwards();
    delay(1400);
    for(int i = 0; i<13;i++){  
  ledBlink(greenLed,redLed,1,50);
  musicBox(30,400);
     }
    
     for(int i = 0; i<17;i++){  
  ledBlink(greenLed,redLed,1,50);
  musicBox(30,300);
     }
    
     for(int i = 0; i<30;i++){  
  ledBlink(greenLed,redLed,1,50);
  musicBox(30,200);
     }
     
    
           stopAll();
  analogWrite(rightEngB,(int)(255));
  analogWrite(leftEngF,(int)(255));  
  while(true){    
    lookRight90();
      for(int i = 0; i<8;i++){  
  ledBlink(greenLed,redLed,1,50);
  musicBox(30,200);
     }
  lookLeft90();
    for(int i = 0; i<8;i++){  
  ledBlink(greenLed,redLed,1,50);
  musicBox(30,200);
     }
  }
     
}

void basicRythm(boolean dance){
  lookRight90();
    delay(500);
   for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(800-3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(900-3*i);    
  } 
  
  lookLeft90();
  delay(500);
  for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(800-3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(900-3*i);    
  } 
  delay(500);
  for(int i = 0; i<100;i++){    
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(800-3*i);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(900-3*i);    
  } 
  
   delay(200);
    digitalWrite(redLed, HIGH);
     digitalWrite(greenLed, HIGH);
     if(dance){
        stopAll();
  analogWrite(rightEngF,(int)(155));
  analogWrite(leftEngB,(int)(155));  
     }
    musicBox(240,500);
     if(dance){
         stopAll();
    }
    digitalWrite(redLed, LOW);
     digitalWrite(greenLed, LOW);     
    delay(100);
     digitalWrite(redLed, HIGH);
     digitalWrite(greenLed, HIGH);
     
     if(dance){
         stopAll();
  analogWrite(rightEngB,(int)(155));
  analogWrite(leftEngF,(int)(155));  
     }
    musicBox(240,500);
    if(dance){
         stopAll();
    }
    delay(100);        
    digitalWrite(redLed, LOW);
     digitalWrite(greenLed, LOW);
  
}

void musicBox(int loops, int microdel){
    for(int i = 0; i<loops;i++){
   digitalWrite(speakerPin,HIGH);
  delayMicroseconds(microdel);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(microdel);  
    }
}







void songMode(){
  int lastReading;
  musicBox(100,200);
  delay(100);
  musicBox(100,200);
  delay(100);
  musicBox(100,200);
  delay(600);
  
  while(true){
    lastReading = sonar.ping_cm();
    musicBox(100,6*lastReading+200);
  }
}
