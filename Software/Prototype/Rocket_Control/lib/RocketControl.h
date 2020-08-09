//
// Created by Rowan Rathod on 18/06/20.
//

#ifndef ROCKET_CONTROL_ROCKETCONTROL_H
#define ROCKET_CONTROL_ROCKETCONTROL_H

#include <cmath>
#include <limits>

class RocketControl{
public:
    RocketControl(float target, float changeBound, float kP, float kI, float kD);
    float getAdjustment(float current);
    float getBoundedAdjustment(float current);

private:
    float maxFloat = std::numeric_limits<float>::max();
    float minFloat = std::numeric_limits<float>::min();
    float target;
    float kP, kI, kD;
    float error = 0;
    float integral = 0;
    float derivative = 0;
    float changeBound;

    float restrictChange(float c);
    void updateError(float current);
    void updateIntegral();
};

#endif //ROCKET_CONTROL_ROCKETCONTROL_H
