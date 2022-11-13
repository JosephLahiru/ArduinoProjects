/*
  http://myhub.lk/a/Robotics/v3_line_following_01
  by Dileepa Jayawardena
*/

int sL = A0;//Sensors
int sR = A1;


int enL = 6; // Motor Driver PWM
int enR = 5;

int inR1 = 7;// Motor Driver Direction
int inR2 = 8;
int inL1 = 9;
int inL2 = 10;


void setup() {
  Serial.begin(9600);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);

  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);

  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);

  digitalWrite(13,HIGH);
  delay(10000);

}

int maxpower = 140;// max bot speed
int robotspeed = 0;
int maxspeed = 100;// speed limit
void loop() {
  int vL = analogRead(A0);// sensor reading
  int vR = analogRead(A1);
  Serial.print(vL);
  Serial.print("_");
  Serial.println(vR);

  int mL = 0;
  int mR = 0;

  if (vL > 400) {
    if (robotspeed > maxspeed) {
      stopbot();
    }
    mL = -maxpower;
    mR = maxpower;
    robotspeed = 0;
  } else if (vR > 400) {
    if (robotspeed > maxspeed) {
      stopbot();
    }
    mL = maxpower;
    mR = -maxpower;
    robotspeed = 0;
  } else if (vL < 400 && vR < 400) {
    mL = maxpower;
    mR = maxpower;
    robotspeed++;
  }
  mpower(mL, mR);
}

void stopbot() {
  mpower(-maxpower, -maxpower);
  delay(10);
  mpower(0, 0);
  delay(10);
}
void mpower(int m1, int m2) {

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



