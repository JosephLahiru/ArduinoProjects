int led = 5;
int s1 = 0;
int s2 = 0;

void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);

}

void loop() {

  s1 = analogRead(A0);
  s2 = analogRead(A1);

  if (s1 > 500 && s2 > 500) {

    digitalWrite(led, HIGH);
    Serial.println("water detected");

  }
  else {
    digitalWrite(led, LOW);
    Serial.println("water not detected");
  }

}
