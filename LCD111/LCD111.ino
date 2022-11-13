#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("hello, world!");
  lcd.setCursor(0,1);
  lcd.print("ATOM");
}

void loop() {
  lcd.setCursor(0,1);
for(int positionCounter=0;positionCounter<13;positionCounter++){
  lcd.scrollDisplayLeft();
  delay(150);
}
for(int positionCounter=0;positionCounter<29;positionCounter++){
  lcd.scrollDisplayRight();
  delay(150);
}
for(int positionCounter=0;positionCounter<16;positionCounter++){
  lcd.scrollDisplayLeft();
  delay(150);
}
delay(1000);
}
