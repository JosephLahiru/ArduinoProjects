void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  byte barDistance = maxDistance; 
  byte barDegree;                 
  byte distance;                 
  
  
  for (byte ultrasonicServoDegree = 40; ultrasonicServoDegree < 140; ultrasonicServoDegree += 10) {
    
    ultrasonicServo.write(ultrasonicServoDegree + ultrasonicServoOffset); // steer pan tilt to corresponding position
    
    delay(50);                // wait 50ms between pings (about 20 pingsc). 29ms should be the shortest delay between pings.
    
    receiveData();
    
    distance = getDistance(); // detect the current distance from obstacle with angle of pan tilt stable
    
    if (distance < barDistance) { // if the current measured distance is smaller than the previous one, save the data of current measured distance
      
      barDegree = ultrasonicServoDegree;       // save the measured angle
      
      barDistance = distance;     // save the measured distance
      
    }
  }
  
  // servo of pan tilt turns to default position
  
  delay(200);
  
  ultrasonicServo.write(90 + ultrasonicServoOffset);
  
  int spd = 128;  // set the speed(0-255) of smart car
  
  // According to the result of scanning control action of intelligent vehicles
  if (barDistance < 20) {     // if the obstacle distance is too close, reverse the travelling direction
    
    if (barDegree < 90)       // choose to reverse direction according to the angle with obstacle
    
      ctrlCar1(135 - (data[4] - 512) / 12,  FORWARD, spd); // control steering and reversing smart car
      
    else
    
      ctrlCar1(45 - (data[4] - 512) / 12,  FORWARD, spd); // control steering and reversing smart car
      
    for (int i = 0; i < 15; i++) {
      
      delay(100);     
              
      receiveData();
      
    }
  }
  else if (barDistance < 50) {// if the obstacle distance is too close, reverse the travelling direction
    
    if (barDegree < 90)       // choose to reverse direction according to the angle with obstacle
    
      ctrlCar1(135 - (data[4] - 512) / 12, BACKWARD, spd); // control steering and moving on
      
    else
    
      ctrlCar1(45 - (data[4] - 512) / 12, BACKWARD, spd);  // control steering and moving on
      
    for (int i = 0; i < 10; i++) {
      
      delay(100);              // reversing time
      
      receiveData();
      
    }
  }
  else {                     // if the obstacle distance is not close, move on
    
    ctrlCar1(90 - (data[4] - 512) / 12, BACKWARD, spd);    // control the smart car move on
    
    for (int i = 0; i < 10; i++) {
      
      delay(100);              // reversing time
      
      receiveData();
    }
  }
  ctrlCar1(90 - (data[4] - 512) / 12, BACKWARD, 0); // make the smart car stop for preparation of next scanning


}
