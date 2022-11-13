int trigPin = 42;
int echoPin = 43;
float pingTime;
float cm;

void setup() {

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
}

void loop() {
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
