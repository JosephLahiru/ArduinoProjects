#include <ESP8266WiFi.h>

const char* ssid = "PROLINK_H5004NK_82271";
const char* password = "bdg2293338";

String k;

WiFiServer server(80);

void setup() {

  Serial.begin(9600);
  delay(10);

 // k = Serial.read();

  //while (k != "arduinoReady") {
  //  Serial.println("Waiting For Arduino");
  //  delay(1000);
 // }

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

  }

  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");

  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  if (request.indexOf("/START") != -1) {
    Serial.write("START");
  }

  client.println("<html>");

  client.println("<head>");
  client.println("</head>");

  client.println("<body bgcolor='yellow'>");
  //------------------------------------------------------------------------------------------------------------------------------------

  client.println("<a href =\"/START\"\"><button style='width:40%;height:20%'>START</button></a>");

  //------------------------------------------------------------------------------------------------------------------------------------
  client.println("</body>");

  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
