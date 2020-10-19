//
// Created by Rowan Rathod on 14/08/20.
//

#include "padparadscha_serial.h"


PadparadschaSerial::PadparadschaSerial() {
    Serial.begin(DEFAULT_BAUD_RATE);
}

PadparadschaSerial::PadparadschaSerial(int baud_rate) {
    if(baud_rate < 0){
        baud_rate = DEFAULT_BAUD_RATE;
    }
    Serial.begin(baud_rate);
}

void PadparadschaSerial::sendMessage(const String& message) {
    Serial.println(message);
}

