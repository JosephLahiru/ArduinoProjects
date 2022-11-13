#include <LiquidCrystal.h>

char data = 0;                //Variable for storing received data
LiquidCrystal LCD(A0, A1, A2, A3, A4, A5);

void setup()
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
  LCD.begin(16, 2);
}
void loop()
{
  if (Serial.available() > 0) // Send data only when you receive data:
  {
    data = Serial.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line
    if (data == '1')  {         //Checks whether value of data is equal to 1
      digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
      LCD.print("led_on");
    }
    else if (data == '0')   {   //Checks whether value of data is equal to 0
      digitalWrite(13, LOW);   //If value is 0 then LED turns OFF
      LCD.print("led_on");
    }
  }

}
