#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>


//количество кнопок и диодов
const int BTN_COUNT = 20;
//Пины с группами прерываний
const int ISR_1 = 2;
const int ISR_2 = 3;

//пины кнопок
int btn[BTN_COUNT]; // Присвоить номера пинов!!!!
//массив с состояниями диодов
int ledState[BTN_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Присвоить номера!!!!
//массив с масками (какие должы быть состояния кнопок во время игры)
boolean mask[BTN_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//счёт первого и второго игрока
int timers[BTN_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ;
int timer = 0;
boolean flagInterrupt = false;
boolean flag = false;

int score1 = 0;
int score2 = 0;

byte gameMode = 0;


const int pinCS = 10; // ПИН CS для матрицы
const int numberOfHorizontalDisplays = 4; //количество горизонтальных матриц
const int numberOfVerticalDisplays = 1; //количество вертикальных матриц
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays); // объект матрица


//счётчик
unsigned long currentTime = 0;

/*===========================================================================================================*/
void setup() {
  //выбираем режим работы для пинов диодов и кнопок
  for (int i = 0; i < BTN_COUNT; i++) {
    pinMode(btn[i], INPUT);
    //pinMode(led[i], OUTPUT);
  }
  //последоательный порт для отладки
  Serial.begin(9600);


  //выбор яркости матрицы
  matrix.setIntensity(7);
  //поворот матриц
  matrix.setRotation(0, 1);
  matrix.setRotation(1, 1);
  matrix.setRotation(2, 1);
  matrix.setRotation(3, 1);

}

/*===========================================================================================================*/
void loop() {
  switch (gameMode) {
    case 1: {
        wallie();
      }
    case 2: {
        cowboy();
      }
    case 3: {
        turnItOff();
      }
  }
}

/*===========================================================================================================*/
/* Функция лоха
*/
void loser() {
Serial.println("Losser");
}
/*===========================================================================================================*/
/*
   Функция изменения состояния светодиода
   number - номер светодиода
   state - состояние HIGH или LOW
   Функция должна изменять массив состояний светодиодов и загружать этот массив в регистр
*/
void changeLedState(byte number, boolean state) {
  // TODO: ДОПИСАТЬ!!!
  ledState[number] = state;

}
/*===========================================================================================================*/
void changeAllLedState(boolean state) {
  // TODO: ДОПИСАТЬ!!!
  for (int i = 0; i < BTN_COUNT; i++) {

  }
}
/*===========================================================================================================*/
/* Функция победы в раунде
*/
void winRound() {

}
/*===========================================================================================================*/
int Random(int a, int b) {
  randomSeed(analogRead(A5));
  return random(a, b);
}
/*===========================================================================================================*/
/*
   Обнуляет все переменные используемые в играх
   НЕ ОБНУЛЯЕТ индекс игры
   Записывает в currentTime текущее время

*/
void reset() {
  for (int i = 0; i < BTN_COUNT; i++) {
    mask[i] = 0;
    timers[i] = 0;
  }
  changeAllLedState(LOW);
  timer = 0;
  flagInterrupt = false;
  flag = false;
  score1 = 0;
  score2 = 0;
  currentTime = millis();
}
