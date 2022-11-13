/*done by amres last code*/

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

void ultrasonic() {

}



void loop() {

  if (j == 'a' || j == 'A')

  {

    automatic();

  }


  else if (j == 'm' || j == 'M' || j == 'U')

  {

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
          digitalWrite(buzzer,HIGH);
          delay(10);
          digitalWrite(buzzer,LOW);
          x = 0;
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

      else if (com == 'F' || com == 'B' || com == 'L' || com == 'R' || com == 'G' || com == 'I' || com == 'H' || com == 'J'|| com == 'Z')
        goto g;


    }

  }
  else {
l:
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



