// Working use me
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include "EEPROMAnything.h"

int threshold = 50;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int randNumber;
const int redOne = 13;
const int greenOne = 12;
const int sensorOne = A0;
int senValueOne = 0;
int targetStateOne = 0;

long targetStartTime;
long targetEndTime;

const int redTwo = 11;
const int greenTwo = 10;
const int sensorTwo = A1;
int senValueTwo = 0;
int targetStateTwo = 0;

const int redThree = 9;
const int greenThree = 8;
const int sensorThree = A2;
int senValueThree = 0;
int targetStateThree = 0;

const int redFour = 7;
const int greenFour = 6;
const int sensorFour = A3;
int senValueFour = 0;
int targetStateFour = 0;

const int startButton = 5;
const int swPin = 4;

unsigned long debounceDelay = 500;

unsigned long lastDebounceTime = millis();
boolean gameStart = false;

unsigned long gameStartTime;



boolean targetOn = false;

int highRandom;
int scoreRandom;
int targetScore = 0;

unsigned long timeRemaining;
unsigned long oldTimeRemaining = timeRemaining;

void setup() {
  //EEPROM_writeAnything(0, 0);
  lcd.init(); // Initalize Lcd
  lcd.backlight(); // Enable backlight

  //lcdDisplay(); // Load once to start screen
  pinMode(redOne, OUTPUT);
  pinMode(greenOne, OUTPUT);
  pinMode(redTwo, OUTPUT);
  pinMode(greenTwo, OUTPUT);

  pinMode(redThree, OUTPUT);
  pinMode(greenThree, OUTPUT);

  pinMode(redFour, OUTPUT);
  pinMode(greenFour, OUTPUT);

  //EEPROM_writeAnything(0, 0); //Reset Epprom Value
  Serial.begin(9600);
  pinMode(startButton, INPUT);
  digitalWrite(startButton, HIGH);

  highRandom =  EEPROM_readAnything(0, highRandom);
  //Serial.println(EEPROM_readAnything(0, highRandom));
  EEPROM_readAnything(0, highRandom);
  // Serial.print("Loaded highRandom is now: ");
  //Serial.println(highRandom);

  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("Score: ");
  lcd.setCursor(7, 0);
  lcd.print("    ");
  lcd.setCursor(7, 0);
  lcd.print(scoreRandom);

  lcd.setCursor(0, 1);
  lcd.print("High Score: ");
  lcd.print(highRandom);
  lcd.setCursor(14, 0);
  lcd.print("  ");
  lcd.setCursor(14, 0);
  lcd.print(timeRemaining);

  // Serial.println("-=-=-=-= Setup Complete =-=-=-=-");
}

void loop() {

  senValueOne = analogRead(sensorOne);
  senValueTwo = analogRead(sensorTwo);
  senValueThree = analogRead(sensorThree);
  senValueFour = analogRead(sensorFour);
  //Serial.print(digitalRead(swPin));
  //Serial.print("              ");
  //Serial.println(digitalRead(startButton));


  if (digitalRead(startButton) == HIGH && (millis() - lastDebounceTime) > debounceDelay) {
    //Serial.println("Start Click");
    targetScore = 0;
    scoreRandom = 0;
    gameStart = true;
    gameStartTime = millis();
    targetStartTime = millis();
    lastDebounceTime = millis();
  }




  if (gameStart == true && millis() - gameStartTime < 30000) {

    timeRemaining = (30000 - (millis() - gameStartTime)) / 1000;

    if (targetStateOne == 0 && targetStateTwo == 0 && targetStateThree == 0 && targetStateFour == 0) {
      randNumber = random(1, 5);
      targetStartTime = millis();

      // Serial.print("Random Target #: ");
      // Serial.println(randNumber);
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

      targetScore = 10 - ((targetEndTime - targetStartTime) / 1000);
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

      /* Serial.print("Last Target Score: ");
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
        } */
    }



    lcd.setCursor(0, 0);
    lcd.print("Score: ");
    lcd.setCursor(7, 0);
    lcd.print("    ");
    lcd.setCursor(7, 0);
    lcd.print(scoreRandom);

    lcd.setCursor(0, 1);
    lcd.print("High Score: ");
    lcd.print(highRandom);
    lcd.setCursor(14, 0);
    lcd.print("  ");
    lcd.setCursor(14, 0);
    lcd.print(timeRemaining);


    if (scoreRandom > highRandom) {
      EEPROM_writeAnything(0, scoreRandom);
      highRandom = scoreRandom;
    }



    Serial.print(targetScore);
    Serial.print(",");
    Serial.print(scoreRandom);
    Serial.print(",");
    Serial.print(timeRemaining);
    Serial.print(",");
    Serial.print(highRandom);
    Serial.print(",");
    Serial.println("99");
  }

}
