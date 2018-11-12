#include "cardio.h"

int pulseAverage = 0;

void setup() {
  Serial.begin(9600);
  pulseAverage = simulatePulseInputInit();
}

void loop() {
  int simulatedPulse = simulatePulseInputLoop(pulseAverage);
  unsigned long leftTime = millis();
  Serial.print(leftTime);
  Serial.print(" - ");
  Serial.println(simulatedPulse);
}
