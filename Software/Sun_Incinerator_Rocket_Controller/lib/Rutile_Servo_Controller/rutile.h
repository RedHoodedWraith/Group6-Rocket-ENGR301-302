/**
 * 'Rutile' Servos Library
 * 
 * This library will handle the servos. 
 */

#ifndef RUTILE
#define RUTILE

#include "lars_main.h"

class Rutile{
public:
    Rutile();
    float getAngle (){
        return angle; 
    }

private:
    float angle;

    void setAngle(float a) {
        if ((a > 359.00) || (a < 0.00)){
            perror("Invalid angle value"); 
        }
        angle = a;
    }
};

#endif