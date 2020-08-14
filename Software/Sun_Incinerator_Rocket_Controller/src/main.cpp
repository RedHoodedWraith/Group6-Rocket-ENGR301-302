#include "lars_main.h"

RocketController rocket;

void setup() {

}

void loop() {
  rocket.communicator->sendDataSerial("Hello World!");
  delay(1000);
}