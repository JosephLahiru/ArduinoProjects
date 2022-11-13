#include<AFMotor.h>
AF_DCMotor motor1(3); 
AF_DCMotor motor2(4);  




int i;

char j;



int trigPin=12;
int echoPin=13;
int left1motor=6;
int left2motor=7;
int right1motor=8;
int right2motor=11;
float pingTime;
float targetDistance;

void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(left1motor, OUTPUT);
pinMode(left2motor, OUTPUT);
pinMode(right1motor, OUTPUT);
pinMode(right2motor, OUTPUT);


while(!Serial.available());
j=Serial.read();
}

void loop(){ 
if(j=='a'||j=='A'){

automatic();

}

else if(j=='m'||j=='M')

{



manual();

}



while(!Serial.available());

j=Serial.read();

}

void manual()

{

char com;

while(!Serial.available());

g:

com=Serial.read();

if(com=='w'||com=='W')

{

while(!Serial.available())

{

digitalWrite(left1motor, HIGH);

digitalWrite(left2motor, LOW);

digitalWrite(right1motor, HIGH);

digitalWrite(right2motor, LOW);

Serial.println("FORWARD");

}

}

else if(com=='s'||com=='S')

{

while(!Serial.available())

{

digitalWrite(left1motor, LOW);

digitalWrite(left2motor, HIGH);

digitalWrite(right1motor, LOW);

digitalWrite(right2motor, HIGH);

// LCD_normal();

Serial.println("BACKWARD");

}

}

else if(com=='a'||com=='A')

{

while(!Serial.available())

{

digitalWrite(left1motor, LOW);

digitalWrite(left2motor, HIGH);

digitalWrite(right1motor, HIGH);

digitalWrite(right2motor, LOW);

// LCD_obstacle();

Serial.println("LEFT TURN");

}

}

else if(com=='d'||com=='D')

{

while(!Serial.available())

{

digitalWrite(left1motor, HIGH);

digitalWrite(left2motor, LOW);

digitalWrite(right1motor, LOW);

digitalWrite(right2motor, HIGH);

// LCD_obstacle();

Serial.println("RIGHT TURN");

}

}

if(com=='a'||com=='A'||com=='s'||com=='S'||com=='A'||com=='a'||com=='d'||com=='D')

goto g;

else if(com=='e'||com=='E')

{

digitalWrite(left1motor, LOW);

digitalWrite(left2motor, LOW);

digitalWrite(right1motor, LOW);

digitalWrite(right2motor, LOW);



Serial.println("STOPPED");

}

}

void automatic()

{

g:

while(!Serial.available())

{

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

pingTime = pulseIn(echoPin, HIGH);

pingTime=pingTime/29;

targetDistance=pingTime/2;


if(targetDistance==0.0)

{

digitalWrite(left1motor, HIGH);

digitalWrite(left2motor, LOW);

digitalWrite(right1motor, HIGH);

digitalWrite(right2motor, LOW);


Serial.println("FORWARD");

}

else if(targetDistance>30.0)

{

digitalWrite(left1motor, HIGH);

digitalWrite(left2motor, LOW);

digitalWrite(right1motor, HIGH);

digitalWrite(right2motor, LOW);



Serial.println("FORWARD");

}

else if(targetDistance<10.0)

{

digitalWrite(left1motor, LOW);

digitalWrite(left2motor, HIGH);

digitalWrite(right1motor, LOW);

digitalWrite(right2motor, HIGH);



Serial.println("BACKWARD");

}

else if(targetDistance<30.0)

{

digitalWrite(left1motor, LOW);

digitalWrite(left2motor, HIGH);

digitalWrite(right1motor, HIGH);

digitalWrite(right2motor, LOW);

Serial.println("LEFT TURN");

}

}

int com=Serial.read();

if(com!='e'||com!='E')

goto g;

}


