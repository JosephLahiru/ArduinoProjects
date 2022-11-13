
#include <ESP8266WiFi.h>

const char* ssid = "your router";
const char* password = "your password";

WiFiServer server(80);



void left_f(void)
{
   digitalWrite(D1, 255);
   digitalWrite(D2, 0);
}
void right_f(void)
{
   digitalWrite(D5, 255);
   digitalWrite(D6, 0);
}
void left_b(void)
{
     digitalWrite(D1, 0);
   digitalWrite(D2, 255);
}
void right_b(void)
{
    digitalWrite(D5, 0);
   digitalWrite(D6, 255);
}

void move_forward(void)
{
  left_f();
  right_f();
}

void move_backward(void)
{
  left_b();
  right_b();
}

void move_left(void)
{
  left_b();
  right_f();
}

void move_right(void)
{
  left_f();
  right_b();
}

void stop_all_now(void)
{
    digitalWrite(D5, 0);
   digitalWrite(D6, 0);
    digitalWrite(D1, 0);
   digitalWrite(D2, 0);
   
}




void setup() {

  Serial.begin(115200);
  delay(10);
  
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

  

 stop_all_now();

   WiFi.begin(ssid, password);



 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
   Serial.print(".");
  }
 Serial.println("");
 Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
Serial.println("Server started");

  // Print the IP address
 Serial.println(WiFi.localIP());








}

void loop()
{
// stop_all_now();

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
//  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
//  Serial.println(req);
  client.flush();
  
  // Match the request
  int val=0;
  if (req.indexOf("/gpio/0") != -1)
    val = 0;
  else if (req.indexOf("/gpio/1") != -1)
    val = 1;

 else if (req.indexOf("/gpio/2") != -1)
    val = 2;

     else if (req.indexOf("/gpio/3") != -1)
    val = 3;

     else if (req.indexOf("/gpio/4") != -1)
    val = 4;
    
  else {
   // Serial.println("invalid request");
    client.stop();
    return;
  }

  // Set GPIO2 according to the request


  

  if(val==1) move_forward();
  if(val==2) move_backward();
  if(val==3) move_left();
  if(val==4) move_right();
  if(val==0) stop_all_now();
  if ((val<=0) || (val>=5))
  stop_all_now();
  val=0;
  
 // digitalWrite(LED_BUILTIN, val);
  
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  s += (val)?"high":"low";
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
/
}
























/*
  
 move_forward();
 delay(1000);
  move_backward();
  delay(1000);
  move_left();
  delay(1000);
  move_right();
  delay(1000);
 
 
   
}*/
