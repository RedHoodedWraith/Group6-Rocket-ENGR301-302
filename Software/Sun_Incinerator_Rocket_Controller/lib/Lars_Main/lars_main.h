/**
 * 'Lars of the Stars' Main Header
 *
 * This header is to store final headers that are used in the main project.
 */

#ifndef LARS_ROCKET_CONTROLLER
#define LARS_ROCKET_CONTROLLER

#include "fluoride_dependencies.h"   // Handles Common Dependencies
#include "padparadscha.h"   // Handles Communications
#include "rhodonite.h"  // External Sensors
#include "rutile.h" // Servo Controls

class RocketController{
public:
    RocketController();
    class Padparadscha* communicator;
    class Rhodonite* sensors;
    class Rutile* servos;
    class SD_Handler* sdcard;

private:
    class PadparadschaSerial* serial_channel;
};

#endif
