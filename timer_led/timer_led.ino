int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  for (int i = 0; i < 5000; i+10) {
    digitalWrite(led,HIGH);
    delay(i);
    digitalWrite(led,LOW);
    delay(i);
  }
    for (int i = 5000; i > 5000; i-10) {
    digitalWrite(led,HIGH);
    delay(i);
    digitalWrite(led,LOW);
    delay(i);
  }
}
