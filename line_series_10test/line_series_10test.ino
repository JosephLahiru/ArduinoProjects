#define NUM_SENSORS             6  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             2  // emitter is controlled by digital pin 2
#define GUARD_GAIN   10.0
#define led 26
#define go 24

int enL = 6; // Motor Driver PWM
int enR = 5;

int inR1 = 7;// Motor Driver Direction
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;

int sL2 = A0;
int sL1 = A1;
int sM = A2;
int sR1 = A3;
int sR2 = A4;

unsigned int sensorValues[NUM_SENSORS];
unsigned int pidValues[NUM_SENSORS];
/////////////////////////////////////////////////////////////////
float Kp = 15;
float Ki = 0;
float Kd = 150;
float pTerm, iTerm, dTerm, integrated_error, last_error;
float error = 0;
int pidSpeed = 0;
int leftSpeed = 0;
int rightSpeed = 0;
int baseSpeed = 320;
int start;
//////////////////////////////////////////////////////////////////
void setup() {
  Serial3.begin(115200);
  pinMode(go, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  delay(500);
  
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);

  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);

  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  
  start = digitalRead(go);
  while (start == HIGH) {
    start = digitalRead(go);
    digitalWrite(led, HIGH);
  }
  digitalWrite(led, LOW);
  delay(1000);
}

void loop() {
  pid();
  leftSpeed = constrain((baseSpeed + pidSpeed), -400, 400);
  rightSpeed = constrain((baseSpeed - pidSpeed), -400, 400);
  speedCon(leftSpeed,rightSpeed);
}

void pid() {
  unsigned int position = qtra.readLine(sensorValues);
  int sum = 0;
  for (unsigned char i = 0; i < NUM_SENSORS; i++) {
    if (sensorValues[i] >= 450) {
      pidValues[i] = 0;
    }
    else if (sensorValues[i] < 450) {
      sum++;
      pidValues[i] = 1;
    }
  }
  error = 0;
  error = error - (90 * pidValues[0]);
  error = error - (25 * pidValues[1]);
  error = error - (10 * pidValues[2]);
  error = error + (10 * pidValues[5]);
  error = error + (25 * pidValues[6]);
  error = error + (90 * pidValues[7]);
  error = error / sum;
  pTerm = Kp * (error);
  integrated_error += error;
  iTerm = Ki * constrain(integrated_error, -GUARD_GAIN, GUARD_GAIN);
  dTerm = Kd * (error - last_error);
  last_error = error;
  pidSpeed = (pTerm + dTerm);
  if (sum == 0) {
        breaks();
        delay(5000);
  }
}

void calibratePanel() {
  for (int i = 0; i < 200; i++)
  {
   // qtra.calibrate();
  }
}

void speedCon(int m1, int m2) {

  if (m1 > 0) {
    digitalWrite(inL1, HIGH);//Direction F
    digitalWrite(inL2, LOW);
  } else {
    digitalWrite(inL1, LOW);//Direction B
    digitalWrite(inL2, HIGH);
    m1 = m1 * -1; //Value to possitive
  }
  analogWrite(enL, m1); //Speed Write as PWM


  if (m2 > 0) {
    digitalWrite(inR1, HIGH);//Direction F
    digitalWrite(inR2, LOW);
  } else {
    digitalWrite(inR1, LOW);//Direction B
    digitalWrite(inR2, HIGH);
    m2 = m2 * -1; //Value to possitive
  }
  analogWrite(enR, m2); //Speed Write as PWM

}

void breaks(){
  digitalWrite(inL1,HIGH);
  digitalWrite(inL2,HIGH);
  analogWrite(enL,255);

  digitalWrite(inR1,HIGH);
  digitalWrite(inR2,HIGH);
  analogWrite(enR,255);
}

