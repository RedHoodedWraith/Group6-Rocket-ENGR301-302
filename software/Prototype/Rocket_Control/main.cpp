#include "RocketControl.h"
#include <stdio.h>
#include <string>

float target = 134;
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
    RocketControl c(target, 1, 1, 0.1);

    float dir = 0;
    float wdir = dir;
    for(int i=0; i<200; i++){
        printf("Iteration: %d\n", i);
        dir++;
        wdir++;
        dir += restrictChange(c.getAdjustment(dir));
        printf("With PID: %.2f\t\tWithout PID: %.2f\n\n", dir, wdir);
    }

    std::string s = (dir == target) ? "Target Reached" : "Failed to Reach Target";
    printf("%s\nFinal Value: %.2f\t\tIntended Target: %.2f\n", s.c_str(), dir, target);

    return 0;
}
