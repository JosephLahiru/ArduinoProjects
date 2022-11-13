int sharp=0;
int x=0;
void setup() {
  pinMode(0,INPUT);//left sen
  pinMode(2,INPUT); //left mid sen
  pinMode(3,INPUT); //mid sen
  pinMode(4,INPUT); //right mid sen
  pinMode(5,INPUT); //right sen 
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9200);  
}
void sen_check(){
    x=0;
    while(x<6){
      Serial.print(digitalRead(x));
      x=x+1;
      }
      Serial.print("\n");
      delay(500);
          
}
void forword(){
    analogWrite(10,50);  //left 
    analogWrite(11,57);  //right
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
}

void reverse(){
    analogWrite(10,80);  //left 
    analogWrite(11,80);  //right
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}
void left(){
    analogWrite(10,100);   
    analogWrite(11,100); 
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
}
void right(){
    analogWrite(10,100);   
    analogWrite(11,100); 
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}
void none(){
    analogWrite(10,0);   
    analogWrite(11,0);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}
void breake(){
    reverse();
    delay(5);
  }
void sharp_test(){
    sharp=analogRead(A0);
    /*Serial.print(sharp);
    delay(500);
    Serial.print("\n");*/
    if(sharp>250){
          breake();
          right();
          delay(500);
          while(analogRead(A4)>100){
            forword();
          }
        breake();
        left();
        delay(335);
      }
    else{
        forword();
      }
    
  }
void loop() {
sharp_test();
  
}
