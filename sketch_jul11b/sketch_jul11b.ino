long duration, inches, cm;  //  function from datasheet of ping sensor

void read_Ping( void )
{
  pinMode(pingPin,OUTPUT);    //  
  digitalWrite(pingPin,LOW); 
  delayMicroseconds(2);       // delay recomended from datasheet
  digitalWrite(pingPin,HIGH); 
  delayMicroseconds(5);       // delay recomended from datasheet
  digitalWrite(pingPin,LOW); 
  pinMode(pingPin,INPUT); 
  duration =pulseIn(pingPin,HIGH); 
  
  inches = microsecondsToInches(duration); // converting time into distance
  cm = microsecondsToCentimeters(duration); 

  Serial.print(inches); 
  Serial.print("in, "); 
  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println();
}

