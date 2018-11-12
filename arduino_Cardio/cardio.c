#include "cardio.h"

int simulatePulseInputInit() {
    int pulseAvergage = random(60, 120);
    return pulseAvergage;
}

int simulatePulseInputLoop(int pulseAverage) {
    int variation = random(-10, 10);
    return pulseAverage + variation;
}
