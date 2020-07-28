/**
 * 'Rhodonite' External Sensors Library
 * 
 * This library will handle the external conditions, using data retrieved from the following external sensors: 
 * GPS, Inertial Measurement Unit (IMU), Barometer and Servo Controller. 
 */
#ifndef RHODONITE_EXTERNAL_SENSORS
#define RHODONITE_EXTERNAL_SENSORS

#include "lars_main.h"

class Rhodonite{
public: 
    Rhodonite(); 
    float air_pressure; 
    float time;
    float longitude;
    float latitude;
    float altitude; 
private:
}

#endif