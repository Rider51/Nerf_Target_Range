void lcdDisplay() {

  if (inProgress == false) {

    /*lcd.setCursor(0, 0);
      lcd.print("Gamemode:");
    */

    if (menuOption != oldmenuOption) {

      switch (menuOption) {
        case 1:
          Serial.println("Gamemode: Free Play");
          lcd.setCursor(0, 0);
          lcd.print("                ");
          lcd.setCursor(0, 0);
          lcd.print("Free Play");
          break;

        case 2:
          Serial.println("Gamemode: Random Target");
          lcd.setCursor(0, 0);
          lcd.print("                ");
          lcd.setCursor(0, 0);
          lcd.print("Random Target");
          break;
      }
    }

  } else if (inProgress == true && gameInProgress == false) {

    switch (menuOption) {
      case 1:// FreePlay
        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(timeRemaining);

        if (gameInProgress == false) {
          lcd.setCursor(0, 0);
          lcd.print("Last Score: ");
          lcd.print(scoreFreeplay);

          lcd.setCursor(0, 1);
          lcd.print("High Score: ");
          lcd.print(scoreRandom);

        case 2:// Random
          lcd.setCursor(0, 0);
          lcd.print("Score: ");
          lcd.print(scoreRandom);

          lcd.setCursor(0, 1);
          lcd.print("High Score: ");
          lcd.print(highRandom);
          }

          break;





        }






    }




  }


