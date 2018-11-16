void blinkOnRythm()
{
  int state = HIGH;

  for (int i = 0; i < 2; i++)
  {
    for (int j = 2; j < 10; j++)
    {
      digitalWrite(j, state);
    }

    delay(200);
    state = LOW;
  }

  /*for (int i = 2; i < 10; i++) {
    digitalWrite(i, HIGH);
    }
    delay(200);
    for (int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
    }*/
}

void oneOfTwo()
{
  bool first = true;

  for (int i = 0; i < 2; i++)
  {
    for (int j = 2; j < 10; j += 2)
    {
      digitalWrite(j, first ? HIGH : LOW); // Condition ternaire: booléen vrai ? alors : sinon;
      digitalWrite(j + 1, first ? LOW : HIGH);
    }
    delay(200);
    first = false;
  }

  /* for (int i = 2; i < 10; i += 2) {
    digitalWrite(i, HIGH);
    digitalWrite(i + 1, LOW);
    }
    delay(200);
    for (int i = 2; i < 10; i += 2) {
    digitalWrite(i, LOW);
    digitalWrite(i + 1, HIGH);
    } */
}

//1 LED on 2 is turned on alternativly
void oneOfThree() {
/*
  for(int i = 0; i < 3; i++)
  {
    for (int i = 2; i < 9; i += 3) {
    digitalWrite(i, HIGH);
    digitalWrite(i + 1, LOW);
    digitalWrite(i + 2, LOW);
  }
  }
  */
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

//1 LED is parcouring all the heart
void chain(int current) {
  if (current == 2) {
    digitalWrite(9, LOW);
  } else {
    digitalWrite(current - 1, LOW);
  }
  digitalWrite(current, HIGH);
}

//only 1 LED choosen by the user is blinking
void unique(int choice) {
  digitalWrite(choice, HIGH);
  delay(200);
  digitalWrite(choice, LOW);
}

//random LED is blinking (changes at each pulse)
void randFunc() {
  int led = random(2, 9);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
}

//LEDs are blinking symmetrically
void symmetry() {
  while (digitalRead(3) == HIGH || digitalRead(4) == HIGH || digitalRead(5) == HIGH || digitalRead(7) == HIGH || digitalRead(8) == HIGH || digitalRead(9) == HIGH) {
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
    delay(200);
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(6, LOW);
  }
}
