String x;

void setup() {
  Serial.begin(9600);
  Serial.println("started");

}

void loop() {
  while (1)
  {
    if (Serial.available() > 0)
    {
      x = Serial.read();
      //Serial.println("Serial Available");
    }
    Serial.println(x);
  }
}
