int i=0;
int x=0;
void setup() {
 Serial.begin(9600);
}

void loop() {
  for(int l=0; l<1000; l++){
  Serial.println(l);
  }
}
