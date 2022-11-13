
int trigPin_f=A10;
int echoPin_f=A11;
float pingTime_f;
float cm_f=0;
int trigPin_l=A12;
int echoPin_l=A13;
float pingTime_l;
float cm_l=0;
int trigPin_r=A15;
int echoPin_r=A14;
float pingTime_r;
float cm_r=0;

void setup() {
  pinMode(trigPin_f, OUTPUT);
  pinMode(trigPin_l, OUTPUT);
  pinMode(trigPin_r, OUTPUT);
  Serial.begin(9600);
}

void ultrasonic_test(){

digitalWrite(trigPin_f, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_f, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_f, LOW);
pingTime_f = pulseIn(echoPin_f, HIGH);
pingTime_f=pingTime_f/29;
cm_f=pingTime_f/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm_f);
Serial.println(" cm_f");
delay(10);

digitalWrite(trigPin_l, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_l, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_l, LOW);
pingTime_l = pulseIn(echoPin_l, HIGH);
pingTime_l=pingTime_l/29;
cm_l=pingTime_l/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm_l);
Serial.println(" cm_l");
delay(10);

digitalWrite(trigPin_r, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_r, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_r, LOW);
pingTime_r = pulseIn(echoPin_r, HIGH);
pingTime_r=pingTime_r/29;
cm_r=pingTime_r/2;
Serial.print("The Distance to Target is: ");
Serial.print(cm_r);
Serial.println(" cm_r");
delay(10);
  
}

void loop() {
  ultrasonic_test();
  delay(1000);

}
