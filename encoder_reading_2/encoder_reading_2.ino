


//------code for RPM----------------
int encoder_pin = 2;
// The pin the encoder is connected
unsigned int rpm;
// rpm reading
volatile byte pulses;
// number of pulses
unsigned long timeold;
// The number of pulses per revolution
// depends on your index disc!!
unsigned int pulsesperturn = 1;
void counter()
{
  //Update count
  pulses++;
}
//-----------------------------------
void setup()   {
  Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  //display.display();
  //delay(2000);
  // Clear the buffer.
  //display.clearDisplay();
  // draw a single pixel
  //display.drawPixel(10, 10, WHITE);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  //display.display();
  //delay(2000);
  //-----------code for RPM---------------
  //Use statusPin to flash along with interrupts
  pinMode(encoder_pin, INPUT);
  //Interrupt 0 is digital pin 2, so that is where the IR detector is connected
  //Triggers on FALLING (change from HIGH to LOW)
  attachInterrupt(0, counter, FALLING);
  // Initialize
  pulses = 0;
  rpm = 0;
  timeold = 0;
}
void loop()
{
  if (millis() - timeold >= 1000) {
    /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
    //Don't process interrupts during calculations
    detachInterrupt(0);
    //Note that this would be 60*1000/(millis() - timeold)*pulses if the interrupt
    //happened once per revolution
    rpm = (60 * 1000 / pulsesperturn ) / (millis() - timeold) * pulses;
    timeold = millis();
    pulses = 0;
    //Write it out to serial port
    Serial.print("RPM = ");
    Serial.println(rpm, DEC);
    updateDisplay(rpm);
    //Restart the interrupt processing
    attachInterrupt(0, counter, FALLING);
  }
}
int valLen;
int displayWidth = 128;
int letterWidth = 18;
void updateDisplay(int rpm) {
  if (rpm > 9999)
    valLen = 5;
  else if (rpm > 999)
    valLen = 4;
  else if (rpm > 99)
    valLen = 3;
  else if (rpm > 9)
    valLen = 2;
  else
    valLen = 1;

}
