//Google Assistant Home Automation
#include <ESP8266WiFi.h>π
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <Adafruit_Sensor.h>


// pin connected to DH22 data line


#define Relay1 D0
#define Relay2 D1
#define Relay3 D2
#define Relay4 D3
#define Relay5 D4
#define Relay6 D5
#define Relay7 D6
#define Relay8 D7


//WLAN Details
#define WLAN_SSID "PROLINK_PRS1140_3CA59" // Your SSID
#define WLAN_PASS "thealphaguardian1234" // Your password

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER "io.adafruit.com" //Adafruit Server
#define AIO_SERVERPORT 1883
#define AIO_USERNAME "Amres" // Username
#define AIO_KEY "17d759ac6e9b4e5a8e94031e544d21ed" // Auth Key


//WIFI CLIENT
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Light = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME"/feeds/Relay1"); // Feeds name should be same everywhere
Adafruit_MQTT_Subscribe Fan = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay2");
Adafruit_MQTT_Subscribe PlugOne = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay3");
Adafruit_MQTT_Subscribe PlugTwo = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay4");
Adafruit_MQTT_Subscribe LivingRoomLight = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME"/feeds/Relay5");
Adafruit_MQTT_Subscribe LivingRoomPlugOne = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay6");
Adafruit_MQTT_Subscribe LivingRoomPlugTwo = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay7");
Adafruit_MQTT_Subscribe LivingRoomPlugThree = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay8");

void MQTT_connect();

void setup() {


  Serial.begin(115200);


  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  pinMode(Relay6, OUTPUT);
  pinMode(Relay7, OUTPUT);
  pinMode(Relay8, OUTPUT);


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
  mqtt.subscribe(&Fan);
  mqtt.subscribe(&PlugOne);
  mqtt.subscribe(&PlugTwo);
  mqtt.subscribe(&LivingRoomLight);
  mqtt.subscribe(&LivingRoomPlugOne);
  mqtt.subscribe(&LivingRoomPlugTwo);
  mqtt.subscribe(&LivingRoomPlugThree);

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
    if (subscription == &Fan) {
      Serial.print(F("Got: "));
      Serial.println((char *)Fan.lastread);
      int Fan_State = atoi((char *)Fan.lastread);
      digitalWrite(Relay2, Fan_State);
    }
    if (subscription == &PlugOne) {
      Serial.print(F("Got: "));
      Serial.println((char *)PlugOne.lastread);
      int PlugOne_State = atoi((char *)PlugOne.lastread);
      digitalWrite(Relay3, PlugOne_State);
    }
    if (subscription == &PlugTwo) {
      Serial.print(F("Got: "));
      Serial.println((char *)PlugTwo.lastread);
      int PlugTwo_State = atoi((char *)PlugTwo.lastread);
      digitalWrite(Relay4, PlugTwo_State);
    }
    if (subscription == &LivingRoomLight) {
      Serial.print(F("Got: "));
      Serial.println((char *)LivingRoomLight.lastread);
      int LivingRoomLight_State = atoi((char *)LivingRoomLight.lastread);
      digitalWrite(Relay5, LivingRoomLight_State);
    }
    if (subscription == &LivingRoomPlugOne) {
      Serial.print(F("Got: "));
      Serial.println((char *)LivingRoomPlugOne.lastread);
      int LivingRoomPlugOne_State = atoi((char *)LivingRoomPlugOne.lastread);
      digitalWrite(Relay6, LivingRoomPlugOne_State);
    }
    if (subscription == &LivingRoomPlugTwo) {
      Serial.print(F("Got: "));
      Serial.println((char *)LivingRoomPlugTwo.lastread);
      int LivingRoomPlugTwo_State = atoi((char *)PlugOne.lastread);
      digitalWrite(Relay7, LivingRoomPlugTwo_State);
    }
    if (subscription == &LivingRoomPlugThree) {
      Serial.print(F("Got: "));
      Serial.println((char *)LivingRoomPlugThree.lastread);
      int LivingRoomPlugThree_State = atoi((char *)LivingRoomPlugThree.lastread);
      digitalWrite(Relay8, LivingRoomPlugThree_State);
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
