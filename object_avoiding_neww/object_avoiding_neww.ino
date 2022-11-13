
int trigPin_f = A0;
int echoPin_f = A1;
float pingTime_f;
float cm_f = 0;
int trigPin_l = A2;
int echoPin_l = A3;
float pingTime_l;
float cm_l = 0;
int trigPin_r = A5;
int echoPin_r = A4;
float pingTime_r;
float cm_r = 0;
// Motor Driver PWM
int enL = 6;
int enR = 5;
// Motor Driver Direction
int inR1 = 7;
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

void setup() {
  pinMode(trigPin_f, OUTPUT);
  pinMode(trigPin_l, OUTPUT);
  pinMode(trigPin_r, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  Serial.begin(9600);
}

void ultrasonic_test() {

  digitalWrite(trigPin_f, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_f, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_f, LOW);
  pingTime_f = pulseIn(echoPin_f, HIGH);
  pingTime_f = pingTime_f / 29;
  cm_f = pingTime_f / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_f);
  Serial.println(" cm_f");
  delay(10);

  digitalWrite(trigPin_l, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_l, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_l, LOW);
  pingTime_l = pulseIn(echoPin_l, HIGH);
  pingTime_l = pingTime_l / 29;
  cm_l = pingTime_l / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_l);
  Serial.println(" cm_l");
  delay(10);

  digitalWrite(trigPin_r, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_r, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_r, LOW);
  pingTime_r = pulseIn(echoPin_r, HIGH);
  pingTime_r = pingTime_r / 29;
  cm_r = pingTime_r / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_r);
  Serial.println(" cm_r");
  delay(10);

}

void forward()
{

  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enR, 300);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 300);
}

void backward()
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
  analogWrite(enR, 300);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 300);
}
void backwardleft()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 150);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 300);
}
void right()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 300);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enL, 300);
}
void backwardright()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, HIGH);
  analogWrite(enR, 300);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, HIGH);
  analogWrite(enL, 150);
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
void loop() {
  ultrasonic_test();
  if (cm_f > 30) {
    forward();
    Serial.println("forward");
  }
  else if (cm_f < 30 && cm_f > 15) {

    if (cm_l < 40) {
      right();
      Serial.println("right_turn");
      delay(1050);
    }
    else if (cm_r < 40) {
      left();
      Serial.println("left_turn");
      delay(1050);
    }
    else if (cm_l > 45 && cm_r > 45) {
      left();
      Serial.println("left_turn");
      delay(1050);
    }
  }
  else if (cm_f < 14) {
     
    
   if (cm_l < 10) {
      backwardright();
      Serial.println("backward_right_turn");
      delay(1000);
    }
    else if (cm_r < 10) {
      backwardleft();
      Serial.println("backward_left_turn");
      delay(1000);
    }
    else{
      backward();
      delay(1000);
      none();
      delay(150);
      Serial.println("backward");
    }
  }
}
