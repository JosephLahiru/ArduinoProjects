//Google Assistant Home Automation
#include <ESP8266WiFi.h>π
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <Adafruit_Sensor.h>


// pin connected to DH22 data line


#define Relay1 D0
#define Relay2 D1
#define Relay3 D2


//WLAN Details
#define WLAN_SSID "Dialog 4G 299" // Your SSID
#define WLAN_PASS "9b1025c3" // Your password

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER "io.adafruit.com" //Adafruit Server
#define AIO_SERVERPORT 1883
#define AIO_USERNAME "Amres" // Username
#define AIO_KEY "17d759ac6e9b4e5a8e94031e544d21ed" // Auth Key


//WIFI CLIENT
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Light = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME"/feeds/Relay1"); // Feeds name should be same everywhere
Adafruit_MQTT_Subscribe Lamp = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay2");
Adafruit_MQTT_Subscribe Fan = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay3");

void MQTT_connect();

void setup() {


  Serial.begin(115200);


  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);


  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  mqtt.subscribe(&Light);
  mqtt.subscribe(&Lamp);
  mqtt.subscribe(&Fan);

}

void loop() {

  MQTT_connect();


  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(20000))) {
    if (subscription == &Light) {
      Serial.print(F("Got: "));
      Serial.println((char *)Light.lastread);
      int Light_State = atoi((char *)Light.lastread);
      digitalWrite(Relay1, Light_State);

    }
    if (subscription == &Lamp) {
      Serial.print(F("Got: "));
      Serial.println((char *)Lamp.lastread);
      int Lamp_State = atoi((char *)Lamp.lastread);
      digitalWrite(Relay2, Lamp_State);
    }
    if (subscription == &Fan) {
      Serial.print(F("Got: "));
      Serial.println((char *)Fan.lastread);
      int Fan_State = atoi((char *)Fan.lastread);
      digitalWrite(Relay3, Fan_State);
    }

  }

}

void MQTT_connect() {
  int8_t ret;

  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;

  while ((ret = mqtt.connect()) != 0) {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 2 seconds...");
    mqtt.disconnect();
    delay(2000);
    retries--;
    if (retries == 0) {
      while (1);
    }
  }
  Serial.println("MQTT Connected!");

}
