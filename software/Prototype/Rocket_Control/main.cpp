#include "RocketControl.h"
#include <stdio.h>

int main() {
    RocketControl c(200, 1, 0.7, 0.1);

    int dir = 100;
    int wdir = dir;
    for(int i=0; i<300; i++){
        dir++;
        wdir++;
        dir += c.getAdjustment(dir);
        printf("With PID: %d\t\tWithout PID: %d\n\n", dir, wdir);
    }

    return 0;
}
