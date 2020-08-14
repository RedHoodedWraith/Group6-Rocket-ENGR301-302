#include "rutile.h"

void Rutile::setAngle(float a) {
    if ((a > 359.00) || (a < 0.00)){
        //perror("Invalid angle value");
    }
    angle = a;
}

float Rutile::getAngle(){
    return angle;
}

