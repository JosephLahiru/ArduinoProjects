#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(12, 11); // RX, TX

//driving mode of the car, it depends on tha band of the of the track
# define STOPPED 0
# define FOLLOWING_LINE 1
# define NO_LINE 2
# define BIG_ANGLE_LEFT 3
# define BIG_ANGLE_RIGHT 4
# define SMALL_ANGLE_LEFT 5
# define SMALL_ANGLE_RIGHT 6

//motor pin configuration
int rightMotorEnable = 3;
int leftMotorEnable = 5;
int rightMotorBackward = 6;
int rightMotorForward = 7;
int leftMotorBackward = 8;
int leftMotorForward = 9;

const int lineFollowSensor0 = A0; //righ most sensor
const int lineFollowSensor1 = A1; 
const int lineFollowSensor2 = A3; 
const int lineFollowSensor3 = A4;
const int lineFollowSensor4 = A2; //left most sensor

int leftMotorStartingSpeed = 170;
int rightMotorStartingSpeed = 185;
int manualSpeed = 160;

char btCommand = 'S';
char prevCommand = 'A';
int velocity = 0;   
unsigned long timer0 = 2000;  //Stores the time (in millis since execution started) 
unsigned long timer1 = 0;  //Stores the time when the last command was received from the phone

int mode = 0;

int LFSensor[5]={0, 0, 0, 0, 0};

// PID controller
float Kp=70;
float Ki=0;
float Kd=50;

float pidValue = 0;

float error=0, P=0, I=0, D=0, PIDvalue=0;
float previousError=0, previousI=0;

int wheelCheck=0;
//String command;
String device;

String inputString = "";
String command = "";
String value = "";
boolean stringComplete = false; 

void setup() {
  Serial.begin(9600);  //Set the baud rate to that of your Bluetooth module.
  bluetoothSerial.begin(9600); //set the baud rate for your bluetooth module

  //all motor controller related pin should be output
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT);
  pinMode(leftMotorEnable, OUTPUT);

  //all sensor pin should be input
  pinMode(lineFollowSensor0, INPUT);
  pinMode(lineFollowSensor1, INPUT);
  pinMode(lineFollowSensor2, INPUT);
  pinMode(lineFollowSensor3, INPUT);
  pinMode(lineFollowSensor4, INPUT);

  //command for bluetooth receiver
  inputString.reserve(50);  // reserve 50 bytes in memory to save for string manipulation 
  command.reserve(50);
  value.reserve(50);
}

void loop() {

 //uncomment the following two lines for testing sensors
 //testLineFollowSensorsAndPIDvalue();
 //delay(1000);

 /****************This snippet is for PID tuning using Bluetooth***************************/
 serialEvent(); //check if bluetooth receiver receives any data
 if (stringComplete) {
    delay(100);
    // identified the posiion of '=' in string and set its index to pos variable
    int pos = inputString.indexOf('=');
    // value of pos variable > or = 0 means '=' present in received string.
    if (pos > -1) {
      // substring(start, stop) function cut a specific portion of string from start to stop
      // here command will be the portion of received string till '='
      // let received string is KP=123.25
      // then the receive value id for KP and actual value is 123.25 
      command = inputString.substring(0, pos);
      // value will be from after = to newline command
      // for the above example Kp value is 123.25
      // we just ignoreing the '=' taking first parameter of substring as 'pos+1'
      // we are using '=' as a separator between command and vale
      // without '=' any other character can be used
      value = inputString.substring(pos+1, inputString.length()-1);  // extract command up to \n exluded
      pidValue = value.toFloat(); //convert the string into float value
      //uncomment following line to check the value in serial monitor
      //Serial.println(pidValue);
      if(command == "KP"){
           Kp = pidValue;
           delay(50);
           }
      else if(command == "KI"){
           Ki = pidValue;
           delay(50);
           }
      else if(command == "KD"){
           Kd = pidValue;
           delay(50);
           } 
        } 
      inputString = "";
      stringComplete = false;//all the data is collected from serial buffer
    }

 /*********************This snippet is for Line Following***************************************/
 readLFSsensorsAndCalculateError(); //read sensor, calculate error and set driving mode
 switch (mode)
   {
    case STOPPED:  //all sensors read black line
      wheelCheck=0;
      motorStop();
      previousError = error;
      break;

    case NO_LINE:  //all sensor are on white plane
      wheelCheck+=1; 
      if(wheelCheck==1){
      forward();
      delay(2);
      }
      else if(wheelCheck==2){
      wheel_rotation(120,-120);
      delay(4);
      }
      previousError = 0;
      break;
      
    case BIG_ANGLE_RIGHT:
      wheelCheck=0;
      wheel_rotation(-120,120); //rotate right for small angle
      delay(5);  //delay determines the degree of angle

    case BIG_ANGLE_LEFT:
      wheelCheck=0;
      wheel_rotation(120,-120); //rotate left for small angle
      delay(5);
      
    case SMALL_ANGLE_RIGHT:
      wheelCheck=0;
      wheel_rotation(-120,120);
      delay(20); //rotate right for big angle
      previousError = 0;
      break;

    case SMALL_ANGLE_LEFT:
      wheelCheck=0;
      wheel_rotation(120,-120);
      delay(20); //rotate left for big angle
      previousError = 0;
      break;

    case FOLLOWING_LINE: //everything is going well
      wheelCheck=0;      
      calculatePID();
      motorPIDcontrol();   
      break;     
  }

  /**************************This snippet is for Bluetooth Remote Driving****************************/
  //Uncomment following line and comment above section for manual driving 
  //bluetoothControl();
}

