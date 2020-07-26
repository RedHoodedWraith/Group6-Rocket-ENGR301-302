#include <Arduino.h>

bool on = false;
const int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  if(on){
    digitalWrite(led, HIGH);
    on = false;
  } else{
    digitalWrite(led, LOW);
    on = true;
  }

  delay(1000);
}