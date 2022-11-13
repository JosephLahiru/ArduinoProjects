#include <LiquidCrystal.h>
LiquidCrystal LCD(45, 44, 43, 42, 41, 40);
char x;
int i;

void setup() {
  Serial.begin(9600);
  LCD.begin(16,2);
  

}

void loop() {
  
while(!Serial.available());
x=Serial.read(); 
if(x=='1'){
  LCD.clear();
}
else{
LCD.print(x);
delay(100);
}
}
