#include "cardio.h"

int pulseAverage = 0;
int mode;
int current = 2;
int choice = 2;

void setup() {
  Serial.begin(9600);
  pulseAverage = simulatePulseInputInit();
//  for (int i = 1; i < 10; i++) {
//    pinMode(i, OUTPUT);
//    digitalWrite(i, HIGH);
//    delay(100);
//    digitalWrite(i, LOW);
//  }
//  Serial.println("Entrez le mode :");
//  while (Serial.available() == 0) {}
//  mode = Serial.parseInt();
//
//  Serial.flush();
//  if (mode == 5) {
//    Serial.println("Choose a LED");
//    while (Serial.available() == 0) {}
//    choice = Serial.parseInt();
//  }
  mode = 2;
}

void loop() {
  int simulatedPulse = simulatePulseInputLoop(pulseAverage);
  unsigned long leftTime = millis();

  Serial.println(leftTime);
  Serial.println(simulatedPulse);

  switch (mode) {
    case 1:
      blinkOnRythm();
      break;
    case 2:
      oneOfTwo();
      break;
    case 3:
      oneOfThree();
      break;
    case 4:
      chain(current);
      current++;
      if (current == 10) {
        current = 2;
      }
      break;
    case 5:
      unique(choice);
  }
  delay(600);
}
