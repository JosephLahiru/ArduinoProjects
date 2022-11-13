int pulse;

void setup() {
  Serial.begin(115200);
  pinMode(A0,INPUT);

}

void loop() {
  pulse = analogRead(A0);
  Serial.println(pulse);
  //analogWrite(A0,100);
}
