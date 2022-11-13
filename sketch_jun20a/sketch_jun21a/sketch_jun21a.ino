void setup() {
  pinMode ( 13,OUTPUT);

}

void loop() {
  tone(13,870);
  delay(50);
  noTone(13);
  delay(50);

}
