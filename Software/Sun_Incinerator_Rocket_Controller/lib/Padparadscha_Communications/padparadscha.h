/**
 * 'Padparadscha' Communications Library
 *
 * This library handles LoRa communications to the Mission Control station and encodes and decodes data for transmission.
 */
#ifndef PADPARADSCHA
#define PADPARADSCHA

#include "fluoride_dependencies.h"

class Padparadscha{
public:
    Padparadscha();
    Padparadscha(int baud_rate);
    bool sendData();
    void sendDataSerial(const String& message);
    class PadparadschaSerial* getLocalSerial();
private:
    class PadparadschaSerial* localSerial;
    String encodeData(String input);
    String decodeData(String input);
};

#endif