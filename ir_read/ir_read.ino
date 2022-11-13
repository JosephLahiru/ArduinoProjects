int ir = 6;
int sen;

void setup() {
  Serial.begin(9600);
  pinMode(ir,INPUT);

}

void loop() {
  
  sen=digitalRead(ir);
  
  Serial.println(sen);
}
