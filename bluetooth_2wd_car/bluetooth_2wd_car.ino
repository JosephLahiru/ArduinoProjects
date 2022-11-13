char junk;
String inputString="";
long time = 0; 
int state = HIGH;
int frontled = 7;
int frontled2 = 3;
int buzzer = 4;

void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);     
 pinMode(3, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(redled, OUTPUT);
 pinMode(redled2, OUTPUT);
 pinMode(12, OUTPUT); 
 pinMode(9, OUTPUT);
 pinMode(13, OUTPUT);
 pinMode(11, OUTPUT); 
 pinMode(8, OUTPUT); 
 pinMode(frontled, OUTPUT);
 pinMode(frontled2, OUTPUT); 
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar; //make a string of the characters coming on  serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { 
    junk = Serial.read() ; 
    }      // clear the serial buffer
    if(inputString == "a"){         //in case of 'a' turn the LED on
      if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    

    digitalWrite(frontled, state);
    digitalWrite(frontled2, state);
    }
    else if(inputString == "f"){   //incase of 'f'= forward
      digitalWrite(12, HIGH); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 255);   //Spins the motor on Channel A at full speed
      digitalWrite(13, HIGH); //Establishes forward direction of Channel B
      digitalWrite(8, LOW);   //Disengage the Brake for Channel B
      analogWrite(11, 255);   //Spins the motor on Channel B at full speed
    }
    else if(inputString == "b"){  //incase of 'b'= brakes
      digitalWrite(9, HIGH);  //Engage brakes for channel A
      digitalWrite(8, HIGH);  //Engage brakes for channel A
    }
    else if(inputString == "l"){  //incase of 'l'= left
      digitalWrite(12, HIGH); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 100);   //Spins the motor on Channel A at half speed
      digitalWrite(13, LOW); //Establishes backward direction of Channel B
      digitalWrite(8, LOW);   //Disengage the Brake for Channel B
      analogWrite(11, 100);   //Spins the motor on Channel B at half speed
    }
    else if(inputString == "r"){  //incase of 'r'= right
      digitalWrite(12, LOW); //Establishes backward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 100);   //Spins the motor on Channel A at half speed
      digitalWrite(13, HIGH); //Establishes forward direction of Channel B
      digitalWrite(8, LOW);   //Disengage the Brake for Channel B
      analogWrite(11, 100);   //Spins the motor on Channel B at half speed
    }
    else if(inputString == "w"){   //incase of 'w'= backward
      digitalWrite(12, LOW); //Establishes backward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 255);   //Spins the motor on Channel A at full speed
      digitalWrite(13, LOW); //Establishes backward direction of Channel B
      digitalWrite(8, LOW);   //Disengage the Brake for Channel B
      analogWrite(11, 255);   //Spins the motor on Channel B at full speed
    }
    inputString = ""; //we clear the variable for the next commande
  }
}
