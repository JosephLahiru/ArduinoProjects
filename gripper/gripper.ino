#include <Servo.h>

Servo servo1;
Servo servo2;

int x=0;
int pos = 0;   

void setup() {
  servo1.attach(5);  
  servo2.attach(6);
  servo1.write(0);
  servo2.write(180);
}

void loop() {
  
  
  for (pos = 0; pos <= 180; pos += 1) { 
   
    servo1.write(pos); 
    servo2.write(180-pos);            
    delay(10);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    
    servo1.write(pos); 
    servo2.write(180-pos);            
    delay(10);                      
  }
}

