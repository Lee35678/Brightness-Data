#include <Arduino.h>

int val = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  val = analogRead(15);
  Serial.println(val);
  delay(500);
}
