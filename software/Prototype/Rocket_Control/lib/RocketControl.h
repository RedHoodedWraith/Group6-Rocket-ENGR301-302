//
// Created by Rowan Rathod on 18/06/20.
//

#ifndef ROCKET_CONTROL_ROCKETCONTROL_H
#define ROCKET_CONTROL_ROCKETCONTROL_H

#include <cmath>

class RocketControl{
public:
    RocketControl(float target, float proportional);

    float getAdjustment(float current);

private:
    float target;
    float error = 0;
    float errorLimit;
    float kP = 0;
    float kI = 0;
    float kD = 0;

    void updateError(float current);
};

#endif //ROCKET_CONTROL_ROCKETCONTROL_H
