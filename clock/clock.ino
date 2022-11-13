int n = 0;
int m = 0;
int h = 0;
int s = 0;
int g = 1000;
int l = 60000;
int k = 360000;

void setup() {

  Serial.begin(9600);

}

void loop() {
  while (1) {
    Serial.print(h);
    Serial.print(":");
    Serial.print(m);
    Serial.print(":");
    Serial.println(s);
    n = n + 1000;
    delay(1000);

    if (n == g) {
      s = s + 1;
      g = g + 1000;

      if (n == l) {
        s = 0;
        m = m + 1;
        l = l + 60000;

        if (n == k) {
          m = 0;
          h = h + 1;
          k = k + 3600000;

          if (n == 86400000) {
            h = 0;
            n = 0;
          }
        }
      }
    }
  }
}
