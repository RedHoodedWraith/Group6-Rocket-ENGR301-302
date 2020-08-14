/**
 * 'Rutile' Servos Library
 * 
 * This library will handle the servos. 
 */

#ifndef RUTILE
#define RUTILE

#include "fluoride_dependencies.h"

#define START_ANGLE 0

class Rutile{
public:
    Rutile(Padparadscha& comms);
    float getAngle();

private:
    const String classname = "Rutile";
    float angle;
    DiagnosticHandler* error;

    void reportInvalidValueError(float val);
    void setAngle(float a);
};

#endif