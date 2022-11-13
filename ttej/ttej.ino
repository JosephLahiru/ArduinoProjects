int trigPin=12;
int echoPin=13;
float pingTime;
float targetDistance;

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(2,OUTPUT);//left
 pinMode(3,OUTPUT);//left
 pinMode(4,OUTPUT);//right
 pinMode(5,OUTPUT);//right
 pinMode(6,OUTPUT);//LPWM
 pinMode(7,OUTPUT);//RPWM
 Serial.begin(9600);
}


void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/29;
targetDistance=pingTime/2;
delay(10);

if(targetDistance>20.0)

{

    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,1);
    digitalWrite(5,0);
    analogWrite(6,255);
    analogWrite(7,255);  
    Serial.println("FORWARD");

}

else if(targetDistance<20.0)

{

    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,1);
    digitalWrite(5,0);
    analogWrite(6,0);
    analogWrite(7,255);  
    Serial.println("LEFT TURN");
 
}

}



