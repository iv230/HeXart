// fonction éclairage en rythme avec le pouls 
void blinkOnRythm()
{
  int state = HIGH;

  //faire deux fois boucle
  for (int i = 0; i < 2; i++)
  {
    // j = 2 car première LED branchée à pin 2
    // j<10 car dernière LED branchée sur pin 9
    for (int j = 2; j < 10; j++)
    {
      digitalWrite(j, state);
    }

    delay(LED_BLINK_TIME);
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

// fonction éclairage une sur deux
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
    delay(LED_BLINK_TIME);
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

//1 LED sur 2 allumée
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
  delay(LED_BLINK_TIME);
  for (int i = 2; i < 9; i += 3) {
    digitalWrite(i, LOW);
    digitalWrite(i + 1, HIGH);
    digitalWrite(i + 2, LOW);
  }
  delay(LED_BLINK_TIME);
  for (int i = 2; i < 9; i += 3) {
    digitalWrite(i, LOW);
    digitalWrite(i + 1, LOW);
    digitalWrite(i + 2, HIGH);
  }
}

//1 LED parcourt tout le coeur
void chain(int current) {
  // si LED allumée est sur pin 2, LED pin 9 éteinte
  if (current == 2) {
    digitalWrite(9, LOW);
  }
  //LED précédente éteinte quand LED suivante allumée
  else {
    digitalWrite(current - 1, LOW);
  }
  digitalWrite(current, HIGH);
}

//une LED choisie par l'utilisateur
void unique(int choice) {
  digitalWrite(choice, HIGH);
  delay(LED_BLINK_TIME);
  digitalWrite(choice, LOW);
}

//1 LED random(change à chaque battement)
void randFunc() {
  int led = random(2, 9);
  digitalWrite(led, HIGH);
  delay(LED_BLINK_TIME);
  digitalWrite(led, LOW);
}

//LEDs allumées symétriquement
void symmetry() {
  //tant que les LEDS autre que LED 2 ou 6 allumées faire :
  while (digitalRead(3) == HIGH || digitalRead(4) == HIGH || digitalRead(5) == HIGH || digitalRead(7) == HIGH || digitalRead(8) == HIGH || digitalRead(9) == HIGH) {
    digitalWrite(2, HIGH);
    delay(LED_BLINK_TIME);
    digitalWrite(2, LOW);
    for (int i = 3, j = 9; i<6, j>6; i++, j--) {
      digitalWrite(i, HIGH);
      digitalWrite(j, HIGH);
      delay(LED_BLINK_TIME);
      digitalWrite(i, LOW);
      digitalWrite(j, LOW);
    }
    delay(LED_BLINK_TIME);
    digitalWrite(6, HIGH);
    delay(LED_BLINK_TIME);
    digitalWrite(6, LOW);
  }
}
