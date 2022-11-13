#include<ESP8266WiFi.h>
const char*ssid = "PROLINK_H5004NK_82271";
const char*password = "bdg2293338";
int ledpin = 2;
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
} void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  } Serial.println("new client");
  while (!client.available()) {
    delay(1);
  } String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  int value = LOW;
  if (request.indexOf(" /LED=ON") != -1) {
    digitalWrite(ledpin, 1);
    value = HIGH;
  } if (request.indexOf(" /LED=OFF") != -1) {
    digitalWrite(ledpin, 0);
    value = LOW;
  } client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<title>switch</title>");
  client.print("<body bgcolor='red'>");
  client.print("<h1>hello bitches this is iot</h1>");
  client.print("Led pin is now: ");
  if (value == HIGH) {
    client.print("OFF");
  } else {
    client.print("ON");
  } client.println("<br><br>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn <b>ON</b></button></a>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn <b>OFF</b></button></a></br>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
