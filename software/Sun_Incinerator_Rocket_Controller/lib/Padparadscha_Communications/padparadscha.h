/**
 * 'Padparadscha' Communications Library
 *
 * This library handles LoRa communications to the Mission Control station and encodes and decodes data for transmission.
 */
#ifndef PADPARADSCHA
#define PADPARADSCHA

#include "lars_main.h"

class Padparadscha{
public:
    Padparadscha();
    bool sendData();
private:
    String encodeData(String input);
    String decodeData(String input);
};

#endif