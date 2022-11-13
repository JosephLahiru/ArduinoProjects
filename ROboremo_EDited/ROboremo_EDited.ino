#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char *ssid = "mywifi";
const char *pw = "qwerty123";
IPAddress ip(192, 168, 0, 1);
IPAddress netmask(255, 255, 255, 0);
const int port = 9876;

//
//motor driver details
//

int chVal[] = {150, 1500}; 

int usMin = 700;
int usMax = 2300;


WiFiServer server(port);
WiFiClient client;


char cmd[100];
int cmdIndex;
unsigned long lastCmdTime = 60000;
unsigned long aliveSentTime = 0;


boolean cmdStartsWith(const char *st) {
  for (int i = 0; ; i++) {
    if (st[i] == 0) return true;
    if (cmd[i] == 0) return false;
    if (cmd[i] != st[i]) return false;;
  }
  return false;
}

void none() {

}

void exeCmd() {

  lastCmdTime = millis();

  //slider

  if ( cmdStartsWith("ch") ) {
    int ch = cmd[2] - '0';
    if (ch >= 0 && ch <= 9 && cmd[3] == ' ') {
      chVal[ch] = (int)atof(cmd + 4);
      Serial.print("chval = ");
      Serial.print(chVal[0]);
      Serial.print(",");
      Serial.println(chVal[1]);
    }
  }

  // accelerometer:

  if ( cmdStartsWith("ca") ) {
    int ch = cmd[2] - '0';
    if (ch >= 0 && ch <= 9 && cmd[3] == ' ') {
      chVal[ch] = (usMax + usMin) / 2 + (int)( atof(cmd + 4) * 51 ); // 9.8*51 = 500 => 1000 .. 2000
      Serial.print("chval = ");
      Serial.print(chVal[0]);
      Serial.print(",");
      Serial.println(chVal[1]);
    }
  }
}

void setup() {

  delay(1000);

  cmdIndex = 0;

  Serial.begin(115200);

  WiFi.softAPConfig(ip, ip, netmask);
  WiFi.softAP(ssid, pw);

  server.begin();

  Serial.println((String)"SSID: " + ssid + "  PASS: " + pw);
  Serial.println((String)"RoboRemo app must connect to " + ip.toString() + ":" + port);

}


void loop() {

  if (millis() - lastCmdTime > 500) {
    none();
  }

  if (!client.connected()) {
    client = server.available();
    return;
  }

  if (client.available()) {
    char c = (char)client.read();

    if (c == '\n') {
      cmd[cmdIndex] = 0;
      exeCmd();
      cmdIndex = 0;
    } else {
      cmd[cmdIndex] = c;
      if (cmdIndex < 99) cmdIndex++;
    }
  }

  if (millis() - aliveSentTime > 500) {
    client.write("alive 1\n");

    aliveSentTime = millis();
  }
}
