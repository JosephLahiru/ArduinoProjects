#include <Servo.h>

Servo ser1;
Servo ser2;
Servo ser3;

char x = 0;

void setup() {
  Serial.begin(9600);
  ser1.attach(9);//BLACK
  ser2.attach(10);//BLUE
  ser3.attach(11);//UP DOWN
  
  ser3.write(10);
  ser1.write(53);
  ser2.write(110);
  Serial.print("Gripper_Ready!");

}

void loop()
{
  while (1)
  {

    if (Serial.available() > 0)
    {
      x = Serial.read();

      if (x == 'P') {

        ser1.write(85);//black 56 middle 56- 85 ungrip
        ser2.write(70);//blue 105 middle 105-70 ungrip
        Serial.println("un_grip");


      }
      else if (x == 'Q') {

        ser1.write(53);//black 56 middle 56- 85 ungrip
        ser2.write(110);//blue 105 middle 105-70 ungrip
        Serial.println("grip");

      }
      else if (x == 'U') {

        ser3.write(10);
        Serial.println("UP");

      }
      else if (x == 'D') {

        ser3.write(100);
        Serial.println("DOWN");

      }
    }
  }
}
