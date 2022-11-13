
void setup() {
 pinMode(1,INPUT);//right_sensor
 pinMode(2,INPUT);//mid_sensor
 pinMode(3,INPUT);//leftsensor
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
}

 void forword(){
  
        analogWrite(6,255); 
        analogWrite(7,255);  
        digitalWrite(1,LOW);
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
}
void reverse(){
  
        analogWrite(6,255); 
        analogWrite(7,255);  
        digitalWrite(1,HIGH);
        digitalWrite(2,LOW);
        digitalWrite(3,HIGH);
}
void turn_left(){
  
        analogWrite(6,255); 
        analogWrite(7,100);  
        digitalWrite(1,LOW);
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
}
void turn_right(){
  
        analogWrite(6,100); 
        analogWrite(7,255);  
        digitalWrite(1,HIGH);
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
}
void turn_leftH(){
  
        analogWrite(6,255); 
        analogWrite(7,0);  
        digitalWrite(1,LOW);
        digitalWrite(2,LOW);
        digitalWrite(3,HIGH);
}
void turn_rightH(){
  
        analogWrite(6,0); 
        analogWrite(7,255);  
        digitalWrite(1,HIGH);
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
}
void stop(){
  
        analogWrite(6,255); 
        analogWrite(7,255);  
        digitalWrite(1,LOW);
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
}
void loop() {
 void forword();
 void reverse();
 void turn_left();
 void turn_right();
 void turn_leftH();
 void turn_rightH();
 void stop();
}
