int one = 2;
int two = 3;
int three = 4;
int four = 5;
int five = 6;
int six = 7;
int seven = 8;
int button = 9;

void setup() {
  
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,INPUT);

}

void loop() {

  zeroo();
  delay(1);
  onee();
  delay(1);
  twoo();
  delay(1);
  threee();
  delay(1);
  fourr();
  delay(1);
  fivee();
  delay(1);
  sixx();
  delay(1);
  sevenn();
  delay(1);
  eightt();
  delay(1);
  ninee();
  delay(1);
}

void zeroo(){
  digitalWrite(one,HIGH);
  digitalWrite(two,HIGH);
  digitalWrite(three,HIGH);
  digitalWrite(four,HIGH);
  digitalWrite(six,HIGH);
  digitalWrite(seven,HIGH);
  delay(1000);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  digitalWrite(three,LOW);
  digitalWrite(four,LOW);
  digitalWrite(six,LOW);
  digitalWrite(seven,LOW);
  delay(1);
}
void onee(){
  digitalWrite(one,HIGH);
  digitalWrite(two,HIGH);
  delay(1000);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  delay(1);
}
void twoo(){
  digitalWrite(six,HIGH);
  digitalWrite(one,HIGH);
  digitalWrite(five,HIGH);
  digitalWrite(four,HIGH);
  digitalWrite(three,HIGH);
  delay(1000);
  digitalWrite(six,LOW);
  digitalWrite(one,LOW);
  digitalWrite(five,LOW);
  digitalWrite(four,LOW);
  digitalWrite(three,LOW);
  delay(1);
}
void threee(){
  digitalWrite(six,HIGH);
  digitalWrite(one,HIGH);
  digitalWrite(five,HIGH);
  digitalWrite(two,HIGH);
  digitalWrite(three,HIGH);
  delay(1000);
  digitalWrite(six,LOW);
  digitalWrite(one,LOW);
  digitalWrite(five,LOW);
  digitalWrite(two,LOW);
  digitalWrite(three,LOW);
  delay(1);
}
void fourr(){
  digitalWrite(seven,HIGH);
  digitalWrite(one,HIGH);
  digitalWrite(five,HIGH);
  digitalWrite(two,HIGH);
  delay(1000);
  digitalWrite(seven,HIGH);
  digitalWrite(one,LOW);
  digitalWrite(five,LOW);
  digitalWrite(two,LOW);
  delay(1);
}
void fivee(){
  digitalWrite(six,HIGH);
  digitalWrite(seven,HIGH);
  digitalWrite(five,HIGH);
  digitalWrite(two,HIGH);
  digitalWrite(three,HIGH);
  delay(1000);
  digitalWrite(six,LOW);
  digitalWrite(seven,LOW);
  digitalWrite(five,LOW);
  digitalWrite(two,LOW);
  digitalWrite(three,LOW);
  delay(1);
}
void sixx(){
  digitalWrite(six,HIGH);
  digitalWrite(seven,HIGH);
  digitalWrite(five,HIGH);
  digitalWrite(two,HIGH);
  digitalWrite(three,HIGH);
  digitalWrite(four,HIGH);
  delay(1000);
  digitalWrite(six,LOW);
  digitalWrite(seven,LOW);
  digitalWrite(five,LOW);
  digitalWrite(two,LOW);
  digitalWrite(three,LOW);
  digitalWrite(four,LOW);
  delay(1);
}
void sevenn(){
  digitalWrite(one,HIGH);
  digitalWrite(two,HIGH);
  digitalWrite(six,HIGH);
  delay(1000);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  digitalWrite(six,LOW);
  delay(1);
}
void eightt(){
  digitalWrite(one,HIGH);
  digitalWrite(two,HIGH);
  digitalWrite(three,HIGH);
  digitalWrite(four,HIGH);
  digitalWrite(six,HIGH);
  digitalWrite(seven,HIGH);
  digitalWrite(five,HIGH);
  delay(1000);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  digitalWrite(three,LOW);
  digitalWrite(four,LOW);
  digitalWrite(six,LOW);
  digitalWrite(seven,LOW);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  digitalWrite(five,LOW);
  delay(1);
}
void ninee(){
  digitalWrite(one,HIGH);
  digitalWrite(two,HIGH);
  digitalWrite(three,HIGH);
  digitalWrite(six,HIGH);
  digitalWrite(seven,HIGH);
  digitalWrite(five,HIGH);
  delay(1000);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  digitalWrite(three,LOW);
  digitalWrite(six,LOW);
  digitalWrite(seven,LOW);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  digitalWrite(five,LOW);
  delay(1);
}
void none(){
  
}

