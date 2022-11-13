int dr = 5;

void setup() {
  pinMode(dr, OUTPUT);

}

void loop() {
  digitalWrite(dr, HIGH);
  delay(5);
  digitalWrite(dr, LOW);
  delay(5);
}
