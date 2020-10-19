#include "padparadscha.h"

/**
 * Starts up and initialises the Serial ports for communications at a default baud rate
 * (See padparadscha_serial.h for the default baud rate)
 *
 */
Padparadscha::Padparadscha() {
    localSerial = new PadparadschaSerial(); 
}

/**
 * Starts up and initialises the Serial ports for communications with a given baud rate.
 * If value is not a valid baud-rate, then the default baud-rate is set.
 * (See padparadscha_serial.h for the default baud rate)
 *
 * @param baud_rate int The baud-rate/Serial speed to communicate at
 */
Padparadscha::Padparadscha(int baud_rate) {
    localSerial = new PadparadschaSerial(baud_rate);
}

/**
 * Sends a given String message to the Serial Channel
 *
 * @param message   String  The message to send
 */
void Padparadscha::sendDataSerial(const String& message) {
    localSerial->sendMessage(message);
}

class PadparadschaSerial* Padparadscha::getLocalSerial() {
    return localSerial;
}

