/*
  Coded by amres
  Project : AIDEN
  Date : 12/09/2017
  hello coders this is my second attempt to make a robot that works well ;) hope this will be cool.
*/
#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal LCD(30, 31, 32, 33, 34, 35);
Servo ser1;
Servo ser2;
Servo ser3;

float Kp = 1, Ki = 0.000001, Kd = 1.8;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0, con = 0;
float previous_error = 0, previous_I = 0;
int sensor[5] = {0, 0, 0, 0, 0};
int initial_motor_speed = 220;
int error_all_black;

int ang_UD = 10;
int ang_Gs1 = 53;
int ang_Gs2 = 110;

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

int x = 0;
int j = 0;
int com = 0;
int i = 0;
float cm = 0;

//IR sensors
int S0 = A0;
int S1 = A1;
int S2 = A2;
int S3 = A3;
int S4 = A4;
int S5 = A5;
int S6 = A6;
int S7 = A7;

int buzzer = 28;

// Motor Driver PWM
int enL = 6;
int enR = 5;

// Motor Driver Direction
int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

//ultrasonic opins
int trigPin_f = A10;
int echoPin_f = A11;
float pingTime_f;
float cm_f = 0;
int trigPin_l = A12;
int echoPin_l = A13;
float pingTime_l;
float cm_l = 0;
int trigPin_r = A15;
int echoPin_r = A14;
float pingTime_r;
float cm_r = 0;

void setup() {

  Serial.begin(9600);// hell yeah serial communications begun

  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
  pinMode(S7, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);

  pinMode(trigPin_f, OUTPUT);
  pinMode(trigPin_l, OUTPUT);
  pinMode(trigPin_r, OUTPUT);

  ser1.attach(2);//BLACK
  ser2.attach(3);//BLUE
  ser3.attach(4);//UP DOWN

  LCD.begin(16, 2);
  LCD_start();

  ser3.write(120);
  ser1.write(ang_Gs1);
  ser2.write(ang_Gs2);

  while (!Serial.available());
  j = Serial.read();

}

//-----------------------------------------------------------------------------------------------------------Sensor triggers BEGUN-----------------------------------------------------------------------------------------------------------------------------------//

void ultrasonic_test() {

  digitalWrite(trigPin_f, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_f, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_f, LOW);
  pingTime_f = pulseIn(echoPin_f, HIGH);
  pingTime_f = pingTime_f / 29;
  cm_f = pingTime_f / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_f);
  Serial.println(" cm_f");
  delay(10);

  digitalWrite(trigPin_l, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_l, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_l, LOW);
  pingTime_l = pulseIn(echoPin_l, HIGH);
  pingTime_l = pingTime_l / 29;
  cm_l = pingTime_l / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_l);
  Serial.println(" cm_l");
  delay(10);

  digitalWrite(trigPin_r, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_r, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_r, LOW);
  pingTime_r = pulseIn(echoPin_r, HIGH);
  pingTime_r = pingTime_r / 29;
  cm_r = pingTime_r / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_r);
  Serial.println(" cm_r");
  delay(10);

}

