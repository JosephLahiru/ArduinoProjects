int com = 0;

void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.println("begin");
  delay(5000);
  //pinMode(2, OUTPUT);
  
}

void loop() {

  com = Serial.read();
  Serial.println(com);

  /*if (com == 97) {
    digitalWrite(2, LOW);
    delay(5);
    digitalWrite(2, HIGH);
  }*/
}
