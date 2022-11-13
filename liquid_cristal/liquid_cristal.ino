/*
  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

*/

// include the library code:
#include <LiquidCrystal.h>

int Contrast = 1;
int light = 10;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {

  analogWrite(9, Contrast);
  digitalWrite(light, HIGH);

  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 1);

  lcd.print("hello, world!");
}

void loop() {
  lcd.print("hello, world!");
}

