//
// Created by Rowan Rathod on 18/06/20.
//

#ifndef ROCKET_CONTROL_ROCKETCONTROL_H
#define ROCKET_CONTROL_ROCKETCONTROL_H

#include <cmath>

class RocketControl{
public:
    RocketControl(float target);
    RocketControl(float target, float errorLimit);
    void calculateError(float current);

private:
    float target;
    float error = 0;
    float errorLimit;
};

#endif //ROCKET_CONTROL_ROCKETCONTROL_H
