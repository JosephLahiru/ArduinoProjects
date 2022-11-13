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

  if(button,HIGH) 
  {
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
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  delay(1);
  digitalWrite(one,HIGH);
  digitalWrite(two,HIGH);
  delay(1000);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  delay(1);
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
  digitalWrite(one,HIGH);
  digitalWrite(two,HIGH);
  digitalWrite(six,HIGH);
  delay(1000);
  digitalWrite(one,LOW);
  digitalWrite(two,LOW);
  digitalWrite(six,LOW);
  delay(1);
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
  } else {
    digitalWrite(one,LOW);  
  } 

}