void read_sensor_values()
{
  sensor[0] = digitalRead(S0);
  sensor[1] = digitalRead(S1);
  sensor[2] = digitalRead(S2);
  sensor[3] = digitalRead(S3);
  sensor[4] = digitalRead(S4);
  sensor[5] = digitalRead(S5);
  sensor[6] = digitalRead(S6);
  sensor[7] = digitalRead(S7);

  Serial.print(sensor[0]);
  Serial.print("_");
  Serial.print(sensor[1]);
  Serial.print("_");
  Serial.print(sensor[2]);
  Serial.print("_");
  Serial.print(sensor[3]);
  Serial.print("_");
  Serial.print(sensor[4]);
  Serial.print("_");
  Serial.print(sensor[5]);
  Serial.print("_");
  Serial.print(sensor[6]);
  Serial.print("_");
  Serial.println(sensor[7]);

  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 1)) {
    error = 38;
    con = 7;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1) && (sensor[5] == 0) && (sensor[6] == 1) && (sensor[7] == 1)) {
    error = 34;
    con = 6;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 1) && (sensor[7] == 0)) {
    error = 30;
    con = 5;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 1) && (sensor[6] == 1) && (sensor[7] == 0)) {
    error = 26;
    con = 4;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 1) && (sensor[6] == 0) && (sensor[7] == 0)) {
    error = 22;
    con = 3;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1) && (sensor[5] == 1) && (sensor[6] == 0) && (sensor[7] == 0)) {
    error = 18;
    con = 2;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) { //14
    error = 14;
    con = 1;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) { //middle
    error = 10;
    con = 0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) { //-14
    error = -14;
    con = -1;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) {
    error = -18;
    con = -2;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) {
    error = -22;
    con = -3;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) {
    error = -26;
    con = -4;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) {
    error = -30;
    con = -5;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) {
    error = -34;
    con = -6;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0)) {
    error = -38;
    con = -7;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0) && (sensor[7] == 0))
  {
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
  }

}
//-------------------------------------------------------------------------------------------------------------------------Sensor triggers END---------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------LCD voids BEGIN------------------------------------------------------------------------------------------------------------------------//
void LCD_start()

