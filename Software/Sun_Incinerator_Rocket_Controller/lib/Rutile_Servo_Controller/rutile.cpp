#include "rutile.h"

Rutile::Rutile(PadparadschaSerial* comms) {
    angle = START_ANGLE;
    error = new DiagnosticHandler(comms, classname);
}

void Rutile::setAngle(float a) {
    if ((a > 359.00) || (a < 0.00)){
        reportInvalidValueError(a);
    } else {
        angle = a;
    }
}

float Rutile::getAngle(){
    return angle;
}

void Rutile::reportInvalidValueError(float val) {
    error->report_error("Invalid Angle Value: " + String(val));
}

