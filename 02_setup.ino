void setup() {
  Serial.begin(9600);

  //Load highscores from EEPROM:
  //=================================
  EEPROM_writeAnything(0, 0); //Reset Epprom Value (location, value)
  highRandom =  EEPROM_readAnything(0, highRandom);
  //Serial.println(EEPROM_readAnything(0, highRandom));
  EEPROM_readAnything(0, highRandom);
  Serial.print("Found highscore of random target with vaue of: ");
  Serial.println(highRandom);
  

  // Setup of targets
  //=================================
  pinMode(redOne, OUTPUT);
  pinMode(greenOne, OUTPUT);

  pinMode(redTwo, OUTPUT);
  pinMode(greenTwo, OUTPUT);

  pinMode(redThree, OUTPUT);
  pinMode(greenThree, OUTPUT);

  pinMode(redFour, OUTPUT);
  pinMode(greenFour, OUTPUT);

  // Setup of Rotory Encoder and misc buttons.
  //=================================

  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);

  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);

  pinMode(startButton, INPUT);
  digitalWrite(startButton, HIGH);

  //LCD Setup
  //=================================
  lcd.init(); // Initalize Lcd
  lcd.backlight(); // Enable backlight

  lcdDisplay(); // Load once to start screen


  Serial.println("-=-=-=[ Setup Complete! ]=-=-=-");
  delay(1000); //Allow everything to get ready. Needed?

  gameInProgress = true;
  gameStartTime = millis();
}


