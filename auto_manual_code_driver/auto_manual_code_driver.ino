#include <LiquidCrystal.h>

LiquidCrystal LCD(4, 11, 12, 12, A2, A3);
int buzzer = 3;
int i;
char j;
int x = 0;
int com = 0;

int maxpower = 140;// max bot speed
int robotspeed = 0;
int maxspeed = 100;// speed limit

int sL = A0;//Sensors
int sR = A1;

int enL = 6; // Motor Driver PWM
int enR = 5;

int inR1 = 7;// Motor Driver Direction
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

void setup() {

  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  LCD.begin(16, 2);
  LCD_start();
  while (!Serial.available());
  j = Serial.read();

}

void forward()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 400);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 400);
}
void none()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 0);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 0);
}
void reverse()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 400);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 400);
}
void left()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 125);
}
void forwardleft()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 125);
}
void backwardleft()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 125);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);
}
void right()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 125);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
}
void forwardright()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 125);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
}
void backwardright()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 125);
}

void LCD_start()

{

  LCD.setCursor(0, 0);
  LCD.print("* WELCOME SIR *");
  delay(1000);
  LCD.setCursor(0, 1);
  LCD.print(" PROJECT : ATOM ");
  delay(2000);
  LCD.clear();
  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem7[] = {'C', 'H', 'E', 'C', 'K', 'I', 'N', 'G', ' ', 'M', 'O', 'T', 'O', 'R', 'S'};
  char displayitem8[] = {'C', 'O', 'M', 'P', 'L', 'E', 'T', 'E', 'D'};

  for (i = 0; i < 15; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem7[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(200);
    LCD.setCursor(15, 0);
    LCD.print("_");
    delay(200);
    LCD.setCursor(15, 0);
    LCD.print(" ");

  }

  for (i = 0; i < 9; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem8[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(9, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(9, 1);
    LCD.print("_");

  }

  for (i = 0; i < 2; i++)

  {

    LCD.clear();
    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem9[] = {'B', 'A', 'S', 'E', 'C', 'O', 'D', 'E'};
  char displayitem10[] = {'U', 'P', 'D', 'A', 'T', 'E', 'D'};

  for (i = 0; i < 8; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem9[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(200);
    LCD.setCursor(8, 0);
    LCD.print("_");
    delay(200);
    LCD.setCursor(8, 0);
    LCD.print(" ");

  }

  for (i = 0; i < 7; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem10[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(7, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(7, 1);
    LCD.print("_");

  }

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem11[] = {'I', 'N', 'T', 'I', 'A', 'L', 'I', 'S', 'I', 'N', 'G'};
  char displayitem12[] = {'S', 'E', 'Q', 'U', 'E', 'N', 'C', 'E'};

  for (i = 0; i < 11; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem11[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 8; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem12[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(8, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(8, 1);
    LCD.print("_");

  }

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

  char displayitem5[] = {'W', 'A', 'I', 'T', 'I', 'N', 'G', ' ', ' ', 'F', 'O', 'R'};
  char displayitem6[] = {'I', 'N', 'S', 'T', 'R', 'U', 'C', 'T', 'I', 'O', 'N'};

  for (i = 0; i < 12; i++)

  {

    LCD.setCursor(i, 0);
    LCD.print(displayitem5[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 11; i++)

  {

    LCD.setCursor(i, 1);
    LCD.print(displayitem6[i]);
    LCD.print("_");
    delay(50);

  }

  for (i = 0; i < 3; i++)

  {

    delay(500);
    LCD.setCursor(11, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(11, 1);
    LCD.print("_");

  }

}


void LCD_final()

{

  LCD.setCursor(0, 0);
  LCD.print("** THANK YOU **");
  delay(1000);
  LCD.setCursor(0, 1);
  LCD.print(" PROJECT : ATOM ");
  delay(2000);

  for (i = 0; i < 2; i++)

  {

    LCD.setCursor(0, i);
    LCD.print(" ");

  }

}

void stopbot()
{
  mpower(-maxpower, -maxpower);
  delay(10);
  mpower(0, 0);
  delay(10);
}

void mpower(int m1, int m2)
{
  if (m1 > 0) {
    digitalWrite(inL1, HIGH);//Direction F
    digitalWrite(inL2, LOW);
  } else {
    digitalWrite(inL1, LOW);//Direction B
    digitalWrite(inL2, HIGH);
    m1 = m1 * -1; //Value to possitive
  }
  analogWrite(enL, m1); //Speed Write as PWM


  if (m2 > 0) {
    digitalWrite(inR1, HIGH);//Direction F
    digitalWrite(inR2, LOW);
  } else {
    digitalWrite(inR1, LOW);//Direction B
    digitalWrite(inR2, HIGH);
    m2 = m2 * -1; //Value to possitive
  }
  analogWrite(enR, m2); //Speed Write as PWM
}

void automatic()

{

g:
  while (!Serial.available())

  {

    {
      int vL = analogRead(A0);// sensor reading
      int vR = analogRead(A1);
      Serial.print(vL);
      Serial.print("_");
      Serial.println(vR);

      int mL = 0;
      int mR = 0;

      if (vL > 400) {
        if (robotspeed > maxspeed) {
          stopbot();
        }
        mL = -maxpower;
        mR = maxpower;
        robotspeed = 0;
      } else if (vR > 400) {
        if (robotspeed > maxspeed) {
          stopbot();
        }
        mL = maxpower;
        mR = -maxpower;
        robotspeed = 0;
      } else if (vL < 400 && vR < 400) {
        mL = maxpower;
        mR = maxpower;
        robotspeed++;
      }
      mpower(mL, mR);
    }

  }

  int com = Serial.read();

  if (com == 'e' || com == 'E')

  {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, LOW);
    analogWrite(enR, 0);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 0);
    LCD_final();
    Serial.println("STOPPED");

  }

  else goto g;

}

void loop() {

  if (j == 'a' || j == 'A' || j == 'W')

  {

    j = 'Z';
    LCD.clear();
    for (i = 0; i < 2; i++)

    {

      LCD.setCursor(0, i);
      LCD.print(" ");

    }

    char displayitem1[] = {'A', 'U', 'T', 'O', 'M', 'A', 'T', 'I', 'C', ' ', 'C', 'T', 'R', 'L'};
    char displayitem2[] = {'A', 'C', 'T', 'I', 'V', 'A', 'T', 'E', 'D'};

    for (i = 0; i < 14; i++)

    {

      LCD.setCursor(i, 0);
      LCD.print(displayitem1[i]);
      LCD.print("_");
      delay(50);

    }

    for (i = 0; i < 9; i++)

    {

      LCD.setCursor(i, 1);
      LCD.print(displayitem2[i]);
      LCD.print("_");
      Serial.println("auto_controlling_activated");
      delay(50);

    }

    for (i = 0; i < 3; i++)

    {

      delay(500);
      LCD.setCursor(9, 1);
      LCD.print(" ");
      delay(500);
      LCD.setCursor(9, 1);
      LCD.print("_");

    }

    automatic();

  }


  else if (j == 'm' || j == 'M' || j == 'U')

  {

    j = 'Z';
    LCD.clear();
    for (i = 0; i < 2; i++)

    {

      LCD.setCursor(0, i);
      LCD.print(" ");

    }

    char displayitem3[] = {'M', 'A', 'N', 'U', 'A', 'L', ' ', 'C', 'O', 'N', 'T', 'R', 'O', 'L'};
    char displayitem4[] = {'A', 'C', 'T', 'I', 'V', 'A', 'T', 'E', 'D'};

    for (i = 0; i < 14; i++)

    {

      LCD.setCursor(i, 0);
      LCD.print(displayitem3[i]);
      LCD.print("_");
      delay(50);

    }

    for (i = 0; i < 9; i++)

    {

      LCD.setCursor(i, 1);
      LCD.print(displayitem4[i]);
      LCD.print("_");
      Serial.println("manual_controlling_activated");
      delay(50);

    }

    for (i = 0; i < 3; i++)

    {

      delay(500);
      LCD.setCursor(9, 1);
      LCD.print(" ");
      delay(500);
      LCD.setCursor(9, 1);
      LCD.print("_");

    }

    manual();

  }

  else

  {

    for (i = 0; i < 2; i++)

    {

      LCD.setCursor(0, i);
      LCD.print(" ");

    }

    char displayitem5[] = {'W', 'A', 'I', 'T', 'I', 'N', 'G', ' ', ' ', 'F', 'O', 'R'};
    char displayitem6[] = {'I', 'N', 'S', 'T', 'R', 'U', 'C', 'T', 'I', 'O', 'N'};

    for (i = 0; i < 12; i++)

    {

      LCD.setCursor(i, 0);
      LCD.print(displayitem5[i]);
      LCD.print("_");
      delay(50);

    }

    for (i = 0; i < 11; i++)

    {

      LCD.setCursor(i, 1);
      LCD.print(displayitem6[i]);
      LCD.print("_");
      delay(50);

    }

    for (i = 0; i < 3; i++)

    {

      delay(500);
      LCD.setCursor(11, 1);
      LCD.print(" ");
      delay(500);
      LCD.setCursor(11, 1);
      LCD.print("_");

    }

  }

  while (!Serial.available());
  j = Serial.read();

}

void manual()
{

g:
  while (1)
  {

    if (Serial.available() > 0)
    {
      x = Serial.read();
    }
    Serial.println(x);
    if (x == 'F') {
      forward();
      delay(10);
      x = 0;
    }
    else if (x == 'B') {
      reverse();
      delay(10);
      x = 0;
    }
    else if (x == 'L') {
      left();
      delay(10);
      x = 0;
    }
    else if (x == 'R') {
      right();
      delay(10);
      x = 0;
    }
    else if (x == 'G') {
      forwardleft();
      delay(10);
      x = 0;
    }
    else if (x == 'I') {
      forwardright();
      delay(10);
      x = 0;
    }
    else if (x == 'H') {
      backwardleft();
      delay(10);
      x = 0;
    }
    else if (x == 'J') {
      backwardright();
      delay(10);
      x = 0;
    }
    else {
      none();
    }
  }


  if (com == 'f' || com == 'F' || com == 'b' || com == 'B' || com == 'l' || com == 'L' || com == 'r' || com == 'R' || com == 'u' || com == 'U' || com == 'y' || com == 'Y' || com == 'w' || com == 'W' || com == '7' || com == '8' || com == '9' || com == 'p' || com == 'P')

    goto g;

  else if (com == 'u' || com == 'w' || com == 'E')

  {

    digitalWrite(inR1, LOW);
    digitalWrite(inR2, LOW);
    analogWrite(enR, 0);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 0);
    LCD_final();
    Serial.println("STOPPED");

  }

}

