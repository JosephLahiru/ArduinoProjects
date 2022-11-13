float Kp = 1, Ki = 0.000001, Kd = 1.8; //for 50 1 , 0.000001 , 1.8
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;//for 60 1 , 0.000003,6.5
float previous_error = 0, previous_I = 0;
int initial_motor_speed = 55; //50
int x = 0;
int F1, F2, F3, L, R;
int sensor[5] = {0, 0, 0, 0, 0};
int ret = 0;
void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);
void analz_sharp(int y, int ret);
int sensor0, sensor1, sensor2, sensor3, sensor4, LM, RM;
int N=0;
int count = 0;
int O=0;
int H=0;
int Z=0;
int Y=0;
void setup()
{
  pinMode(12,INPUT);// left motor sensor
  pinMode(A0,INPUT);// right motor sensor
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
void left() {
  analogWrite(10, 0);
  analogWrite(11, 75);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void right() {
  analogWrite(10, 80);
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
void breake() {
  reverse();
  delay(5);
}

void sharp_read(){
  
  F2 = analogRead(A1);
  F3 = analogRead(A2);
  L = analogRead(A4);
  R = analogRead(A3);
  }
void motor_reading(){
  LM=digitalRead(12);
  RM=digitalRead(A0);
}
void encoder_reading(){
  motor_reading();
while (true){
motor_reading();
if (LM == 0){
  if (Y == 0){
  O=O+1;
  Y=1;
  }
}
else{
 
  Y=0;

}
if (RM == 0){
  if (Z == 0){
  H=H+1;
  Z=1;
  }
}
else{
 
  Z=0;

}
if (O == H){
  analogWrite(10, 45); //left
  analogWrite(11, 43); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
 }
else if (O > H){
  analogWrite(10, 0); //left
  analogWrite(11, 50); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
else if (O < H){
  analogWrite(10, 50); //left
  analogWrite(11, 0); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
// Serial.print(LM);
// Serial.print(" ");
// Serial.print(O);
// Serial.print(" ");
// Serial.print(RM);
// Serial.print(" ");
// Serial.print(H);
// delay(50);
// Serial.print("\n"); 

}

}
void box_area_forword() {
 encoder_reading();
 if (O == H){
  analogWrite(10, 45); //left
  analogWrite(11, 43); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
 }
else if (O > H){
  analogWrite(10, 45); //left
  analogWrite(11, 50); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
else if (O < H){
  analogWrite(10, 50); //left
  analogWrite(11, 43); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
else{
  analogWrite(10, 45); //left
  analogWrite(11, 43); //right
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
}
void box_area() {
  sensor[0] = digitalRead(A5);
  sensor[1] = digitalRead(2);
  sensor[2] = digitalRead(3);
  sensor[3] = digitalRead(4);
  sensor[4] = digitalRead(5);
 if((sensor[0] == 0) or (sensor[1] == 0) or (sensor[2] == 0) or (sensor[3] == 0) or (sensor[4] == 0)){
    while(1){
      none();
      }
  }
 
  F2 = analogRead(A1);
  F3 = analogRead(A2);
  L = analogRead(A4);
  R = analogRead(A3);
// if((F2 > 400 || F3 > 400) && (R > 200 && L > 200)) {
//   box_area_forword();
    

// }
   if (F2 > 500 || F3 > 500 ) {
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
      while (L > 200) {
     //   none();
      //  delay(250);
        box_area_forword();
        sharp_read();
//        if (F2 > 500 || F3 > 500 ){
//            breake();
//            reverse();
//            delay(250);
//            none();
//            delay(250);
//            left();
//            delay(500);
//            breake();
//            while(L > 200){
//              //  none();
//            //    delay(250);
//                box_area_forword();
//                 sharp_read();
//              }
//          }
      }
      //box_area_forword();
      
   //   none();
  //    delay(250);
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
      
      while (R > 200) {
      //  none();
      //  delay(250);
        box_area_forword();
        sharp_read();
//        if (F2 > 500 || F3 > 500 ){
//            breake();
//            reverse();
//            delay(250);
//            none();
//            delay(250);
//            right();
//            delay(550);
//            breake();
//            while(L > 200){
//                sharp_read();
//                box_area_forword();
//              }
//      }
      }
    //  box_area_forword();
    //  none();
   //   delay(250);
      right();
      delay(550);
      breake();
   
  }
   }
 
 else {
   
   box_area_forword();
 }
}
void read_sensor_values()
{
  sensor[0] = digitalRead(A5);
  sensor[1] = digitalRead(2);
  sensor[2] = digitalRead(3);
  sensor[3] = digitalRead(4);
  sensor[4] = digitalRead(5);

  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1)) {
    error = 40;
    N=40;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)) {
    error = 30;
    N=0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)) {
    error = 40;
    N=40;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)) {
    error = -40;
    N=40;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0)) {
    error = 20;
   N=0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0)) {
    error = 10;
    N=0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = 0;
    N=0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0)) {
    error = 0;
    N=0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -10;
    N=0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -20;
    N=0;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0)) {
    error = 40;
    N=-40;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -40;
    N=-40;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -30;
    N=0;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -40;
    N=-40;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
      error=previous_error;
      N=0;
    }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1)) {
      error=previous_error;
      N=0;
    }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0)) {
      error=previous_error;
      N=0;
    }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1)) {
      error=previous_error;
      N=0;
    }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)) {
    while (1) {
      box_area();
      /*tone(13, 1500);
      delay(50);
      noTone(13);
      delay(50);*/
      if ((sensor[0] == 0) or (sensor[1] == 0) or (sensor[2] == 0) or (sensor[3] == 0) or (sensor[4] == 0)) {
        break;
      }
      sensor[0] = digitalRead(A5);
      sensor[1] = digitalRead(2);
      sensor[2] = digitalRead(3);
      sensor[3] = digitalRead(4);
      sensor[4] = digitalRead(5);
    }
  }
  else {
    read_sensor_values();
  }
}

void calculate_pid()
{
  read_sensor_values();
  P = error;
  I = I + error ;
  D = error - previous_error ;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  previous_error = error;
}
void motor_control()
{
  read_sensor_values();
  calculate_pid();
  // Calculating the effective motor speed:
  int left_motor_speed = initial_motor_speed - PID_value;
  int right_motor_speed = initial_motor_speed + PID_value;

  // The motor speed should not exceed the max PWM value
  constrain(left_motor_speed, 0, 255);
  constrain(right_motor_speed, 0, 255);

  if( left_motor_speed < 0 ){
      left_motor_speed = left_motor_speed * -1 ;
    }

  if( right_motor_speed < 0 ){
      right_motor_speed = right_motor_speed * -1 ;
    }
  
  if ( N==-40 ) {
   
    analogWrite(11, left_motor_speed);  //Left Motor Speed
    analogWrite(10, left_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward

    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else if ( N== 40 ) {
    
    analogWrite(11, right_motor_speed);  //Left Motor Speed
    analogWrite(10, right_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward

    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);

  }
  else if (N  == 0){
    analogWrite(11, left_motor_speed);  //Left Motor Speed
    analogWrite(10, right_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward

    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }

}
  void line_follow() {
    read_sensor_values();
    calculate_pid();
    motor_control();
  }
  /*void analz_sharp(int y , ... return ret){
    if(y > 200 && y < 450){
      ret=1;
    }
    else{
      ret=0;
    }
    }*/
 
 

 

  
  void loop()
  {


// line_follow();
//  right();
//    delay(400);
//   none();
//   delay(10000);
encoder_reading();
// box_area_forword();
//forword();
  }


