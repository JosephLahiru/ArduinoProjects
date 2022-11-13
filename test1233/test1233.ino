int waterPin = A0;
int lightPin = D2;

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(waterPin, INPUT);
  pinMode(lightPin, INPUT);
}

void loop() {
  int h = analogRead(waterPin);
  int t = digitalRead(lightPin);
  Serial.print("humidity : ");
  Serial.print(h);
  Serial.print(" / light : ");
  Serial.println(t);
}
