/*done by amres*/
int x = 0;
int j = 0;
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
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
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
    Serial.println("STOPPED");

  }

  else goto g;

}




void loop() {

  if (j == 'a' || j == 'A')

  {

    automatic();

  }


  else if (j == 'm' || j == 'M' || j == 'U')

  {

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
    else if (x == 'E') {
      goto l;
    }
    else {
      none();
    }

  }

  if (com == 'e' || com == 'E')

  {

    goto l;

  }

  else if (com == 'F' || com == 'B' || com == 'L' || com == 'R' || com == 'G' || com == 'I' || com == 'H' || com == 'J')
    goto g;


}

  }
  else {
    l:
    digitalWrite(13, HIGH);
    digitalWrite(inR1, LOW);
    digitalWrite(inR2, LOW);
    analogWrite(enR, 0);
    digitalWrite(inL1, LOW);
    digitalWrite(inL2, LOW);
    analogWrite(enL, 0);
    Serial.println("STOPPED");
  }

  while (!Serial.available());
  j = Serial.read();

}



