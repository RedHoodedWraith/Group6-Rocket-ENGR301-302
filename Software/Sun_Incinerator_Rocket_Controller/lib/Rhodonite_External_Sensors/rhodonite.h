/**
 * 'Rhodonite' External Sensors Library
 * 
 * This library will handle the external conditions, using data retrieved from the following external sensors: 
 * GPS, Inertial Measurement Unit (IMU) and Barometer. 
 */
#ifndef RHODONITE_EXTERNAL_SENSORS
#define RHODONITE_EXTERNAL_SENSORS

#include "fluoride_dependencies.h"

class Rhodonite{
public: 
    Rhodonite(PadparadschaSerial& comms);
    float getAirPressure();
    float getTime();
    float getLongitude();
    float getLatitude();
    float getAltitude();
    float getAcceleration();
    void setAirPressure(float a);
    void setTime(float t);
    void setLongitude(float l);
    void setLatitude(float l);
    void setAltitude(float a);
    void setAcceleration(float a);

private:
    String classname = "Rhodonite";
    float air_pressure; 
    float time;
    float longitude;
    float latitude;
    float altitude; 
    float acceleration;
    class DiagnosticHandler* error;
};

#endif