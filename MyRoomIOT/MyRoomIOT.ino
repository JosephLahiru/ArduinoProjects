/*controling units
   fan
   light
   doorlock
*/

#include<ESP8266WiFi.h>

const char*ssid = "PROLINK_H5004NK_82271";
const char*password = "bdg2293338";
int ledpin = 2;
String d = "";
String value = "";
WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  delay(10);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);
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

  if (request.indexOf(" /LED=ON") != -1)
  {
    digitalWrite(ledpin, 1);
    value = "1";
  }
  if (request.indexOf(" /LED=OFF") != -1)
  {
    digitalWrite(ledpin, 0);
    value = "0";
  }
  if (request.indexOf(" /SHO=ON") != -1)
  {
    d = "'<HR>'";
    value = "2";
  }
  if (request.indexOf(" /SHO=OFF") != -1)
  {
    Serial.println("end SHOW");
    value = "3";
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<title>switch</title>");
  client.print("<body bgcolor='yellow'>");
  client.print("<h1>PROJECT ROOM</h1>");

  if (value == "1")
  {
    client.print("Led pin is now: OFF");
  }
  else if (value == "0")
  {
    client.print("Led pin is now: ON");
  }
  else if (value == "2")
  {
    client.print("show pin is now: OFF");
  }
  else if (value == "3")
  {
    client.print("show pin is now: ON");
  }


  client.println("<br><br>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn <b>ON</b></button></a>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn <b>OFF</b></button></a></br>");
  client.println("<a href=\"/SHO=OFF\"\"><button>Turn <b>SOFF</b></button></a>");
  client.println("<a href=\"/SHO=ON\"\"><button>Turn <b>SON</b></button></a></br>");
  client.println(d);
  client.println("</body>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
  d = "";
}
