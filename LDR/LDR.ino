int SensorReading;
void setup(){
  Serial.begin(9600);
  pinMode(6,OUTPUT);
}
void loop(){
  SensorReading=analogRead(0);
  if(SensorReading<700)
  {
    digitalWrite(6,HIGH);
  }
}

