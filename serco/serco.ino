#include <Servo.h>

Servo ser1;
Servo ser2;

int pos = 0;

char x = 0;

void setup() {
  Serial.begin(9600);
  ser1.attach(9);
  ser2.attach(10);
}

void loop()
{
 /* while (1)
  {

    if (Serial.available() > 0)
    {
      x = Serial.read();
   
    if (x == 'F') {
     
        ser1.write(100);
        
     
    }
    else if (x == 'B') {
     
        ser1.write(50);
     
    }
    else if (x == 'C') {
      
        ser2.write(10);
       
    }
    else if (x == 'D') {
      
        ser2.write(100);
      
    }
  }
}*/
 ser1.write(85);//black 56 middle 56- 85 ungrip
 ser2.write(70);//blue 105 middle 105-70 ungrip
 delay(2000);
 ser1.write(56);//black 56 middle 56- 85 ungrip
 ser2.write(105);//blue 105 middle 105-70 ungrip
 delay(2000);
}
