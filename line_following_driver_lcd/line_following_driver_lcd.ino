#include <LiquidCrystal.h>

LiquidCrystal LCD(A2, A3, A4, A5, A6, A7);

float Kp = 1, Ki = 0.000001, Kd = 1.8;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int sensor[5] = {0, 0, 0, 0, 0};
int initial_motor_speed = 190;
int error_all_black;

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

int x = 0;
int j = 0;
int com = 0;

int S0 = A8;
int S1 = A9;
int S2 = A10;
int S3 = A11;
int S4 = A12;
int buzzer = A13;
int echo = 3;

int enL = 6; // Motor Driver PWM
int enR = 5;

int inR1 = 7;// Motor Driver Direction
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;
int i=0;
int cm = 0;

void setup() {

  Serial.begin(9600);
  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echo, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  LCD.begin(16, 2);
  LCD_start();
  while (!Serial.available());
  j = Serial.read();

}

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
  analogWrite(enR, 150);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 300);
}
void forwardleft()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 300);
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
  analogWrite(enL, 300);
}
void right()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 300);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 150);
}
void forwardright()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 150);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 300);
}
void backwardright()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 300);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 150);
}

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

void read_sensor_values()
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
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[4] == 1) && (sensor[4] == 1))
  {

  }
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


  if (error == 35) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 30) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 25) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 20) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, HIGH);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == 10) {

    digitalWrite(inR1, HIGH);
    digitalWrite(inR2, LOW);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -20) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -25) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -30) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -35) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }

}

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

void loop() {

  if (j == 'a' || j == 'A')

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

    automatic();

  }

  else if (j == 'm' || j == 'M')

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

    manual();

  }

  else

  {

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

  while (!Serial.available());
  j = Serial.read();

}

void manual()

{

  char com;
  while (!Serial.available());
g:
  com = Serial.read();
  if (com == 'f' || com == 'F')

  {

    while (!Serial.available())

    {
      forward();
      delay(10);
      x = 0;
    }

  }

  else if (com == 'b' || com == 'B')

  {

    while (!Serial.available())

    {
      reverse();
      delay(10);
      x = 0;
    }

  }

  else if (com == 'l' || com == 'L')

  {

    while (!Serial.available())

    {
      left();
      delay(10);
      x = 0;
    }

  }

  else if (com == 'r' || com == 'R')

  {

    while (!Serial.available())

    {
      right();
      delay(10);
      x = 0;
    }

  }




  if (com == 'f' || com == 'F' || com == 'b' || com == 'B' || com == 'l' || com == 'L' || com == 'r' || com == 'R' || com == 'u' || com == 'U' || com == 'y' || com == 'Y' || com == 'w' || com == 'W' || com == '7' || com == '8' || com == '9')

    goto g;

  else if (com == 'e' || com == 'E')

  {

    digitalWrite(13, HIGH);
    digitalWrite(inR1, LOW);
    digitalWrite(inR2, LOW);
    analogWrite(enR, 0);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 0);
    LCD_final();
    Serial.println("STOPPED");

  }

}


