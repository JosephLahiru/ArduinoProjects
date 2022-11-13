int left_en = 0, right_en = 0;
int F3, F2, L, R;
int x = 0;
int L_pos = 0, R_pos = 0;
void setup()
{
  pinMode(12, INPUT); // left motor sensor
  pinMode(A0, INPUT); // right motor sensor
  pinMode(0, INPUT); //left sen
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
  Serial.begin(9600); //Enable Serial Communications
}
void breake() {
  reverse();
  delay(5);
}
void none() {
  analogWrite(10, 0);
  analogWrite(11, 0);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void sharp_read(){
  
  F2 = analogRead(A1);
  F3 = analogRead(A2);
  L = analogRead(A4);
  R = analogRead(A3);
  }
void forword() {

  analogWrite(10, 50); //left
  analogWrite(11, 50); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

  if (digitalRead(12) == HIGH) {
    left_en++;
  }
  if (digitalRead(A0) == HIGH) {
    right_en++;
  }
}
void reverse() {
  analogWrite(10, 80); //left
  analogWrite(11, 80); //right
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  if (digitalRead(12) == HIGH) {
    left_en--;
  }
  if (digitalRead(A0) == HIGH) {
    right_en--;
  }
}
void left() {
  analogWrite(10, 0);
  analogWrite(11, 75);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

  if (digitalRead(12) == HIGH) {
    left_en--;
  }
  if (digitalRead(A0) == HIGH) {
    right_en++;
  }
}
void right() {
  analogWrite(10, 80);
  analogWrite(11, 0);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);

  if (digitalRead(12) == HIGH) {
    left_en++;
  }
  if (digitalRead(A0) == HIGH) {
    right_en--;
  }
}
void turn_90_left(){
    R_pos = 0;
    while(R_pos < 3250){
        analogWrite(10, 50); //left
        analogWrite(11, 150); //right
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        if(digitalRead(A0)==1){
            R_pos++;
          }
      }
      Serial.print(R_pos);
  }

  void turn_90_right(){
    L_pos = 0;
    while(L_pos <  3250){
        analogWrite(10, 150); //left
        analogWrite(11, 0); //right
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        if(digitalRead(12)==1){
            L_pos++;
          }
      }
  }

void pos() {
  L_pos = left_en % 4;
  R_pos = right_en % 4;

  if (L_pos < 0) {
    L_pos = L_pos * -1;
  }
  if (R_pos < 0) {
    R_pos = R_pos * -1;
  }
}
void super_forward(){
  if (left_en > right_en) {
      while (left_en != right_en) {
        
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        analogWrite(11, 0);
        analogWrite(10, 50);

        if (digitalRead(12) == HIGH) {
          left_en--;
        }
      }
    }
    else if (right_en > left_en) {
      while (left_en != right_en) {
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        analogWrite(11, 50); //right
        analogWrite(10, 0);
        if (digitalRead(A0) == HIGH) {
          right_en--;
        }
      }
    }
    else{
        forword();
      }
}

void sharp() {
  F2 = analogRead(A1);
  F3 = analogRead(A2);
  R = analogRead(A3);
  L = analogRead(A4);

   if (F2 > 600 || F3 > 600 ) {
    breake();
    if (x%2==0) {
      reverse();
      delay(250);
      none();
      delay(250);
      right();
      delay(550);
      breake();
      x=x+1;
      while (analogRead(A4) > 600) {
        super_forward();
      }
      left();
      delay(550);
      breake();
 }
    else {
      reverse();
      delay(250);
      none();
      delay(250);
      left();
      delay(550);
      breake();
      x=x+1;
      
      while (analogRead(A3) > 600) {
        super_forward();
      }
      right();
      delay(550);
      breake();
   
  }
   }
 
 else {
   
   super_forward();
 }
}

void loop() {
 sharp();
  
  
}
