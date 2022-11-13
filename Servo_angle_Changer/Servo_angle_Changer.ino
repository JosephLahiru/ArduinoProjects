#include <Servo.h>

Servo ser1;
Servo ser2;
Servo ser3;

int ang_UD = 10;
int ang_Gs1 = 53;
int ang_Gs2 = 110;

char x = 0;

void setup() {
  Serial.begin(9600);
  ser1.attach(9);//BLACK
  ser2.attach(10);//BLUE
  ser3.attach(11);//UP DOWN

  ser3.write(ang_UD);
  ser1.write(ang_Gs1);
  ser2.write(ang_Gs2);
  Serial.print("Gripper_Ready!");

}

void loop()
{
  while (1)
  {

    if (Serial.available() > 2)
    {
      x = Serial.read();

      if (x == 'D')
      {
        if (ang_UD < 127)
        {
          ang_UD = ang_UD + 1;
          ser3.write(ang_UD);
          Serial.println("DOWN");
        }

      }
      else if (x == 'U')
      {
        if (ang_UD > 0)
        {
          ang_UD = ang_UD - 1;
          ser3.write(ang_UD);
          Serial.println(ang_UD);
          Serial.println("UP");
        }
      }
      else if (x == 'P')
      {
        if (ang_Gs1 <= 85 && ang_Gs2 >= 70)
        {
          ang_Gs1 = ang_Gs1 + 1;
          ang_Gs2 = ang_Gs2 - 1;
          ser1.write(ang_Gs1);
          ser2.write(ang_Gs2);
          Serial.println("UNgrip");
        }

      }
      else if (x == 'Q')
      {
        if (ang_Gs1 >= 53 && ang_Gs2 <= 110)
        {
          ang_Gs1 = ang_Gs1 - 1;
          ang_Gs2 = ang_Gs2 + 1;
          ser1.write(ang_Gs1);
          ser2.write(ang_Gs2);
          Serial.println("grip");
        }
      }
    }
  }
}


