int a=6,b=7;

void setup()
{
  pinMode(a,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(b,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if((digitalRead(a)==HIGH)&&(digitalRead(b)==HIGH))
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    Serial.println("FORWARD");delay(1);
  }
  else if((digitalRead(a)==LOW)&&(digitalRead(b)==HIGH))
  {
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    Serial.println("LEFT");delay(1);
  }
  else if((digitalRead(a)==HIGH)&&(digitalRead(b)==LOW))
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    Serial.println("RIGHT");delay(1);
  }
    else if((digitalRead(a)==LOW)&&(digitalRead(b)==LOW))
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    Serial.println("LEFT");delay(1);
  }
}

