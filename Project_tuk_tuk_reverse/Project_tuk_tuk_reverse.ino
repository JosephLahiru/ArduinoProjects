int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
int led10 = 11;
int led11 = 12;
int led12 = 13;

int trigPin_1 = A0;
int echoPin_1 = A1;
float pingTime_1;
float cm_1 = 0;
int trigPin_2 = A2;
int echoPin_2 = A3;
float pingTime_2;
float cm_2 = 0;
int trigPin_3 = A5;
int echoPin_3 = A4;
float pingTime_3;
float cm_3 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin_1, OUTPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(trigPin_3, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
}

void ultrasonic_test() {

  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);
  pingTime_1 = pulseIn(echoPin_1, HIGH);
  pingTime_1 = pingTime_1 / 29;
  cm_1 = pingTime_1 / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_1);
  Serial.println(" cm_1");
  delay(10);

  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);
  pingTime_2 = pulseIn(echoPin_2, HIGH);
  pingTime_2 = pingTime_2 / 29;
  cm_2 = pingTime_2 / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_2);
  Serial.println(" cm_2");
  delay(10);

  digitalWrite(trigPin_3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_3, LOW);
  pingTime_3 = pulseIn(echoPin_3, HIGH);
  pingTime_3 = pingTime_3 / 29;
  cm_3 = pingTime_3 / 2;
  Serial.print("The Distance to Target is: ");
  Serial.print(cm_3);
  Serial.println(" cm_3");
  delay(10);

}

void loop() {
  
  ultrasonic_test();

}
