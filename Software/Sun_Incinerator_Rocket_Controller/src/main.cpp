#include "lars_main.h"

Padparadscha comms;

void setup() {
    comms.begin();
}

void loop() {
  comms.sendDataSerial("Hello World!");
  delay(1000);
}