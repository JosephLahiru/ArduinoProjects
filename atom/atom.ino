void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {

  char id = Serial.read();
  if (id == 'a') {
    digitalWrite(13, HIGH);
  }
  if (id == 'b') {
    digitalWrite(13, LOW);
  }

}
