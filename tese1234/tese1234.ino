#include<AFMotor.h>
#include <LiquidCrystal.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
LiquidCrystal LCD(A5, A4, A0, A1, A2, A3);

int i;

char j;

int trigPin=12;

int echoPin=13;

float pingTime;

float targetDistance;

void setup() {

Serial.begin(9600);

pinMode(trigPin, OUTPUT);

LCD.begin(16,2);

LCD_start();

while(!Serial.available());

j=Serial.read();

}

void loop() {

if(j=='a'||j=='A')

{ j='Z';

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem1[]={'A','U','T','O','M','A','T','I','C',' ','C','T','R','L'};

char displayitem2[]={'A','C','T','I','V','A','T','E','D'};

for(i=0;i<14;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem1[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<9;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem2[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(9,1);

LCD.print(" ");

delay(500);

LCD.setCursor(9,1);

LCD.print("_");

}

automatic();

}

else if(j=='m'||j=='M')

{

j='Z';

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem3[]={'M','A','N','U','A','L',' ','C','O','N','T','R','O','L'};

char displayitem4[]={'A','C','T','I','V','A','T','E','D'};

for(i=0;i<14;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem3[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<9;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem4[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(9,1);

LCD.print(" ");

delay(500);

LCD.setCursor(9,1);

LCD.print("_");

}

manual();

}

else

{

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem5[]={'W','A','I','T','I','N','G',' ',' ','F','O','R'};

char displayitem6[]={'I','N','S','T','R','U','C','T','I','O','N'};

for(i=0;i<12;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem5[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<11;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem6[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(11,1);

LCD.print(" ");

delay(500);

LCD.setCursor(11,1);

LCD.print("_");

}

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

if(com=='f'||com=='F')

{

while(!Serial.available())

{

motor1.setSpeed(200);

motor1.run(FORWARD);

motor2.setSpeed(200);

motor2.run(FORWARD);

// LCD_normal();

Serial.println("FORWARD");

}

}

else if(com=='b'||com=='B')

{

while(!Serial.available())

{

motor1.setSpeed(200);

motor1.run(BACKWARD);

motor2.setSpeed(200);

motor2.run(BACKWARD);

// LCD_normal();

Serial.println("BACKWARD");

}

}

else if(com=='l'||com=='L')

{

while(!Serial.available())

{

motor1.setSpeed(0);

motor1.run(RELEASE);

motor2.setSpeed(200);

motor2.run(FORWARD);

// LCD_obstacle();

Serial.println("LEFT TURN");

}

}

else if(com=='r'||com=='R')

{

while(!Serial.available())

{

motor1.setSpeed(200);

motor1.run(BACKWARD);

motor2.setSpeed(0);

motor2.run(RELEASE);

// LCD_obstacle();

Serial.println("RIGHT TURN");

}

}

if(com=='f'||com=='F'||com=='b'||com=='B'||com=='l'||com=='L'||com=='r'||com=='R')

goto g;

else if(com=='e'||com=='E')

{

motor1.setSpeed(0);

motor1.run(RELEASE);

motor2.setSpeed(0);

motor2.run(RELEASE);

LCD_final();

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

Serial.print("The Distance to Target is: ");

Serial.print(targetDistance);

Serial.println(" cm");

delay(10);

if(targetDistance==0.0)

{

motor1.setSpeed(200);

motor1.run(FORWARD);

motor2.setSpeed(200);

motor2.run(FORWARD);

LCD_normal();

Serial.println("FORWARD");

}

else if(targetDistance>30.0)

{

motor1.setSpeed(200);

motor1.run(FORWARD);

motor2.setSpeed(200);

motor2.run(FORWARD);

LCD_normal();

Serial.println("FORWARD");

}

else if(targetDistance<10.0)

{

motor1.setSpeed(200);

motor1.run(BACKWARD);

motor2.setSpeed(200);

motor2.run(BACKWARD);

LCD_normal();

Serial.println("BACKWARD");

}

else if(targetDistance<30.0)

{

motor1.setSpeed(0);

motor1.run(RELEASE);

motor2.setSpeed(200);

motor2.run(FORWARD);

LCD_obstacle();

Serial.println("LEFT TURN");

}

}

int com=Serial.read();

if(com=='e'||com=='E')

{

motor1.setSpeed(0);

motor1.run(RELEASE);

motor2.setSpeed(0);

motor2.run(RELEASE);

LCD_final();

Serial.println("STOPPED");

}
else goto g;
}

void LCD_start()

{

//int i;

LCD.setCursor(0,0);

LCD.print("* WELCOME SIR *");

delay(1000);

LCD.setCursor(0,1);

LCD.print(" PROJECT : ABRC ");

delay(2000);
LCD.clear();
for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem7[]={'C','H','E','C','K','I','N','G',' ','M','O','T','O','R','S'};

char displayitem8[]={'C','O','M','P','L','E','T','E','D'};

for(i=0;i<15;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem7[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(200);

LCD.setCursor(15,0);

LCD.print("_");

delay(200);

LCD.setCursor(15,0);

LCD.print(" ");

}

for(i=0;i<9;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem8[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(9,1);

LCD.print(" ");

delay(500);

LCD.setCursor(9,1);

LCD.print("_");

}

for(i=0;i<2;i++)

{
LCD.clear();
LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem9[]={'B','A','S','E','C','O','D','E'};

char displayitem10[]={'U','P','D','A','T','E','D'};

for(i=0;i<8;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem9[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(200);

LCD.setCursor(8,0);

LCD.print("_");

delay(200);

LCD.setCursor(8,0);

LCD.print(" ");

}

for(i=0;i<7;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem10[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(7,1);

LCD.print(" ");

delay(500);

LCD.setCursor(7,1);

LCD.print("_");

}

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem11[]={'I','N','T','I','A','L','I','S','I','N','G'};

char displayitem12[]={'S','E','Q','U','E','N','C','E'};

for(i=0;i<11;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem11[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<8;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem12[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(8,1);

LCD.print(" ");

delay(500);

LCD.setCursor(8,1);

LCD.print("_");

}

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

char displayitem5[]={'W','A','I','T','I','N','G',' ',' ','F','O','R'};

char displayitem6[]={'I','N','S','T','R','U','C','T','I','O','N'};

for(i=0;i<12;i++)

{

LCD.setCursor(i,0);

LCD.print(displayitem5[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<11;i++)

{

LCD.setCursor(i,1);

LCD.print(displayitem6[i]);

LCD.print("_");

delay(50);

}

for(i=0;i<3;i++)

{

delay(500);

LCD.setCursor(11,1);

LCD.print(" ");

delay(500);

LCD.setCursor(11,1);

LCD.print("_");

}

}

void LCD_normal()

{

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

LCD.setCursor(0,0);

LCD.print("ULTRASONIC");

LCD.setCursor(0,1);

LCD.print("INITIATED");

LCD.setCursor(11,0);

LCD.print(targetDistance);

delay(50);

}

void LCD_obstacle()

{

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

LCD.setCursor(0,0);

LCD.print("OBSTACLE");

LCD.setCursor(0,1);

LCD.print("DETECTED");

LCD.setCursor(11,0);

LCD.print(targetDistance);

delay(100);

}

void LCD_final()

{

LCD.setCursor(0,0);

LCD.print("** THANK YOU **");

delay(1000);

LCD.setCursor(0,1);

LCD.print(" PROJECT : ABRC ");

delay(2000);

for(i=0;i<2;i++)

{

LCD.setCursor(0,i);

LCD.print(" ");

}

}
