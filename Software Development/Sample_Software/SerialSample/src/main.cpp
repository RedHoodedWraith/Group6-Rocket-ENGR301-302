#include <Arduino.h>

const int status_led = 13;

int i = 0;
String sentenceTemplate = "Hello World. Iteration ";
String sentence;

int getLightState(){
  return (i%2 == 0) ? HIGH : LOW;
}

void setup() {
  pinMode(status_led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sentence = sentenceTemplate + i++;
  digitalWrite(status_led, getLightState());
  Serial.println(sentence);
  delay(1000);
}