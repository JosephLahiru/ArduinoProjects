int error=0;
int sensor0=0;
int sensor1=0;
int sensor2=0;
int sensor3=0;
int sensor4=0;
int sharp1=0;
int sharp2=0;
int sharp3=0;
int x=0;
void setup() {
  pinMode(A5,INPUT); //left sen
 pinMode(2,INPUT); //left mid sen
 pinMode(3,INPUT); //mid sen
 pinMode(4,INPUT); //right mid sen
 pinMode(5,INPUT); //right sen 
 pinMode(11,OUTPUT); //PWM Pin 1
 pinMode(10,OUTPUT); //PWM Pin 2
 pinMode(9,OUTPUT); //Left Motor Pin 1
 pinMode(8,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(6,OUTPUT);  //Right Motor Pin 2
 Serial.begin(9600); //Enable Serial Communications
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
    analogWrite(10,150);  //left 
    analogWrite(11,150);  //right
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
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

void reverse(){
    analogWrite(10,80);  //left 
    analogWrite(11,80);  //right
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}
void fast_left(){
    analogWrite(10,100);   
    analogWrite(11,100); 
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
}
void fast_right(){
    analogWrite(10,100);   
    analogWrite(11,100); 
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}
void left(){
    analogWrite(10,0);   
    analogWrite(11,100); 
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
}
void right(){
    analogWrite(10,100);   
    analogWrite(11,0); 
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}
void slow_left(){
    analogWrite(10,100);   
    analogWrite(11,150); 
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
}
void slow_right(){
    analogWrite(10,150);   
    analogWrite(11,100); 
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
}
void breake(){
    reverse();
    delay(5);
  }
void sharp_test(){
    //sharp1=analogRead(A0);
   // sharp2=analogRead(A1);
   // sharp3=analogRead(A2);
    /*Serial.print(sharp);
    delay(500);
    Serial.print("\n");*/
    if((analogRead(A0)>250)||(analogRead(A1>250))||(analogRead(A2)>250)){
          breake();
          slow_left();
          delay(500);
          while(analogRead(A3)>100){
            forword();
          }
          
        breake();
        slow_right();
        delay(335);
      }
    else{
        forword();
      }
    
  }
/*void none(){
    analogWrite(10,0);   
    analogWrite(11,0);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
}*/
void read_sensor_values()
{
  sensor0=digitalRead(A5);
  sensor1=digitalRead(2);
  sensor2=digitalRead(3);
  sensor3=digitalRead(4);
  sensor4=digitalRead(5);  
  if((sensor0==LOW)&&(sensor1==LOW)&&(sensor2==LOW)&&(sensor3==LOW)&&(sensor4==HIGH)){
    error=100;
    
  }
  if((sensor0==0)&&(sensor1==0)&&(sensor2==1)&&(sensor3==1)&&(sensor4==1)){
   error=90;
    
  }
 if((sensor0==0)&&(sensor1==0)&&(sensor2==0)&&(sensor3==1)&&(sensor4==1)){
   error=80;
    
  }
  if((sensor0==0)&&(sensor1==0)&&(sensor2==0)&&(sensor3==1)&&(sensor4==0)){
   error=60;
  
  }
  if((sensor0==0)&&(sensor1==0)&&(sensor2==1)&&(sensor3==1)&&(sensor4==0)){
   error=40;
   
  }
  if((sensor0==0)&&(sensor1==0)&&(sensor2==1)&&(sensor3==0)&&(sensor4==0)){
  error=0;
 
  }
 if((sensor0==0)&&(sensor1==1)&&(sensor2==1)&&(sensor3==1)&&(sensor4==0)){
 error=0;
   
  }
 if((sensor0==0)&&(sensor1==1)&&(sensor2==1)&&(sensor3==0)&&(sensor4==0)){
  error=-40;
   
  }
 if((sensor0==0)&&(sensor1==1)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)){
   error=-60;
  
  }
 if((sensor0==1)&&(sensor1==1)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)){
   error=-80;
   
  }
  if((sensor0==1)&&(sensor1==1)&&(sensor2==1)&&(sensor3==0)&&(sensor4==0)){
   error=-90;
   
  }
 if((sensor0==1)&&(sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)){
 error=-100;
 
  }
//  if((sensor0==1)&&(sensor1==1)&&(sensor2==1)&&(sensor3==1)&&(sensor4==1)){
// error=200;
 
//  }
}
 void line_follow(){
  read_sensor_values();
 if (error==100){
    fast_right();
  }
  else if(error==80){
    fast_right();
  }
   else if(error==90){
    fast_right();
  }
  else if(error==60){
    right();
  }
  else if(error==40){
    slow_right();
  }
  else if(error==0){
    forword();
  }
  else if(error==-40){
    slow_left();
  }  
  else if(error==-60){
    left();
  }
  else if(error==-80){
    fast_left();
  }
   else if(error==-90){
    fast_left();
  }
  else if(error==-100){
    fast_left();
  }
 // else if(error==200){
 //   sharp_test();
//  }
}


void loop() {
  
line_follow();

  }
 
