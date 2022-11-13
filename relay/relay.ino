void setup() {
  Serial.begin(9600);

}

void loop() {
  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(9,LOW);
  delay(1000);
}
