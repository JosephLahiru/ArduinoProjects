String k;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.write("arduinoReady");
  digitalWrite(13,LOW);
}

void loop() {
  k=Serial.read();
  Serial.println(k);
  if(k=="START"){
    digitalWrite(13,HIGH);
  }
}
