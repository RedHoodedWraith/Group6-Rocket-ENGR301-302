#include "RocketControl.h"
#include <stdio.h>
#include <string>

float target = 4.5569;
float changeBound = 10;

/**
 * Checks if two float values are equal. Takes into account -0 and assigns it as 0.
 *
 * @param val1  float   The first value to compare
 * @param val2  float   The second value to compare
 * @return True if both values are equal (including -0 and 0 being equal)
 */
bool equals(float val1, float val2){
    val1 = (val1 == -0 ? 0 : val1);
    val2 = (val2 == -0 ? 0 : val2);

    return val1 == val2;
}

int main() {
    RocketControl c(target, changeBound, 1, 1, 0);

    float dir = 125;
    float wdir = dir;
    for(int i=0; i<1000; i++){
        printf("Iteration: %d\n", i);
        wdir++;
        dir += c.getBoundedAdjustment(dir);
        printf("With PID: %.2f\t\tWithout PID: %.2f\n\n", dir, wdir);
    }

    std::string s = (dir == target) ? "Target Reached" : "Failed to Reach Target";
    printf("%s\nFinal Value: %.2f\t\tIntended Target: %.2f\n", s.c_str(), dir, target);

    return 0;
}
