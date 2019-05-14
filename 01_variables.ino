#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include "EEPROMAnything.h"

// Variables for Points, and high scores.
//============================================
int highFreeplay = 0; // Highscore for freeplay mode
int highRandom = 0; // Highscore for random target mode

int targetScore; // Temporary variable for storing score of a single target

int scoreFreeplay = 0; // Current/last game's score for Freeplay
int scoreRandom = 0; // Current/last game's score for random target

// Target Led and Sensor Variables:
//============================================
const int redOne = 13;
const int greenOne = 12;
const int sensorOne = A0;
int senValueOne = 0;
int targetStateOne = 0;

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


// Menu variables:
//============================================
int gameMode = 0;
int randNumber = 0;
int menuOption = 1;
int oldmenuOption = 0;

// Game Status Variables:
//============================================
boolean inProgress = false; //Is a game selected
boolean gameInProgress = false; //Is a game actually running
boolean targetOn = false; //Is a target activated

//boolean gameStart = false; //Has the game started

// Time variables:
//============================================
unsigned long timeRemaining; // How much time is remaining in a game
unsigned long oldTimeRemaining = timeRemaining;

unsigned long scoreTimeLeft; //?

unsigned long gameStartTime; // Time the game started, used for calcuating when it will end

unsigned long targetStartTime; //When the target was activated
unsigned long targetEndTime; // When the target was hit/deactivated

unsigned long currentTime; // May be used in place of millis()
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 500;

const long interval = 1000;
unsigned long previousMillis = 0;





// Rotory Encoder:
//============================================
const int clkPin = 2; //the clk attach to pin 2
const int dtPin = 3; //the dt pin attach to pin 3
const int swPin = 4; //the sw pin attach to pin 4

// Other, Misc:
//============================================
const int startButton = 6; // start button attached to pin 6

const int threshold = 50; // Target sensitivity threshold. Lower number is more sensitive.

LiquidCrystal_I2C lcd(0x27, 16, 2);

