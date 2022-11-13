/*
2
 http://www.bajdi.com (your number one source for buggy Arduino sketches)
3
 Simple obstacle avoiding robot made from parts mostly sourced from Ebay
4
 Micro controller = ATmega328P-PU with Arduino bootloader (3.5$ @ Eb.. noooo Tayda Electronics)
5
 Using a L293D (bought from my favourite Ebay seller Polida) to drive 2 yellow "Ebay motors with yellow wheels"
6
 Detecting obstacles with an SR04 ultrasonic sensor (uber cheap on Ebay)
7
 SR04 sensor mounted on SG90 servo (you can get these servo very cheap on ... oh yes you guessed it: EBay) 
8
*/

#include <NewPing.h>  //library for the SR04 ultrasonic sensor

#include <Servo.h>    //servo library, SR04 is mounted on this servo

Servo myservo;    
 
#define TRIGGER_PIN  A1  //using analog pins as digital for SR04 sensor 
#define ECHO_PIN     A0  //because I just happened to plug them in here
#define MAX_DISTANCE 200 //the sensor can't measure much further then this distance
 
19
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
20
 
21
#define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))
22
 
23
const int EN1 = 6;        //enable motor 1 = pin 1 of L293D
24
const int direction1 = 7; //direcion motor 1 = pin 2 of L293D
25
const int EN2 = 5;        //enable motor 2 = pin 9 of L293D
26
const int direction2 = 4; //direction motor 2 = pin 15 of L293D
27
// leds are very handy for testing
28
const int redLed = 10;    // this led will lit up when the robot drives forward
29
const int greenLed = 11;  // this led will lit up when the robot drives backward
30
const int yellowLed = 12; // this led will lit up when the robot turns left
31
const int whiteLed = 13;  // this led will lit up when the robot turns right
32
 
33
int uS;                  //value of SR04 ultrasonic sensor
34
int distance;            //distance in cm of ultrasonic sensor
35
int pos = 90;            //start position of servo = 90
36
int servoDirection = 0;  // sweeping left or right
37
int robotDirection = 0;  //0 = forward, 1 = backward, 2 = left, 3 = right
38
int lastRobotDirection;  //last direction of the robot
39
int distanceCenter;    
40
int distanceLeft;
41
int distanceRight;
42
int servoDelay = 20; //with this parameter you can change the sweep speed of the servo
43
const int speedLeft = 205; //there seems to be a bit of a difference between these cheap motors <span style="display: inline-block; line-height: normal; font-size: inherit; vertical-align: middle; position: relative; width: 1.1em; height: 1.1em; z-index: 100;"><svg style="padding: 0; margin: 0; width:100%; height:100%;"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#emoji-1f641"></use></svg><emoji-description style="width:0px;height:0px;font-size:0;line-height:0;">emoji unicode: 1f641</emoji-description></span>
44
const int speedRight = 255; //this motor needs a bit more voltage to keep up with the other
45
 
46
long previousMillis = 0;
47
const int interval = 650; //interval to switch between the robotDirection, this value will determine
48
//how long the robot will turn left/right when it detects an obstacle
49
 
50
void setup() {               
51
  pinMode(EN1, OUTPUT); 
52
  pinMode(direction1, OUTPUT);
53
  pinMode(EN2, OUTPUT);
54
  pinMode(direction2, OUTPUT);
55
  analogWrite(EN1, 0);
56
  analogWrite(EN2, 0);
57
  pinMode(redLed, OUTPUT);
58
  pinMode(greenLed, OUTPUT);
59
  pinMode(yellowLed, OUTPUT);
60
  pinMode(whiteLed, OUTPUT);
61
  Serial.begin(9600); //to use the serial monitor
62
  myservo.attach(8); //servo on pin 8
63
  myservo.write(pos); //center servo
64
  delay(1500); // delay so we have some time to put the robot on the floor
65
}
66
 