void forward(){ //drive forward at a preset speed
  analogWrite(rightMotorEnable, manualSpeed);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
  
  analogWrite(leftMotorEnable, manualSpeed);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
}

void backward(){
  analogWrite(rightMotorEnable, manualSpeed);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  
  analogWrite(leftMotorEnable, manualSpeed);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
}

void left(){ //left motor rotate CCW and right motor rotate CW
  analogWrite(rightMotorEnable, manualSpeed);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
  
  analogWrite(leftMotorEnable, manualSpeed);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
}


void right(){ //left motor rotate CW and left motor rotate CCW
  analogWrite(rightMotorEnable, manualSpeed);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  
  analogWrite(leftMotorEnable, manualSpeed);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
}

void motorStop(){ //speed of both motor is zero
  analogWrite(rightMotorEnable, 0);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
  
  analogWrite(leftMotorEnable, 0);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
}

void readLFSsensorsAndCalculateError()
{
  LFSensor[0] = digitalRead(lineFollowSensor0);
  LFSensor[1] = digitalRead(lineFollowSensor1);
  LFSensor[2] = digitalRead(lineFollowSensor2);
  LFSensor[3] = digitalRead(lineFollowSensor3);
  LFSensor[4] = digitalRead(lineFollowSensor4);
  
  if((     LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 1 ))  {mode = FOLLOWING_LINE; error = 4;}
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 ))  {mode = FOLLOWING_LINE; error = 3;}
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 0 ))  {mode = FOLLOWING_LINE; error = 2;}
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 0 ))  {mode = FOLLOWING_LINE; error = 1;}
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  {mode = FOLLOWING_LINE; error = 0;}
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  {mode = FOLLOWING_LINE; error =- 1;}
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  {mode = FOLLOWING_LINE; error = -2;}
  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  {mode = FOLLOWING_LINE; error = -3;}
  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  {mode = FOLLOWING_LINE; error = -4;}
  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 ))  {mode = STOPPED; error = 0;}
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  {mode = NO_LINE; error = 0;}
  //track goes right at an angle >90 degree
  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  {mode = BIG_ANGLE_RIGHT; error = 0;}
  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 0 ))  {mode = BIG_ANGLE_RIGHT; error = 0;}
  //track goes right at an angle <90 degree
  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  {mode = SMALL_ANGLE_RIGHT; error = 0;}
  //track goes left at an angle >90 degree
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 ))  {mode = BIG_ANGLE_LEFT; error = 0;}
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 ))  {mode = BIG_ANGLE_LEFT; error = 0;}
  //track goes left at an angle <90 degree
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 1 ))  {mode = SMALL_ANGLE_LEFT; error = 0;}

}

