/*
  coded by AMRES
  Project : ATOM
  Date : 2/18/2019
  raspberry pi synced robot
*/

float Kp = 1, Ki = 0.000001, Kd = 1.8;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int sensor[7] = {0, 0, 0, 0, 0, 0, 0};
int initial_motor_speed = 220;
int error_all_black;

void read_sensor_values(void);

int x = 0;
int t = 50;

//IR sensors
int S0 = 2;
int S1 = 3;
int S2 = 4;
int S3 = 5;
int S4 = 6;
int S5 = 7;
int S6 = 8;

int buzzer = 11;

void setup() {

  Serial.begin(9600);
  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  sensor[0] = digitalRead(S0);
  sensor[1] = digitalRead(S1);
  sensor[2] = digitalRead(S2);
  sensor[3] = digitalRead(S3);
  sensor[4] = digitalRead(S4);
  sensor[5] = digitalRead(S5);
  sensor[6] = digitalRead(S6);

  /*Serial.print(sensor[0]);
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
    Serial.println(sensor[6]);*/

  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 1)) {
    error = 40;
    Serial.println(40);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 1) && (sensor[6] == 1)) {
    error = 30;
    Serial.println(30);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 1) && (sensor[6] == 0)) {
    error = 25;
    Serial.println(25);
    delay(50);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 1) && (sensor[6] == 0)) {
    error = 20;
    Serial.println(20);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = 15;
    Serial.println(15);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = 10;
    Serial.println(10);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = 0;
    Serial.println(0);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -10;
    Serial.println(-10);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -15;
    Serial.println(-15);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -20;
    Serial.println(-20);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -25;
    Serial.println(-25);
    delay(t);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -30;
    Serial.println(-30);
    delay(t);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -40;
    Serial.println(-40);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    {
      //Serial.println(0);
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(t);
    }
  }
}

