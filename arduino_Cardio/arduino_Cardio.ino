#include "cardio.h"
#include "param.h"
#include "leds.h"

int choice = CHOICE;
int mode = MODE;

int pulseAverage = 0;
int current = 2;

unsigned long lastTimes[5];
int pulseComputeIndex = 0;

void setup() {
  Serial.begin(9600);
  pulseAverage = simulatePulseInputInit();
  for (int i = 1; i < 10; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  pinMode(0, OUTPUT);

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
  mode = 1;
}

void loop() {
  int dataPulse = analogRead(0);
  unsigned long leftTime = millis();
  unsigned long pulse = 0;

  if (dataPulse != 0) {
    if (pulseComputeIndex < 5) {
      lastTimes[pulseComputeIndex] = leftTime;
      //Serial.println("[DEBUG] Set lastTimes[" + String(pulseComputeIndex) + "] to " + String(leftTime));
      pulseComputeIndex++;
    }
    else {
      // Compute the pulse
      unsigned long periods[4];
      for (int i = 0; i < 4; i++) {
        periods[i] = lastTimes[i + 1] - lastTimes[i];
        //Serial.println("[DEBUG] lastTime : " + String(lastTimes[i+1]) + " - " + String(lastTimes[i]));
      }

      unsigned long timeAverage = 0;
      for (int i = 0; i < 4; i++) {
        timeAverage += periods[i];
        //Serial.println("[DEBUG] periods[i] : " + String(periods[i]));
      }
      timeAverage = (unsigned long) timeAverage / 4;
      //Serial.println("[DEBUG] timeAvergage : " + String(timeAverage));

      pulse = (unsigned long) 6000 / timeAverage;
      //Serial.println("[DEBUG] pulse : " + String(pulse));
      //Serial.println("[DEBUG] -------------------------");

      // Print data
      String data = String(String(leftTime) + ";" + String(pulse) + "_");
      Serial.print(data);

      // Clear tab
      pulseComputeIndex = 0;
    }

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
        break;
      case 6:
        randFunc();
        break;
      case 7:
        symmetry();
    }
    while (analogRead(0) > 0) {}
  }
}
