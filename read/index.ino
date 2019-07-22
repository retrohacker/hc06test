#include "SoftwareSerial.h"
#include <stdio.h>

SoftwareSerial hc06(11, 10); // TX/RX pins

uint8_t prev = 0;
unsigned long errors;
unsigned long start;

void setup() {
  hc06.begin(9600);
  start = millis();
}

void loop() {
  if(millis > 1000 * 60 * 60) {
    char buffer[1000];
    sprintf(buffer, "errors: %lu", errors);
    hc06.write(buffer);
    delay(1000 * 60);
    return;
  }

  if(Serial.available()) {
    uint8_t val = hc06.read();
    prev = prev + 1;
    if(prev != val) {
      errors = errors + 1;
      prev = val;
    }
  }
}
