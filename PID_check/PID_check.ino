float Kp = 1, Ki = 0.000001, Kd = 1.8;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0, con = 0, tp=0;;
float previous_error = 0, previous_I = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  
 // Serial.println(error);
  P = error;
  I = I + previous_I;
  Serial.print("previous_error=");
  Serial.println(previous_error);
  D = error - previous_error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);
  Serial.println(PID_value);
  previous_I = I;
  previous_error = error;
  error=error+tp;
  tp=tp+1;
  Serial.println(previous_I);
  delay(500);
}


