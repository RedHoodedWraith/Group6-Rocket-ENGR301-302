//
// Created by Rowan Rathod on 18/06/20.
//

#include "RocketControl.h"
#include <cstdio>

/**
 * Constructor: Constructs the Rocket PID Controller
 *
 * @param target    float   the target amount the "current" value should ideally be
 * @param proportional  float   the proportional constant amount to adjust
 * @param integral  float   the integral gain value
 * @param derivative    float
 * @param errorLimit    float   the minimum/maximum error value allowed
 */
RocketControl::RocketControl(float target, float changeBound, float kP, float kI, float kD) {
    RocketControl::target = target;
    RocketControl::changeBound = changeBound;
    RocketControl::kP = kP;
    RocketControl::kI = kI;
    RocketControl::kD = kD;
}

/**
 * Calculates the error value based on difference between the current value of the system
 * and the target value. This also applies the integral component to the controller.
 *
 * @param current   float   the current value of the system
 */
void RocketControl::updateError(float current) {
    float oldError = error;
    error = current - target;
    derivative = error - oldError;
}

void RocketControl::updateIntegral() {
    integral = ((integral + error) > maxFloat ? maxFloat : ((integral + error) < minFloat ? minFloat : integral + error));
}

/**
 * Returns the amount to change the current value by.
 *
 * @param current   float   the current value of the system
 * @return  the calculated
 */
float RocketControl::getAdjustment(float current){
    updateError(current);
    updateIntegral();

    float p = (kP * error);
    float i = (kI * integral);
    float d = (kD * derivative);
    printf("Error: %.2f\t\tIntegral: %.2f\t\tDerivative: %.2f\n", p, i, d);
    return -(p + i + d);
}

/**
 * Ensures the calculated adjustment value is within the set bounds
 *
 * @param c float   The calculated raw adjustment value by the PID algorithm
 * @return  c if float is between min and max float values, max float value if c is above it, min float value if c is below it
 */
float RocketControl::restrictChange(float c){
    changeBound = abs(changeBound);

    if(c > changeBound){
        return changeBound;
    }

    if(c < -changeBound){
        return -changeBound;
    }

    return c;
}

/**
 * Calculates the PID adjustment value and restricts it to be between the set bounds
 *
 * @param current   float   The current value of the system
 * @return  The calculated value to adjust the system by
 */
float RocketControl::getBoundedAdjustment(float current){
    return restrictChange(getAdjustment(current));
}