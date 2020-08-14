/**
 * 'Padparadscha' Communications Library
 *
 * This library handles LoRa communications to the Mission Control station and encodes and decodes data for transmission.
 */
#ifndef PADPARADSCHA
#define PADPARADSCHA

#include "fluoride_dependencies.h"

#define DEFAULT_BAUD_RATE 9600

class Padparadscha{
public:
    Padparadscha();
    bool begin(int baud_rate);
    bool begin();
    bool sendData();
    void sendDataSerial(String message);
private:
    String encodeData(String input);
    String decodeData(String input);
};

#endif