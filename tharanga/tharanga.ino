float Kp = 2, Ki = 0.00001, Kd = 1.8 ; //for 50 1 , 0.000001 , 1.8
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;//for 60 1 , 0.000003,6.5
float previous_error = 0, previous_I = 0;
int initial_motor_speed = 100; //50
int F_sharp = 0, L_sharp = 0, R_sharp = 0;
int sensor[5] = {0, 0, 0, 0, 0};
int x = 0, N = 0;
int M = 0, R = 0 , L = 0;


void setup() {
  pinMode(1, OUTPUT); //right1
  pinMode(2, OUTPUT); //right2
  pinMode(3, OUTPUT); //left1
  pinMode(4, OUTPUT); //left2
  pinMode(5, OUTPUT); //r_pwm
  pinMode(6, OUTPUT); //l_pwm
  pinMode(7, INPUT); //L1
  pinMode(8, INPUT); //L2
  pinMode(9, INPUT); //M sen
  pinMode(10, INPUT); //M2 sen
  pinMode(11, INPUT); //R2
  pinMode(12, INPUT); //R1
  Serial.begin(9600);
}

void forward() {
  digitalWrite(1, HIGH); //right
  digitalWrite(2, LOW); //right
  digitalWrite(3, HIGH); //left
  digitalWrite(4, LOW); //left
  analogWrite(5, 180); //R_pwm
  analogWrite(6, 180); //L_pwm
}
void left_slow() {
  digitalWrite(1, HIGH); //right
  digitalWrite(2, LOW); //right
  digitalWrite(3, HIGH); //left
  digitalWrite(4, LOW); //left
  analogWrite(5, 180); //R_pwm
  analogWrite(6, 100); //L_pwm
}
void right_slow() {
  digitalWrite(1, HIGH); //right
  digitalWrite(2, LOW); //right
  digitalWrite(3, HIGH); //left
  digitalWrite(4, LOW); //left
  analogWrite(5, 100); //R_pwm
  analogWrite(6, 180); //L_pwm
}
void reverse() {
  digitalWrite(1, LOW); //right
  digitalWrite(2, HIGH); //right
  digitalWrite(3, LOW); //left
  digitalWrite(4, HIGH); //left
  analogWrite(5, 80); //R_pwm
  analogWrite(6, 80); //L_pwm
}
void left() {
  digitalWrite(1, LOW); //right
  digitalWrite(2, HIGH); //right
  digitalWrite(3, HIGH); //left
  digitalWrite(4, LOW); //left
  analogWrite(5, 180); //R_pwm
  analogWrite(6, 180); //L_pwm
}



void right() {
  digitalWrite(1, HIGH); //right
  digitalWrite(2, LOW); //right
  digitalWrite(3, LOW); //left
  digitalWrite(4, HIGH); //left
  analogWrite(5, 180); //R_pwm
  analogWrite(6, 180); //L_pwm
}
void none() {
  digitalWrite(1, HIGH); //right
  digitalWrite(2, LOW); //right
  digitalWrite(3, HIGH); //left
  digitalWrite(4, LOW); //left
  analogWrite(5, 0); //R_pwm
  analogWrite(6, 0); //L_pwm
}


void read_sensor_values() {
  L=digitalRead(A0);
  M=digitalRead(A1);
  R=digitalRead(A2);
  if (L == 0 && M == 0 && R == 0) {
    error = previous_error;
  }
  else if (L == 1 && M == 0 && R == 0) {
    error = -30;
    N = -40;
  }
  else if (L == 1 && M == 1 && R == 0) {
    error = 50;
    N = -40;
  }
  else if (L ==0  && M == 1 && R == 0) {
    error = 0;
    N = 0;
  }
  else if (L == 1 && M == 0 && R == 0) {
    error = 0;
    N = 40;
  }
  else if (L == 0 && M == 1 && R == 1) {
    error = -50;
    N = 40;
  }
  else if (L == 0 && M == 0 && R == 1) {
    error = 30;
    N = 40;
  }
  else if(L == 1 && M == 1 && R == 1){
    while(1){
      none();
      
      }  
  }



}

void calculate_pid()
{

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

  if ( left_motor_speed < 0 ) {
    left_motor_speed = left_motor_speed * -1 ;
  }

  if ( right_motor_speed < 0 ) {
    right_motor_speed = right_motor_speed * -1 ;
  }

  if ( N == -40 ) {

    analogWrite(6, left_motor_speed);  //Left Motor Speed
    analogWrite(5, left_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward

    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  else if ( N == 40 ) {
    //right turn
    analogWrite(6, right_motor_speed);  //Left Motor Speed
    analogWrite(5, right_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward

    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

  }
  else if (N  == 0) {
    analogWrite(6, left_motor_speed);  //Left Motor Speed
    analogWrite(5, right_motor_speed); //Right Motor Speed
    //following lines of code are to make the bot move forward

    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }

}


void loop() {
  read_sensor_values();
  calculate_pid();
  motor_control();

}
