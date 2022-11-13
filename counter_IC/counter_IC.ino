int cc= 2;

void setup() {
  pinMode(cc,OUTPUT);

}

void loop() {
  digitalWrite(cc,HIGH);
  delay(1000);
  digitalWrite(cc,LOW);
  delay(1);

}
