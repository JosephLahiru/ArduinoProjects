char getstr; 
int in1=9; 
int in2=10; 
int in3=11; 
int in4=12; 
//上面定义了板上的4个控制端，12一组，34一组 
 
void _mRight(int pin1,int pin2)//当in1和in2中有一个接高位时，电机会向某一方向转动
{ 
 
 digitalWrite(pin1,HIGH); 
 digitalWrite(pin2,LOW); 
} 
void _mLeft(int pin1,int pin2)//同上 
{ 
 digitalWrite(pin1,LOW); 
 digitalWrite(pin2,HIGH); 
} 
void _mStop(int pin1,int pin2)//紧急制动，实际就是将电机两个端短接了 
{ 
 digitalWrite(pin1,HIGH); 
 digitalWrite(pin2,HIGH); 
} 
void setup() 
{ 
 Serial.begin(9600); 
 pinMode(in1,OUTPUT); 
 pinMode(in2,OUTPUT); 
 pinMode(in3,OUTPUT); 
 pinMode(in4,OUTPUT); 
 //下面程序开始时让控制端都为高电平，电机保持不动。 
 digitalWrite(in1,HIGH); 
 digitalWrite(in2,HIGH); 
 digitalWrite(in3,HIGH); 
 digitalWrite(in4,HIGH); 
} 
void loop() 
 
{ 
 getstr=Serial.read(); 
 if(getstr=='f') 
 { 
 Serial.println("go forward!"); 
 _mStop(in1,in2); 
 _mStop(in3,in4); 
 _mRight(in1,in2); 
 _mRight(in3,in4); 
 } 
 else if(getstr=='b'){ 
 Serial.println("go back!"); 
 _mStop(in1,in2); 
 _mStop(in3,in4); 
 _mLeft(in1,in2); 
 _mLeft(in3,in4);
 } 
 else if(getstr=='l'){ 

 Serial.println("go left!"); 
 _mStop(in1,in2); 
 _mStop(in3,in4); 
 _mRight(in1,in2);
 } 
 else if(getstr=='r'){ 
 Serial.println("go right!"); 
 _mStop(in1,in2); 
 _mStop(in3,in4); 
 _mRight(in3,in4); 
 } 
 
 else if(getstr=='s'){ 
 Serial.println("Stop!"); 
 _mStop(in1,in2); 
 _mStop(in3,in4); 
 } 
#}#define echopin  8 // echo pin
#define trigpin 9 // Trigger pin
int maximumRange = 30;
long duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
}
void loop ()
{

  {
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    duration=pulseIn (echopin,HIGH);
    distance= duration/58.2;
    delay (50);
    Serial.println(distance);
  }
  
  if (distance >= 30 ){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay (200);
  }
  
  else if (distance >=15 && distance <= 25) {
    digitalWrite (2,HIGH);
    digitalWrite (3,LOW);
    digitalWrite (4,LOW);
    digitalWrite (5,LOW);
    delay (1000);
  }
 else if (distance < 15){
   digitalWrite (2, LOW);
   digitalWrite (3, HIGH);
   digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   delay (1000);
   digitalWrite (2,LOW);
   digitalWrite (3,LOW);
   digitalWrite (4,HIGH);
   digitalWrite (5,LOW);
   delay (1000);     
 }
}

