#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Servo.h>

const char *ssid = "mywifi";
const char *pw = "qwerty123";
IPAddress ip(192, 168, 0, 1);
IPAddress netmask(255, 255, 255, 0);
const int port = 9876;
int chVal_dev;

//
Servo str;

int pos = 0;

int enLR = D7;

int inR1 = D0;
int inR2 = D1;
int inL1 = D2;
int inL2 = D3;
//

int chVal[] = {0, 1225};

int usMin = 400;
int usMax = 2000;


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

void forward()
{
  digitalWrite(inR1, HIGH);
  digitalWrite(inR2, LOW);
  analogWrite(enLR, chVal[0]);
  digitalWrite(inL1, HIGH);
  digitalWrite(inL2, LOW);
  analogWrite(enLR, chVal[0]);
  Serial.println("forward");
}
void none()
{
  digitalWrite(inR1, LOW);
  digitalWrite(inR2, LOW);
  analogWrite(enLR, 0);
  digitalWrite(inL1, LOW);
  digitalWrite(inL2, LOW);
  analogWrite(enLR, 0);
}

void streeing() {
  str.write(chVal_dev);
}

void exeCmd() {

  lastCmdTime = millis();

  //slider

  if ( cmdStartsWith("ch") ) {
    int ch = cmd[2] - '0';
    if (ch >= 0 && ch <= 9 && cmd[3] == ' ') {
      chVal[ch] = (int)atof(cmd + 4);
    }
  }

  // accelerometer:

  if ( cmdStartsWith("ca") ) {
    int ch = cmd[2] - '0';
    if (ch >= 0 && ch <= 9 && cmd[3] == ' ') {
      chVal[ch] = (usMax + usMin) / 2 + (int)( atof(cmd + 4) * 51 ); // 9.8*51 = 500 => 1000 .. 2000
      chVal_dev = (int(chVal[1]) / 10);
      Serial.print("chval = ");
      Serial.print(chVal[0]);
      Serial.print(",");
      Serial.println(chVal_dev);
    }
  }
}

void setup() {

  delay(1000);

  cmdIndex = 0;

  Serial.begin(115200);

  str.attach(D6);
  pinMode(enLR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  str.write(137);

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
      forward();
      streeing();
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
