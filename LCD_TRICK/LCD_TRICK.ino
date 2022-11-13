#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// make some custom characters:
byte heart[8] = {
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01111,
  0b00111,
  0b00001
};
byte beat[8] = {
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b11110,
  0b11100,
  0b10000
};
void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, heart);
  lcd.createChar(1, beat);

  lcd.setCursor(0,0); 
  lcd.write(0);
  lcd.setCursor(1,0); 
  lcd.write(1);

}

void loop(){
  
}