void testLineFollowSensorsAndPIDvalue()
{
     int LFS0 = digitalRead(lineFollowSensor0);
     int LFS1 = digitalRead(lineFollowSensor1);
     int LFS2 = digitalRead(lineFollowSensor2);
     int LFS3 = digitalRead(lineFollowSensor3);
     int LFS4 = digitalRead(lineFollowSensor4);
     
     Serial.print ("LFS: L  0 1 2 3 4  R ==> "); 
     Serial.print (LFS0); 
     Serial.print (" ");
     Serial.print (LFS1); 
     Serial.print (" ");
     Serial.print (LFS2); 
     Serial.print (" ");
     Serial.print (LFS3); 
     Serial.print (" ");
     Serial.print (LFS4); 
     Serial.print ("  ==> ");
    
     Serial.print (" P: ");
     Serial.print (P);
     Serial.print (" I: ");
     Serial.print (I);
     Serial.print (" D: ");
     Serial.print (D);
     Serial.print (" PID: ");
     Serial.println (PIDvalue);
}

void bluetoothControl(){
  if(bluetoothSerial.available() > 0){ 
    timer1 = millis();   
    prevCommand = btCommand;
    btCommand = bluetoothSerial.read(); 
    //Change pin mode only if new command is different from previous.   
    if(btCommand!=prevCommand){
      //Serial.println(command);
      switch(btCommand){
      case 'F':  
        forward();
        break;
      case 'B':  
        backward();
        break;
      case 'L':  
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':  
        motorStop();
        break; 
      case 'I':  //FR  
        right();
        break; 
      case 'J':  //BR  
        left();
        break;       
      default:  //Get velocity
        if(btCommand=='q'){
          velocity = 255;  //Full velocity
          manualSpeed = velocity;
        }
        else{ 
          //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
          if((btCommand >= 48) && (btCommand <= 57)){ 
            //Subtracting 48 changes the range from 48-57 to 0-9.
            //Multiplying by 25 changes the range from 0-9 to 0-225.
            velocity = (btCommand - 48)*25;       
            manualSpeed = velocity;
          }
        }
      }
    }
  } 
}


void calculatePID()
{
  P = error; //maximum error value is 4 and minimum is zero
  I = I + error; 
  D = error-previousError; 
  PIDvalue = (Kp*P) + (Ki*I) + (Kd*D);
  previousError = error;
}

void motorPIDcontrol()
{  
  int leftMotorSpeed = leftMotorStartingSpeed + PIDvalue;
  int rightMotorSpeed = rightMotorStartingSpeed - PIDvalue;
  
  // The motor speed should not exceed the max PWM value
  constrain(leftMotorSpeed, 100, 255);
  constrain(rightMotorSpeed, 100, 255);

  //determing the rotation and direction of wheel
  wheel_rotation(leftMotorSpeed,rightMotorSpeed);
}

void wheel_rotation(int left, int right){
  if(left>0){
    analogWrite(leftMotorEnable, left);
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
    }
  else if(left<0){
    analogWrite(leftMotorEnable, abs(left));
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, HIGH);
    }
  if(right>0){
    analogWrite(rightMotorEnable, right);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(rightMotorBackward, LOW);
    }
  else if(right<0){
    analogWrite(rightMotorEnable, abs(right));
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, HIGH);
    }
  }

void serialEvent() {
  while (bluetoothSerial.available()) {
    // get the new byte:
    char inChar = (char)bluetoothSerial.read(); 
    //Serial.write(inChar);
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline or a carriage return, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n' || inChar == '\r') {
      stringComplete = true;
    } 
  }
}

/*
void checkBTcmd()  
 { 
   while (Serial.available())   //Check if there is an available byte to read
   {
     delay(10); //Delay added to make thing stable 
     char c = Serial.read(); //Conduct a serial read
     device += c; //build the string.
   }  
   if (device.length() > 0) 
   {
     //Serial.print("Command received from BT ==> ");
     //Serial.println(device); 
     command = device;
     device ="";  //Reset the variable
     Serial.flush();
    } 
}
*/
