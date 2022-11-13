/*controling units
   fan
   light
   doorlock
*/

#include<ESP8266WiFi.h>

const char*ssid = "PROLINK_H5004NK_82271";
const char*password = "bdg2293338";
int ledpin = 2;
String value = "";
int fanpin = 0;
int doorpin = 1;
WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  delay(10);
  pinMode(fanpin, OUTPUT);
  digitalWrite(fanpin, LOW);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);
  pinMode(doorpin, OUTPUT);
  digitalWrite(doorpin, LOW);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin (ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.print("Use this url to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}
void loop()
{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("new client");
  while (!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  value = "";

  if (request.indexOf(" /LED=OFF") != -1)
  {
    digitalWrite(ledpin, HIGH);
    value = "1";
  }
  if (request.indexOf(" /LED=ON") != -1)
  {
    digitalWrite(ledpin, LOW);
    value = "0";
  }
  if (request.indexOf(" /FAN=OFF") != -1)
  {
    digitalWrite(fanpin, HIGH);
    value = "2";
  }
  if (request.indexOf(" /FAN=ON") != -1)
  {
    digitalWrite(fanpin, LOW);
    value = "3";
  }
  if (request.indexOf(" /DOOR=OFF") != -1)
  {
    digitalWrite(doorpin, HIGH);
    value = "4";
  }
  if (request.indexOf(" /DOOR=ON") != -1)
  {
    digitalWrite(doorpin, LOW);
    value = "5";
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<title>switch</title>");
  client.print("<body bgcolor='yellow'>");
  client.print("<h1>PROJECT ROOM</h1>");
  client.println("<h2>LIGHT</h2>" );
  if (value == "0")
  {
    client.print("Led pin is now ON");
  }
  else if (value == "1")  {
    client.print("Led pin is now OFF");
  }

  client.println("<br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn <b>ON</b></button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn <b>OFF</b></button></a></br>");
  client.println("<h2>FAN</h2>");
  if (value == "3")
  {
    client.print("fan is now ON");
  }
  else if (value == "2")
  {
    client.print("fan is now OFF");
  }
  client.println("<br>");
  client.println("<a href=\"/FAN=ON\"\"><button>Turn <b>ON</b></button></a>");
  client.println("<a href=\"/FAN=OFF\"\"><button>Turn <b>OFF</b></button></a></br>");

  client.println("<h2>DOOR</h2>");
  if (value == "5")
  {
    client.print("door is now OPENED");
  }
  else if (value == "4")
  {
    client.print("door is now CLOSED");
  }
  client.println("<br>");
  client.println("<a href=\"/DOOR=ON\"\"><button>Door <b>OPEN</b></button></a>");
  client.println("<a href=\"/DOOR=OFF\"\"><button>Door <b>CLOSE</b></button></a></br>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
