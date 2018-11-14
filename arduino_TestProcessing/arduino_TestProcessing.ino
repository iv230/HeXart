#include "cardio.h"
#include "param.h"
#include "leds.h"

int choice = CHOICE;
int mode = MODE;

int pulseAverage = 0;
int current = 2;

void setup() {
  Serial.begin(9600);
  pulseAverage = simulatePulseInputInit();
  for (int i = 1; i < 10; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  
  /*Serial.println("Entrez le mode :");
  while (Serial.available() == 0) {}
  mode = Serial.parseInt();

  Serial.flush();
  if (mode == 5) {
    Serial.println("Choose a LED");
    while (Serial.available() == 0) {}
    choice = Serial.parseInt();
  }*/
  mode = 1;
}

void loop() {
  int simulatedPulse = simulatePulseInputLoop(pulseAverage);
  unsigned long leftTime = millis();

  String data = String("<" + String(leftTime) + "," + String(simulatedPulse) + ">");
  Serial.print(data);

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
