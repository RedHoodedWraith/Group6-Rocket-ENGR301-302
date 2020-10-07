//
// Created by Rowan Rathod on 14/08/20.
//

#ifndef PADPARADSCHA_SERIAL_H
#define PADPARADSCHA_SERIAL_H

#include <Arduino.h>

#define DEFAULT_BAUD_RATE 9600

class PadparadschaSerial {
public:
    PadparadschaSerial(int baud_rate);
    PadparadschaSerial();
    void sendMessage(const String& message);
};


#endif
