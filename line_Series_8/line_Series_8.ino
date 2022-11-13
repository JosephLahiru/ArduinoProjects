/*moratuwa university*/

#include "DualVNH5019MotorShield.h"
#include <QTRSensors.h>
#define NUM_SENSORS             6  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             2  // emitter is controlled by digital pin 2
#define GUARD_GAIN   10.0
#define led 26
#define go 24
QTRSensorsAnalog qtra((unsigned char[]) {A1, A2, A3, A4, A5, A6,}, NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
DualVNH5019MotorShield md;

unsigned int sensorValues[NUM_SENSORS];
unsigned int pidValues[NUM_SENSORS];
/////////////////////////////////////////////////////////////////
float Kp = 15;
float Ki = 0;
float Kd = 150;
float pTerm, iTerm, dTerm, integrated_error, last_error;
float error = 0;
int pidSpeed = 0;
int leftSpeed = 0;
int rightSpeed = 0;
int baseSpeed = 320;
int start;
//////////////////////////////////////////////////////////////////
void setup() {
  Serial3.begin(115200);
  md.init();
  pinMode(go, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  delay(500);
  calibratePanel();
  delay(100);
  digitalWrite(led, HIGH);
  start = digitalRead(go);
  while (start == HIGH) {
    start = digitalRead(go);
    digitalWrite(led, HIGH);
  }
  digitalWrite(led, LOW);
  delay(1000);
}

void loop() {
  pid();
  leftSpeed = constrain((baseSpeed + pidSpeed), -400, 400);
  rightSpeed = constrain((baseSpeed - pidSpeed), -400, 400);
  md.setSpeeds(leftSpeed, rightSpeed);
}

void pid() {
  unsigned int position = qtra.readLine(sensorValues);
  int sum = 0;
  for (unsigned char i = 0; i < NUM_SENSORS; i++) {
    if (sensorValues[i] >= 450) {
      pidValues[i] = 0;
    }
    else if (sensorValues[i] < 450) {
      sum++;
      pidValues[i] = 1;
    }
  }
  error = 0;
  error = error - (90 * pidValues[0]);
  error = error - (25 * pidValues[1]);
  error = error - (10 * pidValues[2]);
  error = error + (10 * pidValues[5]);
  error = error + (25 * pidValues[6]);
  error = error + (90 * pidValues[7]);
  error = error / sum;
  pTerm = Kp * (error);
  integrated_error += error;
  iTerm = Ki * constrain(integrated_error, -GUARD_GAIN, GUARD_GAIN);
  dTerm = Kd * (error - last_error);
  last_error = error;
  pidSpeed = (pTerm + dTerm);
  if (sum == 0) {
        md.setBrakes(400,400);
        delay(5000);
  }
}

void calibratePanel() {
  for (int i = 0; i < 200; i++)
  {
    qtra.calibrate();
  }
}
