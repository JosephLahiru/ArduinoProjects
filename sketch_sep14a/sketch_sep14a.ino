int x = 0;
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    x = Serial.read();
    }
  Serial.print(x);
  Serial.print("\n");
  if(x == 49){
    digitalWrite(13,1);
  }
  else if(x == 50){
    digitalWrite(13,0);  
  }
}

