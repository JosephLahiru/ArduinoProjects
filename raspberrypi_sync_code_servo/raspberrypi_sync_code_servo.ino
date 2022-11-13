/*
  coded by AMRES
  Project : ATOM
  Date : 2/18/2019
  raspberry pi synced robot
*/

#include<Servo.h>

float Kp = 1, Ki = 0.000001, Kd = 1.8;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int sensor[7] = {0, 0, 0, 0, 0, 0, 0};
int initial_motor_speed = 140;
int error_all_black;

void readSensorValues(void);
void calculatePID(void);
void motorControl(void);

// Motor Driver PWM
int enL = 11;
int enR = 10;

// Motor Driver Direction
int inR1 = A4;
int inR2 = A5;
int inL1 = A2;
int inL2 = A3;

bool light = 0;

Servo ser1;
Servo ser2;

int x = 0;
int t = 1;

int posUD = 90;
int posLR = 90;

//IR sensors
int S0 = 2;
int S1 = 3;
int S2 = 4;
int S3 = 5;
int S4 = 6;
int S5 = 7;
int S6 = 8;

int engine = 12;

int buzzer = A0;

void setup() {
  Serial.begin(9600);
  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(13, OUTPUT);
  ser1.attach(9);
  ser2.attach(A1);
  ser1.write(posUD);
  ser2.write(posLR);
}

void calculatePID()
{
  P = error;
  I = I + previous_I;
  D = error - previous_error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  previous_I = I;
  previous_error = error;
}

void motorControl()
{
  // Calculating the effective motor speed:
  int left_motor_speed = initial_motor_speed - PID_value;
  int right_motor_speed = initial_motor_speed + PID_value;

  // The motor speed should not exceed the max PWM value
  constrain(left_motor_speed, 0, 300);
  constrain(right_motor_speed, 0, 300);

  if (error == 40) {

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
  else if (error == 15) {

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
  else if (error == -10) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }
  else if (error == -15) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
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
  else if (error == -40) {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, HIGH);
    analogWrite(enR, right_motor_speed);
    digitalWrite(inL1, HIGH);
    digitalWrite(inL2, LOW);
    analogWrite(enL, left_motor_speed);
  }

}

void readSensorVal()
{
  sensor[0] = digitalRead(S0);
  sensor[1] = digitalRead(S1);
  sensor[2] = digitalRead(S2);
  sensor[3] = digitalRead(S3);
  sensor[4] = digitalRead(S4);
  sensor[5] = digitalRead(S5);
  sensor[6] = digitalRead(S6);

  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 1)) {
    error = 40;
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 1) && (sensor[6] == 1)) {
    error = 30;
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 1) && (sensor[6] == 0)) {
    error = 25;
    delay(50);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 1) && (sensor[6] == 0)) {
    error = 20;
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = 15;
    //Serial.println(15);
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = 10;
    //Serial.println(10);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = 0;
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -10;
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -15;
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -20;
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -25;
    delay(t);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -30;
    delay(t);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    error = -40;
    delay(t);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) && (sensor[6] == 0)) {
    {
      //Serial.println(0);
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
    }
  }
}

void loop() {
G:
  if (Serial.available() > 0) {
    x = Serial.read();
  }
  if ( x == 'v') {
    digitalWrite(engine,HIGH);
    delay(2000);
    while (1) {
      readSensorVal();
      calculatePID();
      motorControl();
      if (Serial.available() > 0) {
        x = Serial.read();
      }
      if (x == 'b') {
        x = 0;
        digitalWrite(engine,LOW);
        goto G;
      }
    }
  }
  else if (x == 'i') {
    //UpDOWN servo UP
    ser1.write(posUD);
    delay(15);

    if (posUD >= 180) {
      posUD = 180;
    }
    else {
      posUD = posUD + 1;
    }
    x = 0;
  }
  else if (x == 'k') {
    //UpDOWN servo DOWN
    ser1.write(posUD);
    delay(15);

    if (posUD <= 55) {
      posUD = 55;
    }
    else {
      posUD = posUD - 1;
    }
    x = 0;
  }
  else if (x == 'j') {
    //LeftRight servo LEFT
    ser2.write(posLR);
    delay(15);

    if (posLR >= 145) {
      posLR = 145;
    }
    else {
      posLR = posLR + 1;
    }
    x = 0;
  }
  else if (x == 'l') {
    //LeftRight servo RIGHT
    ser2.write(posLR);
    delay(15);
    if (posLR <= 35) {
      posLR = 35;
    }
    else {
      posLR = posLR - 1;
    }
    x = 0;
  }
  else if (x == 'f' && light == 0) {
    digitalWrite(13, HIGH);
    light = 1;
    x=0;
  }
  else if (x == 'f' && light == 1) {
    digitalWrite(13, LOW);
    light = 0;
    x=0;
  }
}