{

  LCD.setCursor(0, 0);
  LCD.print("* WELCOME SIR *");
  delay(1000);
  LCD.setCursor(0, 1);
  LCD.print(" PROJECT : ATOM ");
  delay(2000);
  LCD.clear();
  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem7[] = {'C', 'H', 'E', 'C', 'K', 'I', 'N', 'G', ' ', 'M', 'O', 'T', 'O', 'R', 'S'};
  char displayitem8[] = {'C', 'O', 'M', 'P', 'L', 'E', 'T', 'E', 'D'};

  for (i = 0; i < 15; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem7[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(200);
    LCD.setCursor(15, 0);
    LCD.print("_");
    delay(200);
    LCD.setCursor(15, 0);
    LCD.print(" ");

  }

  for (i = 0; i < 9; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem8[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(9, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(9, 1);
    LCD.print("_");

  }

  for (i = 0; i < 2; i++)

  {

    LCD.clear();
    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem9[] = {'B', 'A', 'S', 'E', 'C', 'O', 'D', 'E'};
  char displayitem10[] = {'U', 'P', 'D', 'A', 'T', 'E', 'D'};

  for (i = 0; i < 8; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem9[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(200);
    LCD.setCursor(8, 0);
    LCD.print("_");
    delay(200);
    LCD.setCursor(8, 0);
    LCD.print(" ");

  }

  for (i = 0; i < 7; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem10[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(7, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(7, 1);
    LCD.print("_");

  }

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem11[] = {'I', 'N', 'T', 'I', 'A', 'L', 'I', 'S', 'I', 'N', 'G'};
  char displayitem12[] = {'S', 'E', 'Q', 'U', 'E', 'N', 'C', 'E'};

  for (i = 0; i < 11; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem11[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 8; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem12[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(8, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(8, 1);
    LCD.print("_");

  }

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem13[] = {'C', 'H', 'E', 'C', 'K', 'I', 'N', 'G', '_', 'G', 'R', 'I', 'P', 'P', 'E', 'R'};
  char displayitem14[] = {'C', 'O', 'M', 'P', 'L', 'E', 'T', 'E', 'D'};

  for (i = 0; i < 16; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem13[i]);
    LCD.print("_");
    delay(50);

  }

  ser3.write(ang_UD);
  ser1.write(ang_Gs1);
  ser2.write(ang_Gs2);

  for (i = 0; i < 9; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem14[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(8, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(8, 1);
    LCD.print("_");

  }

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem5[] = {'W', 'A', 'I', 'T', 'I', 'N', 'G', ' ', ' ', 'F', 'O', 'R'};
  char displayitem6[] = {'I', 'N', 'S', 'T', 'R', 'U', 'C', 'T', 'I', 'O', 'N'};

  for (i = 0; i < 12; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem5[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 11; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem6[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(11, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(11, 1);
    LCD.print("_");

  }

}

void LCD_normal()

{

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  LCD.setCursor(0, 0);
  LCD.print("ULTRASONIC");
  LCD.setCursor(0, 1);
  LCD.print("INITIATED");
  LCD.setCursor(11, 0);
  LCD.print(cm);
  delay(50);

}

void LCD_obstacle()

{

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  LCD.setCursor(0, 0);
  LCD.print("OBSTACLE");
  LCD.setCursor(0, 1);
  LCD.print("DETECTED");
  LCD.setCursor(11, 0);
  LCD.print(cm);
  delay(100);

}

void LCD_final()

{

  LCD.setCursor(0, 0);
  LCD.print("** THANK YOU **");
  delay(1000);
  LCD.setCursor(0, 1);
  LCD.print(" PROJECT : ATOM ");
  delay(2000);

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

}

void automatic_start()
{

  j = 'Z';
  LCD.clear();
  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem1[] = {'A', 'U', 'T', 'O', 'M', 'A', 'T', 'I', 'C', ' ', 'C', 'T', 'R', 'L'};
  char displayitem2[] = {'A', 'C', 'T', 'I', 'V', 'A', 'T', 'E', 'D'};

  for (i = 0; i < 14; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem1[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 9; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem2[i]);
    LCD.print("_");
    Serial.println("auto_controlling_activated");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(9, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(9, 1);
    LCD.print("_");

  }
}

void manual_start()
{

  j = 'Z';
  LCD.clear();
  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem3[] = {'M', 'A', 'N', 'U', 'A', 'L', ' ', 'C', 'O', 'N', 'T', 'R', 'O', 'L'};
  char displayitem4[] = {'A', 'C', 'T', 'I', 'V', 'A', 'T', 'E', 'D'};

  for (i = 0; i < 14; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem3[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 9; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem4[i]);
    LCD.print("_");
    Serial.println("manual_controlling_activated");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(9, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(9, 1);
    LCD.print("_");

  }

}


void ultrasonic_start()
{

  j = 'Z';
  LCD.clear();
  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem1[] = {'O', 'B', 'J', '_', 'A', 'V', 'O', 'I', 'D', 'I', 'N', 'G'};
  char displayitem2[] = {'A', 'C', 'T', 'I', 'V', 'A', 'T', 'E', 'D'};

  for (i = 0; i < 12; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem1[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 9; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem2[i]);
    LCD.print("_");
    Serial.println("OBJ_avoiding_activated");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(9, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(9, 1);
    LCD.print("_");

  }
}


void LF_OBJ_start()
{

  j = 'Z';
  LCD.clear();
  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem1[] = {'L', 'F', '_', 'O', 'B', 'J', '_', 'C', 'T', 'R', 'L'};
  char displayitem2[] = {'A', 'C', 'T', 'I', 'V', 'A', 'T', 'E', 'D'};

  for (i = 0; i < 11; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem1[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 9; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem2[i]);
    LCD.print("_");
    Serial.println("LF_OBJ_activated");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(9, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(9, 1);
    LCD.print("_");

  }
}

void end_all() {

  j = 'Z';
  LCD.clear();
  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem5[] = {'W', 'A', 'I', 'T', 'I', 'N', 'G', ' ', ' ', 'F', 'O', 'R'};
  char displayitem6[] = {'I', 'N', 'S', 'T', 'R', 'U', 'C', 'T', 'I', 'O', 'N'};

  for (i = 0; i < 12; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem5[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 11; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem6[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(11, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(11, 1);
    LCD.print("_");

  }

}

//---------------------------------------------------------------------------------------------------------------------------LCD voids END----------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------Motor Controller voids START---------------------------------------------------------------------------------------------------------------//
void forward()
{

  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);

}
void none()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 0);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 0);
}
void reverse()
{

  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);

}
void left()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);
}
void forwardleft()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 150);
}
void backwardleft()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 150);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);
}
void right()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
}
void forwardright()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 150);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
}
void backwardright()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 150);
}

void calculate_pid()
{
  P = error;
  I = I + previous_I;
  D = error - previous_error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  previous_I = I;
  previous_error = error;
}

void motor_control()
{
  // Calculating the effective motor speed:
  int left_motor_speed = initial_motor_speed - PID_value;
  int right_motor_speed = initial_motor_speed + PID_value;

  // The motor speed should not exceed the max PWM value
  constrain(left_motor_speed, 0, 300);
  constrain(right_motor_speed, 0, 300);


  if (error == 7) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 6) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 5) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 4) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 3) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 2) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 1) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 0) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -1) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -2) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -3) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -4) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -5) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -6) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -7) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }

}

