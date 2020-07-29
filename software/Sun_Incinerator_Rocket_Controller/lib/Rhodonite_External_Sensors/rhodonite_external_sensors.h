/**
 * 'Rhodonite' External Sensors Library
 * 
 * This library will handle the external conditions, using data retrieved from the following external sensors: 
 * GPS, Inertial Measurement Unit (IMU) and Barometer. 
 */
#ifndef RHODONITE_EXTERNAL_SENSORS
#define RHODONITE_EXTERNAL_SENSORS

#include "lars_main.h"

class Rhodonite{
public: 
    Rhodonite(); 
    float getAirPressure() {
      return air_pressure;
    }
    float getTime() {
      return time;
    }
    float getLongitude(){
        return longitude;
    }
    float getLatitude(){
        return latitude;
    }
    float getAltitude(){
        return altitude;
    }

private:
    float air_pressure; 
    float time;
    float longitude;
    float latitude;
    float altitude; 

    void setAirPressure(float a) {
        air_pressure = a;
    }
    void setTime(float t) {
        time = t;
    }
    void setLongitude(float l){
        longitude = l;
    }
    void setLatitude(float l){
        latitude = l;
    }
    void setAltitude(float a){
        altitude = a;
    }
}

#endif