#include "padparadscha.h"

Padparadscha::Padparadscha() {
    begin(DEFAULT_BAUD_RATE);
}

/**
 * Starts up and initialises the Serial ports for communications
 *
 * @param baud_rate int The baud-rate/Serial speed to communicate at
 * @return True if started
 */
bool Padparadscha::begin(int baud_rate) {
    if(baud_rate < 0){
        baud_rate = DEFAULT_BAUD_RATE;
    }
    Serial.begin(baud_rate);

    return true;
}

bool Padparadscha::begin() {
    return begin(DEFAULT_BAUD_RATE);
}

void Padparadscha::sendDataSerial(String message) {
    Serial.println(message);
}

