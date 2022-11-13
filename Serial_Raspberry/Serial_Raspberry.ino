void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("Hello World");
}

void flash(int n) {
  Serial.print("Flash times:");
  Serial.println(n);
  while (true) {
    Serial.println(123);
  }
}

void loop() {

  Serial.println("Hello World");
  if (Serial.available()) {
    flash(Serial.parseInt());
    Serial.flush();
  }
}
