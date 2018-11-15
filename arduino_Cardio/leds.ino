void blinkOnRythm() {
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, HIGH);
  }
  delay(200);
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
  }
}

void oneOfTwo() {
  for (int i = 2; i < 10; i += 2) {
    digitalWrite(i, HIGH);
    digitalWrite(i + 1, LOW);
  }
  delay(200);
  for (int i = 2; i < 10; i += 2) {
    digitalWrite(i, LOW);
    digitalWrite(i + 1, HIGH);
  }
}

void oneOfThree() {
  for (int i = 2; i < 9; i += 3) {
    digitalWrite(i, HIGH);
    digitalWrite(i + 1, LOW);
    digitalWrite(i + 2, LOW);
  }
  delay(200);
  for (int i = 2; i < 9; i += 3) {
    digitalWrite(i, LOW);
    digitalWrite(i + 1, HIGH);
    digitalWrite(i + 2, LOW);
  }
  delay(200);
  for (int i = 2; i < 9; i += 3) {
    digitalWrite(i, LOW);
    digitalWrite(i + 1, LOW);
    digitalWrite(i + 2, HIGH);
  }
}

void chain(int current) {
  if (current == 2) {
    digitalWrite(9, LOW);
  } else {
    digitalWrite(current - 1, LOW);
  }
  digitalWrite(current, HIGH);
}

void unique(int choice) {
  digitalWrite(choice, HIGH);
  delay(200);
  digitalWrite(choice, LOW);
}

void randFunc() {
  int led;
  led = random(2, 9);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
}

void AlexisFunc() {
  while (digitalRead(3) ==HIGH || digitalRead(4) ==HIGH || digitalRead(5) ==HIGH || digitalRead(7) ==HIGH || digitalRead(8) ==HIGH || digitalRead(9) ==HIGH) {
    digitalWrite(2, HIGH);
    delay(200);
    digitalWrite(2, LOW)
    for (int i = 3, int j = 9; i<6, j>6; i++, j--) {
      digitalWrite(i, HIGH);
      digitalWrite(j, HIGH);
      delay(200)
      digitalWrite(i, LOW);
      digitalWrite(j, LOW);
    }
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(6, LOW);
  }
}
