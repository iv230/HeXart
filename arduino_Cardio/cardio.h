// Set up pins for infra-red leds

#ifndef ARDUINO_CARDIO_CARDIO_H
#define ARDUINO_CARDIO_CARDIO_H

#define IR_TR 2 
#define IR_RX 3

int simulatePulseInputInit();
int simulatePulseInputLoop(int pulseAverage);

#endif
