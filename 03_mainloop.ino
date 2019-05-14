void loop() {

  Serial.print("inProgress: ");
  Serial.print(inProgress);
  Serial.print("        ");
  Serial.print("gameInProgress: ");
  Serial.println(gameInProgress);

  senValueOne = analogRead(sensorOne);
  senValueTwo = analogRead(sensorTwo);
  senValueThree = analogRead(sensorThree);
  senValueFour = analogRead(sensorFour);

  unsigned long currentMillis = millis();


  menuSelect();
  lcdDisplay();

  while (inProgress == true) {



    switch (menuOption) {

      case 1:
        break;

      case 2:
        gameRandom();
        break;

    }
  }



}