//-------------------------------------------------------------------------------------------------------------------Motor Controller voids END-----------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------Intelligent voids BUGUN---------------------------------------------------------------------------------------------------------------------------//

void automatic()
{

g:
  while (!Serial.available())

  {

    {
      read_sensor_values();
      calculate_pid();
      motor_control();
    }

  }

  int com = Serial.read();

  if (com == 'e' || com == 'E')

  {
    end_all();
    digitalWrite(inR1, LOW);
    digitalWrite(inR2, LOW);
    analogWrite(enR, 0);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 0);
    Serial.println("STOPPED");

  }

  else goto g;

}

void ultrasonic()
{

g:
  while (!Serial.available())

  {
    {
      ultrasonic_test();
      if (cm_f > 30) {
        forward();
        Serial.println("forward");
      }
      else if (cm_f < 30 && cm_f > 15) {

        if (cm_l < 40) {
          left();
          Serial.println("right_turn");
          delay(1050);
        }
        else if (cm_r < 40) {
          right();
          Serial.println("left_turn");
          delay(1050);
        }
        else if (cm_l > 45 && cm_r > 45) {
          right();
          Serial.println("left_turn");
          delay(1050);
        }
      }
      else if (cm_f < 14) {


        if (cm_l < 10) {
          backwardleft();
          Serial.println("backward_right_turn");
          delay(1000);
        }
        else if (cm_r < 10) {
          backwardright();
          Serial.println("backward_left_turn");
          delay(1000);
        }
        else {
          reverse();
          delay(1000);
          none();
          delay(150);
          Serial.println("backward");
        }
      }
    }
  }

  int com = Serial.read();

  if (com == 'e' || com == 'E')

  {
    end_all();
    digitalWrite(inR1, LOW);
    digitalWrite(inR2, LOW);
    analogWrite(enR, 0);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 0);
    Serial.println("STOPPED");

  }

  else goto g;

}

//-----------------------------------------------------------------------------------------------------------------------------Intelligent Voids END------------------------------------------------------------------------------------------------------------------//

