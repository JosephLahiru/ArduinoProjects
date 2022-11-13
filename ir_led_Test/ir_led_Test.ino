int pulse=0;
int led=13;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
  pulse=digitalRead(A0);
  Serial.println(pulse);
  constrain(pulse, 0, 100);
  digitalWrite(led,!pulse);
  Serial.println(pulse);
}
