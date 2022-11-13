int error = 0;
int sensor0 = 0;
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;
int sharp1 = 0;
int sharp2 = 0;
int sharp3 = 0;
int x = 0;
int F1, F2, F3, L, R;
void setup() {
  pinMode(2, INPUT); //left mid sen
  pinMode(3, INPUT); //mid sen
  pinMode(4, INPUT); //right mid sen
  pinMode(5, INPUT); //right sen
  pinMode(11, OUTPUT); //PWM Pin 1
  pinMode(10, OUTPUT); //PWM Pin 2
  pinMode(9, OUTPUT); //Left Motor Pin 1
  pinMode(8, OUTPUT); //Left Motor Pin 2
  pinMode(7, OUTPUT); //Right Motor Pin 1
  pinMode(6, OUTPUT); //Right Motor Pin 2
  pinMode(13, OUTPUT);//bazzer
  Serial.begin(9600); //Enable Serial Communications
}
void sen_check() {
  x = 0;
  while (x < 6) {
    Serial.print(digitalRead(x));
    x = x + 1;
  }
  Serial.print("\n");
  delay(500);

}
void bazzer(){
    tone(13,1600);
    delay(100);
    noTone(13);
    delay(100);
  }
void forword() {
 
  analogWrite(10, 60); //left
  analogWrite(11, 53); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void none() {
  analogWrite(10, 0);
  analogWrite(11, 0);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void reverse() {
  analogWrite(10, 80); //left
  analogWrite(11, 80); //right
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void fast_left() {
  analogWrite(10, 100);
  analogWrite(11, 100);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void fast_right() {
  analogWrite(10, 100);
  analogWrite(11, 100);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void left() {
  analogWrite(10, 0);
  analogWrite(11, 75);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void right() {
  analogWrite(10, 75);
  analogWrite(11, 0);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void slow_left() {
  analogWrite(10, 45);
  analogWrite(11, 75);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void slow_right() {
  analogWrite(10, 75);
  analogWrite(11, 45);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void breake() {
  reverse();
  delay(5);
}


void box_area() {
  F1 = analogRead(A0);
  F2 = analogRead(A1);
  F3 = analogRead(A2);
  L = analogRead(A4);
  R = analogRead(A3);
  
  if (F2 > 400 || F3 > 400 ) {
    breake();
    if (x%2==0) {
      right();
      delay(700);
      x=x+1;
      while (L > 200) {
        forword();
      }
      forword();
      
      
      left();
      delay(600);
      breake();
      x = x++;
    }
    else {
      left();
      x=x+1;
      delay(700);
      while (R > 200) {
        forword();
      }
      forword();
      
      right();
      delay(600);
      breake();
      x = x++;
    }
  }
  else {
    forword();

  }
}

void sharp_test() {
  F1 = analogRead(A0);
  F2 = analogRead(A1);
  F3 = analogRead(A2);
  L = analogRead(A4);
  R = analogRead(A3);
   if (F2 < 250 or F3 < 250 ) {
      fast_left();
      delay(200);
    }
    else{
        forword();
      }
    

}
void read_sensor_values()
{
  sensor0 = digitalRead(A5);
  sensor1 = digitalRead(2);
  sensor2 = digitalRead(3);
  sensor3 = digitalRead(4);
  sensor4 = digitalRead(5);
  if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 1)) {
    error = 100;

  }
  if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1)) {
    error = 90;

  }
  if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 1) && (sensor4 == 1)) {
    error = 80;

  }
  if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 1) && (sensor4 == 0)) {
    error = 60;

  }
  if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 0)) {
    error = 40;

  }
  if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 1) && (sensor3 == 0) && (sensor4 == 0)) {
    error = 0;

  }
  if ((sensor0 == 0) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 0)) {
    error = 0;

  }
  if ((sensor0 == 0) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 0) && (sensor4 == 0)) {
    error = -40;

  }
  if ((sensor0 == 0) && (sensor1 == 1) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0)) {
    error = -60;

  }
  if ((sensor0 == 1) && (sensor1 == 1) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0)) {
    error = -80;

  }
  if ((sensor0 == 1) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 0) && (sensor4 == 0)) {
    error = -90;

  }
  if ((sensor0 == 1) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0)) {
    error = -100;

  }
   if((sensor0==1) && (sensor1==1) && (sensor2==1) && (sensor3==1) && (sensor4==1)){
   error=200;

    }
}
void line_follow() {
  read_sensor_values();
  if (error == 100) {
    
    fast_right();
  }
  else if (error == 80) {

    fast_right();
  }
  else if (error == 90) {
     
    fast_right();
  }
  else if (error == 60) {
    right();
  }
  else if (error == 40) {
    slow_right();
  }
  else if (error == 0) {
    forword();
  
  }
  else if (error == -40) {
    slow_left();
  }
  else if (error == -60) {
    left();
  }
  else if (error == -80) {

    fast_left();
  }
  else if (error == -90) {
   
    fast_left();
  }
  else if (error == -100) {
   
    fast_left();
  }
   else if(error==200){
     bazzer();
     delay(1000);
    breake();
    none();
  }
}

void extream_path(){
  sensor0 = digitalRead(A5);
  sensor1 = digitalRead(2);
  sensor2 = digitalRead(3);
  sensor3 = digitalRead(4);
  sensor4 = digitalRead(5);
    if ((sensor0 == 1) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1)) {
    while(1){
        box_area();
      }
    }
    else if((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0)){
        none();
      }
    else{
        line_follow();
      }
  }
  
  
void loop() {
  /*F1 = analogRead(A0);
  F2 = analogRead(A1);
  F3 = analogRead(A2);
  L = analogRead(A4);
  R = analogRead(A3);

  Serial.print(F1);
  Serial.print(" ");
  Serial.print(F2);
  Serial.print(" ");
  Serial.print(F3);
  Serial.print(" ");
  Serial.print(L);
  Serial.print(" ");
  Serial.print(R);
  Serial.print(" ");
  Serial.print("\n");
  delay(500);
  */
//  forword();
 // delay(200);
 // extream_path();
 box_area();
}

