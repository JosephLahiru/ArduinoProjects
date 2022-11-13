int sharp=0;
void setup() {
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  
  

}
void forword(){
    analogWrite(10,150);  //left 
    analogWrite(11,150);  //right
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
}
void left(){
    analogWrite(10,0);   
    analogWrite(11,150); 
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}
void right(){
    analogWrite(10,150);   
    analogWrite(11,0); 
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
}
void none(){
    analogWrite(10,0);   
    analogWrite(11,0);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}
void sharp_read(){
    sharp=analogRead(A0);
    Serial.print(sharp);
    delay(500);
    Serial.print("\n");
  }

void loop() {
   sharp_read();
 
}
