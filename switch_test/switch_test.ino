int led = 13;
//int swi = 9;
int state = 0;

int trigPin_f = A10;
int echoPin_f = A11;
float pingTime_f;
float cm_f = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin_f, OUTPUT);
  pinMode(led, OUTPUT);
 // pinMode(swi, INPUT);

}

void distance() {
  
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

}

void loop() {
  distance();
  Serial.println(state);
  
  if (cm_f<15 && state == 0)
  {
    digitalWrite(led, HIGH);
    state = 1;
    delay(1000);
  }
  else if (cm_f<15 && state == 1)
  {
    digitalWrite(led, LOW);
    state = 0;
    delay(1000);
  }
}
