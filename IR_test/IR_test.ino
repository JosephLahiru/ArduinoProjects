int a=2,b=3,c=4,d=5,e=6;

void setup() {
pinMode(a, INPUT);
pinMode(b, INPUT);
pinMode(c, INPUT);
pinMode(d, INPUT);
pinMode(e, INPUT);
Serial.begin(9600); 
}
void set () 
{
if(digitalRead(a)== 1){Serial.println("1");} 
if(digitalRead(b)== 1){Serial.println("2");}
if(digitalRead(c)== 1){Serial.println("3");}
if(digitalRead(d)== 1){Serial.println("4");}
if(digitalRead(e)== 1){Serial.println("5");}
}

void loop() {
  set(); 

}
