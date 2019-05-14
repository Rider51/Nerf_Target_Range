void gameRandom() {

if (gameInProgress == true && millis() - gameStartTime < 30000) {

    timeRemaining = (30000 - (millis() - gameStartTime)) / 1000;

    if (targetStateOne == 0 && targetStateTwo == 0 && targetStateThree == 0 && targetStateFour == 0) {
      randNumber = random(1, 5);
      targetStartTime = millis();

      Serial.print("Random Target #: ");
      Serial.println(randNumber);
      switch (randNumber) {
        default:

          digitalWrite(redOne, LOW);
          digitalWrite(greenOne, LOW);

          digitalWrite(redTwo, LOW);
          digitalWrite(greenTwo, LOW);

          break;
        case 1:
          digitalWrite(redOne, HIGH);
          targetStateOne = 1;
          targetStartTime = millis();

          break;
        case 2:
          digitalWrite(redTwo, HIGH);
          targetStateTwo = 1;
          targetStartTime = millis();
          break;
        case 3:
          digitalWrite(redThree, HIGH);
          targetStateThree = 1;
          targetStartTime = millis();
          break;
        case 4:
          digitalWrite(redFour, HIGH);
          targetStateFour = 1;
          targetStartTime = millis();
          break;
      }

    }

    if (targetStateOne == 1 && senValueOne >= threshold) {
      targetStateOne = 0;
      targetEndTime = millis();

      targetScore = 10. - ((targetEndTime - targetStartTime) / 1000);
      //Serial.println(((targetEndTime - targetStartTime) / 1000.));
      if (targetScore < 1) {
        targetScore = 1;
      }
      scoreRandom = scoreRandom + targetScore;

      //Code to score here ^^

      digitalWrite(redOne, LOW);
      digitalWrite(greenOne, HIGH);
      delay(50);
      digitalWrite(greenOne, LOW);
      delay(50);
      digitalWrite(greenOne, HIGH);
      delay(50);
      digitalWrite(greenOne, LOW);
      delay(50);
    } else if (targetStateTwo == 1 && senValueTwo >= threshold) {
      targetStateTwo = 0;
      targetEndTime = millis();

      targetScore = 10. - ((targetEndTime - targetStartTime) / 1000);
      //Serial.println(((targetEndTime - targetStartTime) / 1000.));
      if (targetScore < 1) {
        targetScore = 1;
      }
      scoreRandom = scoreRandom + targetScore;

      digitalWrite(redTwo, LOW);
      digitalWrite(greenTwo, HIGH);
      delay(50);
      digitalWrite(greenTwo, LOW);
      delay(50);
      digitalWrite(greenTwo, HIGH);
      delay(50);
      digitalWrite(greenTwo, LOW);

    } else if (targetStateThree == 1 && senValueThree >= threshold) {
      targetStateThree = 0;
      targetEndTime = millis();

      targetScore = 10. - ((targetEndTime - targetStartTime) / 1000);
      //Serial.println(((targetEndTime - targetStartTime) / 1000.));
      if (targetScore < 1) {
        targetScore = 1;
      }
      scoreRandom = scoreRandom + targetScore;

      digitalWrite(redThree, LOW);
      digitalWrite(greenThree, HIGH);
      delay(50);
      digitalWrite(greenThree, LOW);
      delay(50);
      digitalWrite(greenThree, HIGH);
      delay(50);
      digitalWrite(greenThree, LOW);

    } else if (targetStateFour == 1 && senValueFour >= threshold) {
      targetStateFour = 0;
      targetEndTime = millis();

      targetScore = 10. - ((targetEndTime - targetStartTime) / 1000);
      //Serial.println(((targetEndTime - targetStartTime) / 1000.));
      if (targetScore < 1) {
        targetScore = 1;
      }
      scoreRandom = scoreRandom + targetScore;

      digitalWrite(redFour, LOW);
      digitalWrite(greenFour, HIGH);
      delay(50);
      digitalWrite(greenFour, LOW);
      delay(50);
      digitalWrite(greenFour, HIGH);
      delay(50);
      digitalWrite(greenFour, LOW);
    }


    if (timeRemaining != oldTimeRemaining) {

      Serial.print("Last Target Score: ");
      Serial.print(targetScore);
      Serial.print("          ");
      Serial.print("Game: ");
      Serial.print(scoreRandom);
      Serial.print("          ");
      Serial.print("Time Remaining: ");
      Serial.print(timeRemaining);
      Serial.print("          ");
      Serial.print("High Score: ");
      Serial.println(highRandom);
      oldTimeRemaining = timeRemaining;
    }
  }


          lcd.setCursor(0, 0);
          lcd.print("Score: ");
          lcd.print(scoreRandom);

          lcd.setCursor(0, 1);
          lcd.print("High Score: ");
          lcd.print(highRandom);
          lcd.setCursor(14, 0);
          lcd.print(timeRemaining);


  if (scoreRandom > highRandom) {
    EEPROM_writeAnything(0, scoreRandom);
    highRandom = scoreRandom;
  }

}