/*
  void LF_OBJ()
  {

  g:
  while (!Serial.available())

  {

    {
      read_sensor_values_lf_oa();
      calculate_pid();
      motor_control();
    }

  }

  int com = Serial.read();

  if (com == 'e' || com == 'E')

  {
    end_all();
    digitalWrite(inR1, LOW);
    digitalWrite(inR2, LOW);
    analogWrite(enR, 0);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 0);
    Serial.println("STOPPED");

  }

  else goto g;

  }
  //construction closed ;)
  void read_sensor_values_lf_oa()
  {
  sensor[0] = digitalRead(S0);
  sensor[1] = digitalRead(S1);
  sensor[2] = digitalRead(S2);
  sensor[3] = digitalRead(S3);
  sensor[4] = digitalRead(S4);

  Serial.print(sensor[0]);
  Serial.print("_");
  Serial.print(sensor[1]);
  Serial.print("_");
  Serial.print(sensor[2]);
  Serial.print("_");
  Serial.print(sensor[3]);
  Serial.print("_");
  Serial.println(sensor[4]);

  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[4] == 0) && (sensor[4] == 1))
    error = 35;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[4] == 1) && (sensor[4] == 1))
    error = 30;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[4] == 1) && (sensor[4] == 0))
    error = 25;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[4] == 1) && (sensor[4] == 0))
    error = 20;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[4] == 0) && (sensor[4] == 0))
    error = 10;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[4] == 0) && (sensor[4] == 0))
    error = -20;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[4] == 0) && (sensor[4] == 0))
    error = -25;
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[4] == 0) && (sensor[4] == 0))
    error = -30;
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[4] == 0) && (sensor[4] == 0))
    error = -35;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[4] == 0) && (sensor[4] == 0))
  {
    ultrasonic_test();
    if (cm_f > 30) {
      forward();
      Serial.println("forward");
    }
    else if (cm_f < 30 && cm_f > 15) {

      if (cm_l < 40) {
        left();
        Serial.println("right_turn");
        delay(1050);
      }
      else if (cm_r < 40) {
        right();
        Serial.println("left_turn");
        delay(1050);
      }
      else if (cm_l > 45 && cm_r > 45) {
        right();
        Serial.println("left_turn");
        delay(1050);
      }
    }
    else if (cm_f < 14) {


      if (cm_l < 10) {
        backwardleft();
        Serial.println("backward_right_turn");
        delay(1000);
      }
      else if (cm_r < 10) {
        backwardright();
        Serial.println("backward_left_turn");
        delay(1000);
      }
      else {
        reverse();
        delay(1000);
        none();
        delay(150);
        Serial.println("backward");
      }
    }
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[4] == 1) && (sensor[4] == 1))
  {
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
    none();
  }
  }
*/
void loop() {

  if (j == 'a' || j == 'A')

  {
    automatic_start();
    automatic();

  }

  if (j == 'u' || j == 'U')

  {
    ultrasonic_start();
    ultrasonic();

  }

  //if (j == 'v' || j == 'V')

  //{
  // LF_OBJ_start();
  //   LF_OBJ();

  //}

  else if (j == 'm' || j == 'M')

  {


    manual_start();
    {

g:
      while (1)
      {

        if (Serial.available() > 0)
        {
          x = Serial.read();
        }
        Serial.println(x);
        if (x == 'F') {
          forward();
          delay(10);
          x = 0;
        }
        else if (x == 'B') {
          reverse();
          delay(10);
          x = 0;
        }
        else if (x == 'L') {
          left();
          delay(10);
          x = 0;
        }
        else if (x == 'R') {
          right();
          delay(10);
          x = 0;
        }
        else if (x == 'G') {
          forwardleft();
          delay(10);
          x = 0;
        }
        else if (x == 'I') {
          forwardright();
          delay(10);
          x = 0;
        }
        else if (x == 'H') {
          backwardleft();
          delay(10);
          x = 0;
        }
        else if (x == 'J') {
          backwardright();
          delay(10);
          x = 0;
        }
        else if (x == 'Z') {
          digitalWrite(buzzer, HIGH);
          delay(10);
          digitalWrite(buzzer, LOW);
          x = 0;
        }
        else if (x == 'P') {

          if (ang_Gs1 <= 85 && ang_Gs2 >= 70)
          {
            ang_Gs1 = ang_Gs1 + 1;
            ang_Gs2 = ang_Gs2 - 1;
            ser1.write(ang_Gs1);
            ser2.write(ang_Gs2);
            Serial.println("UNgrip");
          }

        }
        else if (x == 'Q') {

          if (ang_Gs1 >= 53 && ang_Gs2 <= 110)
          {
            ang_Gs1 = ang_Gs1 - 1;
            ang_Gs2 = ang_Gs2 + 1;
            ser1.write(ang_Gs1);
            ser2.write(ang_Gs2);
            Serial.println("grip");
          }

        }
        else if (x == 'U') {

          if (ang_UD > 0)
          {
            ang_UD = ang_UD - 1;
            ser3.write(ang_UD);
            Serial.println(ang_UD);
            Serial.println("UP");
          }
        }
        else if (x == 'D') {

          if (ang_UD < 127)
          {
            ang_UD = ang_UD + 1;
            ser3.write(ang_UD);
            Serial.println("DOWN");
          }
        }
        else if (x == 'E') {
          goto l;
        }
        else {
          none();
        }

      }

      if (com == 'e' || com == 'E')

      {

        goto l;

      }

      else if (com == 'F' || com == 'B' || com == 'L' || com == 'R' || com == 'G' || com == 'I' || com == 'H' || com == 'J' || com == 'Z')
        goto g;


    }

  }
  else {
l:
    end_all();
    digitalWrite(13, HIGH);
    digitalWrite(inR1, LOW);
    digitalWrite(inR2, LOW);
    analogWrite(enR, 0);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 0);
    Serial.println("STOPPED");
  }

  while (!Serial.available());
  j = Serial.read();

}

