#include "rhodonite.h"

Rhodonite::Rhodonite(Padparadscha& comms) {
    error = new DiagnosticHandler(comms, classname);
}

float Rhodonite::getAirPressure() {
    return air_pressure;
}

float Rhodonite::getTime() {
    return time;
}

float Rhodonite::getLongitude(){
    return longitude;
}

float Rhodonite::getLatitude(){
    return latitude;
}

float Rhodonite::getAltitude(){
    return altitude;
}

float Rhodonite::getAcceleration() {
    return acceleration;
}

void Rhodonite::setAirPressure(float a) {
    air_pressure = a;
}

void Rhodonite::setTime(float t) {
    time = t;
}

void Rhodonite::setLongitude(float l){
    longitude = l;
}

void Rhodonite::setLatitude(float l){
    latitude = l;
}

void Rhodonite::setAltitude(float a){
    altitude = a;
}

void Rhodonite::setAcceleration(float a){
    acceleration = a;
}
