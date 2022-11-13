float Kp = 1, Ki = 0, Kd = 0;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int initial_motor_speed = 50;
int F_sharp = 0, L_sharp = 0, R_sharp = 0;
int F = 0, L = 0, R = 0;
int sensor[5] = {0, 0, 0, 0, 0};
int x = 0, ret = 0;
void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);
void analz_sharp(int y, int ret);
int sensor0, sensor1, sensor2, sensor3, sensor4;
int N=0;
void setup()
{
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

void none() {
  analogWrite(10, 0);
  analogWrite(11, 0);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
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
    N = 40;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)) {
    error = 30;
     N = 30;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)) {
    error = 40;
     N = 40;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)) {
    error = 40;
     N = 40;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0)) {
    error = 20;
     N = 20;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0)) {
    error = 10;
     N = 10;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = 0;
     N = 0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0)) {
    error = 0;
     N = 0;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -10;
     N = -10;
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -20;
     N = -20;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0)) {
    error = -40;
     N = 50;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -40;
     N = 50;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -30;
     N = -30;
  }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
    error = -40;
     N = 50;
  }
 
  /* else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[4] == 0) && (sensor[4] == 0)) {
       if(error=-40){
         error=-50;
       }
       else if(error=40){
           error=50;
         }
       else{
           read_sensor_values();
         }
    }*/
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)) {
    while (1) {
      none();
      tone(13, 1500);
      delay(50);
      noTone(13);
      delay(50);
      if ((sensor[0] == 0) or (sensor[1] == 0) or (sensor[2] == 0) or (sensor[3] == 0) or (sensor[4] == 0)) {
        break;
      }
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
    Serial.print(N);
    Serial.print(" ");
    Serial.print(left_motor_speed);
    Serial.print(" ");
    Serial.print(right_motor_speed);
    Serial.print("\n");
    delay(500);

  
  if (N == 50) {
    
    analogWrite(11, left_motor_speed);  //Left Motor Speed
    analogWrite(10, left_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward
    /*The pin numbers and high, low values might be different
      depending on your connections */
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  
  else if (N == 40) {
    
    analogWrite(11, right_motor_speed);  //Left Motor Speed
    analogWrite(10, right_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward
    /*The pin numbers and high, low values might be different
      depending on your connections */
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);

  }
  else {
    analogWrite(11, left_motor_speed);  //Left Motor Speed
    analogWrite(10, right_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward
    /*The pin numbers and high, low values might be different
      depending on your connections */
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
    }
  void sharp_read() {
    F_sharp = analogRead(A0);
    L_sharp = analogRead(A1);
    R_sharp = analogRead(A2);
    if (F_sharp > 200 && F_sharp < 450) {
      F = 1;
    }
    else {
      F = 0;
    }
    if (L_sharp > 200 && L_sharp < 450) {
      L = 1;
    }
    else {
      L = 0;
    }
    if (R_sharp > 200 && R_sharp < 450) {
      R = 1;
    }
    else {
      R = 0;
    }

  }*/
  void forword() {
    analogWrite(10, 150); //left
    analogWrite(11, 150); //right
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  void left() {
    analogWrite(10, 0);
    analogWrite(11, 150);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  void right() {
    analogWrite(10, 150);
    analogWrite(11, 0);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }/*
  void box_area() {
    sharp_read();
    if (F == 1) {
      x = random(0, 5);
      if (x <= 2) {
        left();
        delay(500);
        while (R == 0) {
          forword();
        }
        right();
        delay(500);
      }
      else {
        right();
        delay(500);
        while (L == 0) {
          forword();
        }
        left();
        delay(500);
      }
    }
    else {
      forword();
    }
  }
  void box_area_1sen() {
    while (1) {
      sharp_read();
      if (F == 1) {
        x = random(0, 5);
        if (x <= 2) {
          left();
          delay(500);
        }
        else {
          right();
          delay(500);
        }
      }
      else {
        forword();
      }
    }
  }*/

  void loop()
  {
    read_sensor_values();
   calculate_pid();
    motor_control();
  
  }


