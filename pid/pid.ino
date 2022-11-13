int sen1 = A5 ;//8// EXTREME LEFT
int sen2 = 2 ;//7
int sen3 = 3 ;//6
int sen4 = 4 ;//3 
int sen5 = 5 ;//2 //1 EXTREME RIGHT 
int thershold = 200;
int leftspeed=0;
int rightspeed=0;
int S1 = 0; 
int S2 = 0;
int S3 = 0;
int S4 = 0;
int S5 = 0;
int S6=0;
//int line = 0;
//int noline =1;
int Weight = 0 ;
int integral=0;
int derivative=0;
int previouserror = 0 ;
int kp=3.6;
int kd=4;
int ki=0;
int error=0 ; 
int x = 0 ;
int change = 0;
int d=0;
int maxspeed=0;


void setup (){
  Serial.begin(9600);
 /* pinMode ( 12 , OUTPUT);// ENA  
  pinMode ( 13 , OUTPUT);// ENB
  pinMode ( 9 , OUTPUT);// IN left 1
  pinMode ( 8, OUTPUT);//  IN LEFT 2  
  pinMode ( 7, OUTPUT);//  IN RIGHT 1
  pinMode ( 6,OUTPUT);//   IN RIGHT 2 */
 pinMode(11,OUTPUT); //PWM Pin 1
 pinMode(10,OUTPUT); //PWM Pin 2
 pinMode(9,OUTPUT); //Left Motor Pin 1
 pinMode(8,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(6,OUTPUT);  //Right Motor Pin 2
 // digitalWrite(12,HIGH);// ENABLE
 // digitalWrite(13,HIGH);
  
}

void loop (){
 int S1=analogRead(sen1);
 int S2=analogRead(sen2);
 int S3=analogRead(sen3);
 int S4=analogRead(sen4);
 int S5=analogRead(sen5);
 

 
  
    
    if (d == 0 ){
   if (  (S1==1)&& (S2==1) &&(S3==1)&& (S4==1)&&(S5==1)&& (S6==1)){
     digitalWrite(9,HIGH);
//     digitalWrite(8,HIGH);
     digitalWrite(7,HIGH);
//     digitalWrite(6,HIGH);
  //   digitalWrite(12,HIGH);// ENABLE
   // digitalWrite(13,HIGH);
  
     delay (200); 
     digitalWrite(9,LOW);
     digitalWrite(7,LOW);
//     digitalWrite(9,LOW);
//     digitalWrite(10,LOW);
     d=1;
   }
   else{
  if (x==0){
  digitalWrite(12,HIGH);// ENABLE
  digitalWrite(13,HIGH);
  
      digitalWrite(9,HIGH);
//     digitalWrite(8,HIGH);
     digitalWrite(7,HIGH);
//     digitalWrite(6,HIGH);
     delay (300);
       digitalWrite(9,LOW);
     digitalWrite(7,LOW);
     x=1;
  }
//  else{  if ((S3==1)&&(S4=0)){
//  Weight = 25;
// }
// else if ((S3==0)&&(S4==1)){
//  Weight = -25;
// }
  if ((S4==1)&&(S5==1)){
  Weight = -35;
 }
 else if ((S5==1)&&(S6==1)){
  Weight = -55;
 }
 else if (S6==1){
  Weight = -110;
 }
 else if ((S2==1)&& ( S3==1)){
  Weight = 35 ;
 }
 else if ((S2==1)&& ( S1==1)){
  Weight = 55;
 }
 else if (S1==1){
  Weight = 110;
 }
 else if ((S3==1)&&(S4==1)){
  Weight = 0 ;
 }
 else if ((S1==0)&&(S2==0)&&(S3==0)&&(S4==0)&&(S5==0)&&(S6==0)){
     digitalWrite(8,HIGH);
     digitalWrite(6,HIGH);
     delay(40);
      digitalWrite(8,LOW);
     digitalWrite(6,LOW);
  
 }

  derivative = (Weight - previouserror);
  integral = integral + (Weight*10);
  previouserror= Weight ;
  
  error = ((kp*Weight)+(kd*derivative)+(ki*integral));

  if ( Weight > 45 ||(Weight < -45) ) {
    maxspeed=180;
//    digitalWrite(8,HIGH);
//     digitalWrite(6,HIGH);
//     delay(50);
//      digitalWrite(8,LOW);
//     digitalWrite(6,LOW);
    
  }
  else {
    maxspeed=255;
  }
  
  leftspeed = (maxspeed-error);
  rightspeed = (maxspeed+error);
  
  if (leftspeed <=0){
    leftspeed = 0 ;
  }
  if (rightspeed <=0){
    rightspeed = 0 ;
  }
  if (leftspeed >= maxspeed){
    leftspeed = maxspeed;
  }
  if (rightspeed >= maxspeed){
    rightspeed=maxspeed;
  }
    
  
  digitalWrite(12,HIGH);// ENABLE
  digitalWrite(13,HIGH);
  
  analogWrite ( 7, rightspeed);
  analogWrite (9, leftspeed);


Serial.println(S1);
Serial.println("1");
Serial.println(S2);
Serial.println("2");
Serial.println(S3);
Serial.println("3");
Serial.println(S4);
Serial.println("4");
Serial.println(S5);
Serial.println("5");
Serial.println(S6);
Serial.println("6");
Serial.println();
delay ( 10) ;
    
   
   }
  } 
}


