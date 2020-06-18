//
// Created by Rowan Rathod on 18/06/20.
//

#include "RocketControl.h"

/**
 * Constructor: Constructs the Rocket PID Controller
 * @param target    float   the target amount the "current" value should ideally be
 * @param errorLimit    float   the minimum/maximum error value allowed (gets converted to positive)
 */
RocketControl::RocketControl(float target, float errorLimit) {
    RocketControl::target = target;
    RocketControl::errorLimit = abs(errorLimit);
}

void RocketControl::calculateError(float current) {
    error = target - current;

    // Ensures the error value remains between its bounds
    if(error > errorLimit){
        error = errorLimit;
    } else if(error < -errorLimit){
        error = -errorLimit;
    }
}


