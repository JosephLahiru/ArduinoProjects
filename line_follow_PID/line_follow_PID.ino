#include<AFMotor.h>

float Kp = 0, Ki = 0, Kd = 0; //for 50 1 , 0.000001 , 1.8
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;//for 60 1 , 0.000003,6.5
float previous_error = 0, previous_I = 0;
int initial_motor_speed = 100; //50
int sensor[5] = {0, 0, 0, 0, 0};

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

int sensor0, sensor1, sensor2, sensor3, sensor4;
int N=0;

int buzzer=50;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup()
{
  pinMode(31,INPUT);
  pinMode(32,INPUT);
  pinMode(33, INPUT); 
  pinMode(34, INPUT); 
  pinMode(35, INPUT); 
  pinMode(buzzer,OUTPUT);
  
 Serial.begin(9600); //Enable Serial Communications 
}

void read_sensor_values()
{
  sensor[0] = digitalRead(31);
  sensor[1] = digitalRead(32);
  sensor[2] = digitalRead(33);
  sensor[3] = digitalRead(34);
  sensor[4] = digitalRead(35);

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
      digitalWrite(buzzer,HIGH);
      delay(50);
      digitalWrite(buzzer,LOW);
      if ((sensor[0] == 0) or (sensor[1] == 0) or (sensor[2] == 0) or (sensor[3] == 0) or (sensor[4] == 0)) {
        break;
      }
      sensor[0] = digitalRead(31);
      sensor[1] = digitalRead(32);
      sensor[2] = digitalRead(33);
      sensor[3] = digitalRead(34);
      sensor[4] = digitalRead(35);
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
   
motor1.setSpeed(0);
motor1.run(BACKWARD);
motor2.setSpeed(left_motor_speed);
motor2.run(FORWARD);
motor3.setSpeed(0);
motor3.run(BACKWARD);
motor4.setSpeed(left_motor_speed);
motor4.run(FORWARD);
delay(10);
    //left
  }
  else if ( N== 40 ) {
    
motor1.setSpeed(right_motor_speed);
motor1.run(FORWARD);
motor2.setSpeed(0);
motor2.run(BACKWARD);
motor3.setSpeed(right_motor_speed);
motor3.run(FORWARD);
motor4.setSpeed(0);
motor4.run(BACKWARD);
delay(10);
   //right
  }
  else if (N  == 0){
motor1.setSpeed(left_motor_speed);
motor1.run(FORWARD);
motor2.setSpeed(right_motor_speed);
motor2.run(FORWARD);
motor3.setSpeed(left_motor_speed);
motor3.run(FORWARD);
motor4.setSpeed(right_motor_speed);
motor4.run(FORWARD);
delay(1);
    //forward
  }

}
  void line_follow() 
{
    read_sensor_values();
    calculate_pid();
    motor_control();
}

  
  void loop()
{
    line_follow();
}


