int buzzer = 12;
int head_light = 13;

int enL = 6;
int enR = 5;

int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

int trigPin = 3;
int echoPin = 4;
float pingTime;
float cm;

int x = 0;

void setup() {
  Serial.begin(9600);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(head_light, OUTPUT);
  pinMode(trigPin, OUTPUT);
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
void right()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 125);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
}
void ultra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH);
  pingTime = pingTime / 29;
  cm = pingTime / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(10);
}

void loop()
{
  ultra();

  if (cm > 10)
  {
    if (Serial.available() > 0) {
      x = Serial.read();

      if (x == 'F') {
        //forward();
        Serial.println("forward");
        delay(10);
        x = 'N';
      }
      else if (x == 'B') {
        //reverse();
        Serial.println("backward");
        delay(10);
        x = 'N';
      }
      else if (x == 'L') {
        left();
        delay(10);
        x = 'N';
      }
      else if (x == 'R') {
        right();
        x = 'N';
      }
      else {
        none();
      }
    }
  }
  else {
    none();
  }
}
