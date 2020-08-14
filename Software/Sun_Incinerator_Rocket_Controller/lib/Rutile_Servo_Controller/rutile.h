/**
 * 'Rutile' Servos Library
 * 
 * This library will handle the servos. 
 */

#ifndef RUTILE
#define RUTILE

#include "fluoride_dependencies.h"

class Rutile{
public:
    Rutile();
    float getAngle();

private:
    float angle;
    void setAngle(float a);
};

#endif