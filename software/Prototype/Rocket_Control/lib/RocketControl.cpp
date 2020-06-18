//
// Created by Rowan Rathod on 18/06/20.
//

#include "RocketControl.h"

/**
 * Constructor: Constructs the Rocket PID Controller
 *
 * @param target    float   the target amount the "current" value should ideally be
 * @param errorLimit    float   the minimum/maximum error value allowed (gets converted to positive)
 */
RocketControl::RocketControl(float target, float errorLimit) {
    RocketControl::target = target;
    RocketControl::errorLimit = abs(errorLimit);
}

/**
 * Proportional:
 * Calculates the error value based on difference between the current value of the system
 * and the target value.
 *
 * @param current   float   the current value of the system
 */
void RocketControl::calculateError(float current) {
    error = current - target;
}

/**
 * Derivative:
 * Returns the amount to change the current value by.
 *
 * @param current   float   the current value of the system
 * @param changeRate    float   the amount to change by
 * @return  the calculated
 */
float RocketControl::getAdjustment(float current, float changeRate){
    calculateError(current);
    
}