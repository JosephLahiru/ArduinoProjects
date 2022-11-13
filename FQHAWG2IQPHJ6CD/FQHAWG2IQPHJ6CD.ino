/*
  Avoider Robot, Bluetooth;Serial Controlled Robot, LCD
  Modified By: Dimas Sheldon S.W.
  dim.sheldon@gmail.com
  July 17th, 2016

  -Arduino Uno
  -Ultrasonic censor HC-SR04 x3
  -DFRobot L298P Motor Driver
  -LCD 16x2 with I2C
  -HC-05 Bluetooth Module

  <<I2C Pins>>:
  VCC to Arduino 5V pin
  GND to Arduino GND pin
  SDA to Arduino A4 pin
  SCL to Arduino A5 pin

  <<HC05 Bluetooth Module>>
  HC05 RX pin to Arduino TX pin
  HC05 TX pin to Arduino RX pin
  (When uploading the codes, you have to release these pins first)

  every VCC pins goes to Arduino 5V pin, also the GND pins
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum censor distance is rated at 400-500cm.

LiquidCrystal_I2C lcd(0x38, 16, 2);
NewPing sonar(2, 3, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonarFL(A2, A3, MAX_DISTANCE);
NewPing sonarFR(A0, A1, MAX_DISTANCE);
unsigned int pingSpeed = 50; // How frequently are we going to send out a ping (in milliseconds). 50ms would be 20 times a second.
unsigned long pingTimer;     // Holds the next ping time.
double distance = 50;
double distanceFL = 50;
double distanceFR = 50;
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  //return microseconds / 29 / 2;
  return microseconds / 10; //default 58
}

int LED = 13;
int Buzzer = 10;
char command = '\0';

//MotorSetting; Using DFRobot L298 2A Motor Driver
int MR = 4;
int EnR = 5;
int EnL = 6;
int ML = 7;
int pwm_speed;
int speedVal = 255;

void Forward() {
  digitalWrite(ML, HIGH);
  digitalWrite(MR, HIGH);
  analogWrite(EnL, speedVal);
  analogWrite(EnR, speedVal);
}

void Backward() {
  digitalWrite(ML, LOW);
  digitalWrite(MR, LOW);
  analogWrite(EnL, speedVal);
  analogWrite(EnR, speedVal);
}

void Left() {
  digitalWrite(ML, LOW);
  digitalWrite(MR, HIGH);
  analogWrite(EnL, speedVal - 105);
  analogWrite(EnR, speedVal);
}

void Right() {
  digitalWrite(ML, HIGH);
  digitalWrite(MR, LOW);
  analogWrite(EnL, speedVal);
  analogWrite(EnR, speedVal - 105);
}

void Stop() {
  analogWrite(EnL, 0);
  analogWrite(EnR, 0);
}

void test_speed() {
  // constrain speed value to between 0-255
  if (speedVal > 250) {
    speedVal = 255;
    Serial.println(" MAX ");
  }
  if (speedVal < 0) {
    speedVal = 0;
    Serial.println(" MIN ");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(MR, OUTPUT);
  pinMode(EnR, OUTPUT);
  pinMode(EnL, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  lcd.init();
  delay(250);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
  }
  switch (command) {
    case '1':
      uint8_t i;
      distance  = sonar.ping_cm();
      distanceFL  = sonarFL.ping_cm();
      distanceFR  = sonarFR.ping_cm();
      Forward();
      if (distanceFL > 3) {
        if ( distanceFL < 20) {
          Right();
          delay(250);
          Forward();
        }
      }
      if (distanceFR > 3) {
        if (distanceFR < 20) {
          Left();
          delay(250);
          Forward();
        }
      }
      while (distance < 40) {
        Forward();
        distance  = sonar.ping_cm();
        if (distance > 2) {
          while (distance < 25) {
            tone(Buzzer, 900);
            Stop();
            delay(500);
            Backward();
            delay(250);
            distance  = sonar.ping_cm();
            distanceFL = sonarFL.ping_cm();
            distanceFR = sonarFR.ping_cm();
            if (distanceFL > 10) {
              Left();
              delay(250);
              distanceFL = sonarFL.ping_cm();
            }
            else if (distanceFR > 10) {
              Right();
              delay(250);
              distanceFR = sonarFR.ping_cm();
            }
            /*else {
              Drive("Backward");
              delay(250);
              }*/
          }
        }
      }
      break;
    case 'w'||'W':
      Serial.println("Moving Forward\r\n");
      Forward();
      command = '\0';
      break;
    case 's':
      Serial.println("Moving Backward\r\n");
      Backward();
      command = '\0';
      break;
    case 'a':
      Serial.println("Turning Left\r\n");
      Left();
      command = '\0';
      break;
    case 'd':
      Serial.println("Turning Right\r\n");
      Right();
      command = '\0';
      break;
    case 'q':
      Serial.println("Stop\r\n");
      Stop();
      command = '\0';
      break;
    case 'x':
      Serial.println("LEDon\r\n");
      digitalWrite(LED, HIGH);
      command = '\0';
      break;
    case 'z':
      Serial.println("LEDoff\r\n");
      digitalWrite(LED, LOW);
      command = '\0';
      break;
    case '2':
      lcd.backlight();
      lcd.setCursor (2, 0);
      lcd.print("INSTRUCTABLES");
      lcd.setCursor(0, 1);
      lcd.print("Multitasking Rbt");
      command = '\0';
      break;
    case'0': //
      Serial.println("Waiting for Command...");
      digitalWrite(LED, LOW);
      lcd.clear();
      lcd.noBacklight();
      command = '\0';
      break;
    case 'e':
      speedVal = speedVal - 5;
      test_speed();
      Serial.println(speedVal);
      command = '\0';
      break;
    case 'r':
      speedVal = speedVal + 5;
      test_speed();
      Serial.println(speedVal);
      command = '\0';
      break;
  }
}
