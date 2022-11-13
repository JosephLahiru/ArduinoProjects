char j;

#define F 13



void setup() {
Serial.begin(9600);
pinMode(13,F);


while(!Serial.available());
j=Serial.read();
Serial.println(j);
}

void loop(){ 
if(j=='F'){

digitalWrite(13,HIGH);
}

else (j=='W');{
  digitalWrite(13,LOW);
}
}
