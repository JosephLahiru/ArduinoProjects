int redpin=13;
int greenpin=8;
int fanpin=9;

int incomingbyte;

void setup(){
  Serial.begin(9600);
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(fanpin,OUTPUT);
}

void loop(){
  if(Serial.available()>0){
    incomingbyte = Serial.read();
  }
  if(incomingbyte == 0){
    digitalWrite(redpin,HIGH);
  }
  if(incomingbyte == 1){
    digitalWrite(redpin,LOW);
  }
}
