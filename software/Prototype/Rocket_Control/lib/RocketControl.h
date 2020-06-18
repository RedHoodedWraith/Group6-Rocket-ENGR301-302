//
// Created by Rowan Rathod on 18/06/20.
//

#ifndef ROCKET_CONTROL_ROCKETCONTROL_H
#define ROCKET_CONTROL_ROCKETCONTROL_H

#include <cmath>

class RocketControl{
public:
    RocketControl(float target, float errorLimit);
    float getAdjustment(float current, float changeRate);

private:
    float target;
    float error = 0;
    float errorLimit;
    void calculateError(float current);
};

#endif //ROCKET_CONTROL_ROCKETCONTROL_H
