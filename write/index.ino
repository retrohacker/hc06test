#include "SoftwareSerial.h"
#include <stdio.h>

SoftwareSerial hc06(11, 10); // TX/RX pins

uint8_t prev = 0;

void setup() {
  hc06.begin(9600);
}

void loop() {
  prev = prev + 1;
  hc06.write(prev);
}
