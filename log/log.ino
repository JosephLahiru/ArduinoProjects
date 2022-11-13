int k;

int trigPin = 3;
int echoPin = 4;
float pingTime;
float cm;

int enL = 6;
int enR = 5;

int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

void setup()
{
  Serial.begin(9600);
  delay(2000);
  pinMode(trigPin, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
}

void forward()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 255);
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
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 255);
}
void left()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 255);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 0);
}
void right()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 0);
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
}

void loop() {

  while (1)
  {
    if (Serial.available() > 0) {
      k = Serial.read();
    }
    ultra();
    if (cm > 25)
    {
      if (k == 'F') {
        forward();
        Serial.println("forward");
        delay(10);
        k = 0;
        none();
      }
    }
    if (cm < 25) {
      Serial.println("object detected forward blocked");
    }
    if (cm > 0) {
      if (k == 'B') {
        reverse();
        Serial.println("backward");
        delay(10);
        k = 0;
        none();
      }
      else if (k == 'L') {
        left();
        Serial.println("left");
        delay(10);
        k = 0;
        none();
      }
      else if (k == 'R') {
        right();
        Serial.println("Right");
        delay(10);
        k = 0;
        none();
      }
    }
  }
}
