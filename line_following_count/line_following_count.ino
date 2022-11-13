/*team omega corrected by amres*/

float Kp = 1, Ki = 0.000001, Kd = 1.8;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int sensor[5] = {0, 0, 0, 0, 0};
int initial_motor_speed = 200;

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

int enL = 6;
int enR = 5;

int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

int S0 = A0;
int S1 = A1;
int S2 = A2;
int S3 = A3;
int S4 = A4;

void setup()
{
  Serial.begin(9600); //Enable Serial Communications
  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  digitalWrite(13, HIGH);
  delay(3000);

}

void loop()
{
  read_sensor_values();
  calculate_pid();
  motor_control();
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


