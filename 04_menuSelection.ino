void menuSelect() {
  int buttonReading = digitalRead(clkPin);


  while (inProgress == false || gameInProgress == false) {

    int change = getEncoderTurn();
    menuOption = menuOption + change;

    /* Limit Encoder from changin the option beyond what is avaiable */
    if (menuOption > 2) {
      menuOption = 1;
    } else if (menuOption < 1) {
      menuOption = 2;
    }
    /* Update the screen if the option changes.*/
    if (menuOption != oldmenuOption) {
      //Serial.println(menuOption);
      lcdDisplay();
      oldmenuOption = menuOption;
    }



  }






  if (digitalRead(swPin) == LOW && (millis() - lastDebounceTime) > debounceDelay) {

    if (gameInProgress == false) {
      gameInProgress = true;
    } else if (gameInProgress == true) {
      gameInProgress = false;
    } else if (gameInProgress == false && inProgress == true) {
      inProgress = false;
    }

 lastDebounceTime = millis();
  }


  if (inProgress == true && gameInProgress == false && digitalRead(startButton) == LOW && (millis() - lastDebounceTime) > debounceDelay) {

    if (menuOption == 1) {
      lcd.clear();


    } else if (menuOption == 2) {
      scoreRandom = 0;
      targetStateOne = 0;
      targetStateTwo = 0;
      targetStateThree = 0;
      targetStateFour = 0;
      gameStartTime = millis();
      gameInProgress == true;

    }



  } else if (gameInProgress == true && digitalRead(startButton) == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("Start button was pushed while game was in progress. Ending game.");
    gameInProgress = false;
    lastDebounceTime = millis();
  }


}


/*Determine Rotary Position */
int getEncoderTurn(void) {
  static int oldA = HIGH; //set the oldA as HIGH
  static int oldB = HIGH; //set the oldB as HIGH
  int result = 0;
  int newA = digitalRead(clkPin);//read the value of clkPin to newA
  int newB = digitalRead(dtPin);//read the value of dtPin to newB
  if (newA != oldA || newB != oldB) //if the value of clkPin or the dtPin has changed
  {
    // something has changed
    if (oldA == HIGH && newA == LOW)
    {
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}

