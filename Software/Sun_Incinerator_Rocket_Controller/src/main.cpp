#include "lars_main.h"

Padparadscha comms;

void setup() {

}

void loop() {
  comms.sendDataSerial("Hello World!");
  delay(1000);
}