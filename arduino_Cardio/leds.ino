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
