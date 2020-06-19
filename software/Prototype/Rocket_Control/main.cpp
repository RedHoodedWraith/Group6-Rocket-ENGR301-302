#include "RocketControl.h"
#include <stdio.h>
#include <string>

float target = -0;
float changeBound = 10;

float restrictChange(float c){
    changeBound = abs(changeBound);

    if(c > changeBound){
        return changeBound;
    }

    if(c < -changeBound){
        return -changeBound;
    }

    return c;
}

int main() {
    RocketControl c(target, 1, 1, 0);

    float dir = 23.5;
    float wdir = dir;
    for(int i=0; i<1000; i++){
        printf("Iteration: %d\n", i);
        wdir++;
        dir += restrictChange(c.getAdjustment(dir));
        printf("With PID: %.2f\t\tWithout PID: %.2f\n\n", dir, wdir);
    }

    std::string s = (dir == target) ? "Target Reached" : "Failed to Reach Target";
    printf("%s\nFinal Value: %.2f\t\tIntended Target: %.2f\n", s.c_str(), dir, target);

    return 0;
}
