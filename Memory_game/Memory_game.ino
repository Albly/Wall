const byte BTN_COUNT = 20; // amount of button using in game
const byte LED_COUNT = 3; // amount the pins for controll buttons leds by remove register

byte latchPin = 33; //ST_CP
byte clockPin = 34; //SH_CP
byte dataPin = 35; //DS

byte btnPins[BTN_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 22, 23, 24, 25, 26, 27, 28, 29}; // arduino pins
//0, 1, 2, 3, 4, 5, 6
byte ledPins[LED_COUNT] = {30, 31, 32}; //arduino pins
byte buttonBank1[BTN_COUNT] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
byte buttonBank2[BTN_COUNT] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
byte flag = 0; // number of preset buttons

unsigned long currentTime = 0; // all work time

void setup()
{
  Serial.begin(9600);
  for (byte i = 0; i < BTN_COUNT; i++) //initialize arduino pins
  {
    pinMode(btnPins[i], INPUT); //with arduino`s resistor
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
//=====================================================================================
void loop()
{
  generateButton();  //generate true random values for both gamers 
  indicate();
  waitForPressed();

}
//======================================================================================
void generateButton()
{
  Serial.println("Start for generate");
  if (flag > 9)
    flag = 0;
  randomSeed(analogRead(A0));
  byte a = random(0, ((BTN_COUNT / 2) - 1));
  buttonBank1[flag] = a;

  randomSeed(analogRead(A0));
  byte b = random(9, BTN_COUNT);
  buttonBank2[flag] = b;

  flag++;
  Serial.print("Set of buttons:");
  Serial.println(flag);
  generateCodRegister();
}
//=========================================================================================
void generateCodRegister()
{
  
}
//=========================================================================================
void indicate()
{
  digitalWrite(latchPin, LOW);
  
}
//=========================================================================================
void waitForPressed()
{
  Serial.println("Waiting for pressing");
  for(currentTime = millis(); millis()-currentTime <1500;)
  {
    
  }
}
