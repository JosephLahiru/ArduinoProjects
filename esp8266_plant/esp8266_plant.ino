#include <ESP8266WiFi.h>

int waterPin = A0;
int lightPin = D2;

const char* ssid     = "PROLINK_H5004NK_82271";
const char* password = "bdg2293338";
const char* host = "roomiot.000webhostapp.com";

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(waterPin, INPUT);
  pinMode(lightPin, INPUT);
  Serial.println();
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
}

void loop() {
  int h = analogRead(waterPin);
  int t = digitalRead(lightPin);
  Serial.print("humidity : ");
  Serial.print(h);
  Serial.print(" / light : ");
  Serial.println(t);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("connecting to ");
  Serial.println(host);

  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  String url = "/api/weather/insert.php?humidity=" + String(h) + "&light="+ String(t);
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  delay(3000);
}