67
void loop() {
68
 
69
  sweepServo(); //function to sweep the servo
70
   
71
  getDistance();  //function to get the distance from the ultrasonic sensor
72
   
73
    if (pos >= 15 && pos <= 45)
74
  {
75
    distanceRight = distance;  //servo is to the right so measured distance = distanceRight
76
  }
77
  if (pos >= 135 && pos <= 165)
78
  {
79
    distanceLeft = distance; //servo is to the left so measured distance = distanceLeft
80
  }  
81
  if (pos > 70 && pos < 110)
82
  {
83
    distanceCenter = distance; //servo is centred so measured distance = distanceCenter
84
  }
85
 
86
  if (distanceCenter >= 25)    // coast is clear, full power forward
87
  {
88
    robotDirection = 0;        //move forward
89
  }
90
  else   //obstacle detected, turn left or right?
91
  {
92
    if (distanceLeft > distanceRight) 
93
    {
94
      robotDirection = 2; //turn left
95
    }
96
    if (distanceLeft < distanceRight)
97
    {
98
      robotDirection = 3; //turn right
99
    }
100
    if (distanceLeft <= 5 && distanceCenter <= 5 || distanceRight <= 5 && distanceCenter <= 5)
101
    {
102
      robotDirection = 1;  // we are stuck, lets try and backup
103
    }
104
  }
105
 
106
  unsigned long currentMillis = millis();  //set a timer
107
 
108
  if(robotDirection == 0 && robotDirection == lastRobotDirection) 
109
  {
110
    forward();
111
    lastRobotDirection = robotDirection;
112
  }
113
  if(robotDirection == 0 && robotDirection != lastRobotDirection && currentMillis - previousMillis > interval )
114
  { 
115
    forward();
116
    lastRobotDirection = robotDirection;
117
    previousMillis = currentMillis;
118
  }
119
  if(robotDirection == 1 && robotDirection == lastRobotDirection)
120
  {
121
    backward();
122
    lastRobotDirection = robotDirection;
123
  }
124
  if(robotDirection == 1 && robotDirection != lastRobotDirection && currentMillis - previousMillis > interval )
125
  { 
126
    backward();
127
    lastRobotDirection = robotDirection;
128
    previousMillis = currentMillis;
129
  }
130
  if(robotDirection == 2 && robotDirection == lastRobotDirection)
131
  {
132
    left();
133
    lastRobotDirection = robotDirection;
134
  }
135
  if(robotDirection == 2 && robotDirection != lastRobotDirection && currentMillis - previousMillis > interval )
136
  { 
137
    left();
138
    lastRobotDirection = robotDirection;
139
    previousMillis = currentMillis;
140
  }
141
  if(robotDirection == 3 && robotDirection == lastRobotDirection)
142
  {
143
    right();
144
    lastRobotDirection = robotDirection;
145
  }
146
  if(robotDirection == 3 && robotDirection != lastRobotDirection && currentMillis - previousMillis > interval )
147
  { 
148
    right();
149
    lastRobotDirection = robotDirection;
150
    previousMillis = currentMillis;
151
  }
152
}
153
 
154
void forward()
155
{
156
  digitalWrite(direction1, HIGH);
157
  digitalWrite(direction2, HIGH);  
158
  analogWrite(EN1, speedLeft);
159
  analogWrite(EN2, speedRight);
160
  digitalWrite(redLed, HIGH);
161
  digitalWrite(greenLed, LOW);
162
  digitalWrite(yellowLed, LOW);
163
  digitalWrite(whiteLed, LOW);
164
}
165
 
166
void stop()
167
{
168
  digitalWrite(direction1, LOW);  
169
  digitalWrite(direction2, LOW);  
170
  analogWrite(EN1, 0);
171
  analogWrite(EN2, 0);
172
  digitalWrite(redLed, LOW);
173
  digitalWrite(greenLed, LOW);
174
  digitalWrite(yellowLed, LOW);
175
  digitalWrite(whiteLed, LOW);
176
}
177
 
178
void backward()
179
{
180
  digitalWrite(direction1, LOW); 
181
  digitalWrite(direction2, LOW);  
182
  analogWrite(EN1, speedLeft+35);
183
  analogWrite(EN2, speedRight-15);
184
  digitalWrite(redLed, LOW);
185
  digitalWrite(greenLed, HIGH);
186
  digitalWrite(yellowLed, LOW);
187
  digitalWrite(whiteLed, LOW);
188
}
189
 
190
void left()
191
{
192
  digitalWrite(direction1, LOW);
193
  digitalWrite(direction2, HIGH);  
194
  analogWrite(EN1, speedLeft+35);
195
  analogWrite(EN2, speedRight);
196
  digitalWrite(redLed, LOW);
197
  digitalWrite(greenLed, LOW);
198
  digitalWrite(yellowLed, HIGH);
199
  digitalWrite(whiteLed, LOW);
200
}
201
 
202
void right()
203
{
204
  digitalWrite(direction1, HIGH);
205
  digitalWrite(direction2, LOW);  
206
  analogWrite(EN1, speedLeft);
207
  analogWrite(EN2, speedRight-30);
208
  digitalWrite(redLed, LOW);
209
  digitalWrite(greenLed, LOW);
210
  digitalWrite(yellowLed, LOW);
211
  digitalWrite(whiteLed, HIGH);
212
}
213
 
214
void getDistance()
215
{
216
  runEvery(40)   //loop for ultrasonic measurement
217
  {
218
    uS = sonar.ping();
219
    distance = uS / US_ROUNDTRIP_CM;
220
    if (uS == NO_ECHO) // if the sensor did not get a ping       
221
    {
222
      distance = MAX_DISTANCE;      //so the distance must be bigger then the max vaulue of the sensor
223
    }
224
    Serial.print("Ping: "); //to check distance on the serial monitor
225
    Serial.print(distance);
226
    Serial.println("cm");
227
  }
228
}
229
 
230
void sweepServo()
231
{
232
  runEvery(servoDelay)  //this loop determines the servo position
233
  {
234
    if(pos < 165 && servoDirection == 0)    // 165 = servo to the left
235
    {                                 
236
      pos = pos + 5;                        // +1 was to slow
237
    }
238
    if(pos > 15 && servoDirection == 1)     // 15 = servo to the right
239
    {                               
240
      pos = pos - 5;
241
    }   
242
  }  
243
  if (pos == 165 )   
244
  {
245
    servoDirection = 1;  //changes the direction
246
  }
247
  if (pos == 15 )    
248
  {
249
    servoDirection = 0;  //changes the direction
250
  }  
251
  myservo.write(pos);  //move that servo!
252
}

