int buzzer = 3;
int head_light = 4;

int enL = 6;
int enR = 5;

int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

int x = 0;

void setup() {
  Serial.begin(9600);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(head_light,OUTPUT);
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
void horn()
{
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
}
void em_break()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);
}
void loop()
{
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
    else if (x == 'E') {
      horn();
      delay(10);
      x = 0;
    }
    else if (x == 'X') {
      em_break();
      delay(50);
      x = 0;
      none();
    }
    else {
      none();
    }
  }
}
